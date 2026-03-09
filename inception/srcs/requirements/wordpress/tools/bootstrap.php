<?php
declare(strict_types=1);

$required = [
    'DOMAIN_NAME',
    'WORDPRESS_TITLE',
    'WORDPRESS_ADMIN_USER',
    'WORDPRESS_ADMIN_EMAIL',
    'WORDPRESS_USER',
    'WORDPRESS_USER_EMAIL',
];

foreach ($required as $name) {
    if (getenv($name) === false || getenv($name) === '') {
        fwrite(STDERR, "Missing environment variable: {$name}\n");
        exit(1);
    }
}

$adminPassword = @file_get_contents('/run/secrets/wp_admin_password');
$userPassword = @file_get_contents('/run/secrets/wp_user_password');

if ($adminPassword === false || $userPassword === false) {
    fwrite(STDERR, "Missing WordPress password secret\n");
    exit(1);
}

$adminPassword = trim($adminPassword);
$userPassword = trim($userPassword);
$domainName = (string) getenv('DOMAIN_NAME');
$siteUrl = "https://{$domainName}";

$_SERVER['HTTP_HOST'] = $domainName;
$_SERVER['SERVER_NAME'] = $domainName;
$_SERVER['HTTPS'] = 'on';
$_SERVER['REQUEST_METHOD'] = 'GET';

define('WP_INSTALLING', true);

require_once '/var/www/html/wp-load.php';
require_once ABSPATH . 'wp-admin/includes/upgrade.php';
require_once ABSPATH . 'wp-admin/includes/user.php';
require_once ABSPATH . 'wp-includes/pluggable.php';

if (!is_blog_installed()) {
    wp_install(
        (string) getenv('WORDPRESS_TITLE'),
        (string) getenv('WORDPRESS_ADMIN_USER'),
        (string) getenv('WORDPRESS_ADMIN_EMAIL'),
        true,
        '',
        $adminPassword
    );
}

update_option('siteurl', $siteUrl);
update_option('home', $siteUrl);

$userLogin = (string) getenv('WORDPRESS_USER');
$userEmail = (string) getenv('WORDPRESS_USER_EMAIL');
$user = get_user_by('login', $userLogin);

if (!$user) {
    $userId = wp_create_user($userLogin, $userPassword, $userEmail);
    if (is_wp_error($userId)) {
        fwrite(STDERR, "Failed to create WordPress user: " . $userId->get_error_message() . "\n");
        exit(1);
    }
    $user = get_user_by('id', $userId);
}

if (!$user instanceof WP_User) {
    fwrite(STDERR, "Unable to load WordPress user: {$userLogin}\n");
    exit(1);
}

$user->set_role('author');
