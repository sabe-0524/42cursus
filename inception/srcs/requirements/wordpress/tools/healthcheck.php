<?php
declare(strict_types=1);

$_SERVER['HTTP_HOST'] = (string) getenv('DOMAIN_NAME');
$_SERVER['SERVER_NAME'] = (string) getenv('DOMAIN_NAME');
$_SERVER['HTTPS'] = 'on';
$_SERVER['REQUEST_METHOD'] = 'GET';

define('WP_INSTALLING', true);

require_once '/var/www/html/wp-load.php';
require_once ABSPATH . 'wp-admin/includes/upgrade.php';

exit(is_blog_installed() ? 0 : 1);
