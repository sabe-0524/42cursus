#!/bin/sh
set -eu

read_secret() {
	if [ ! -f "$1" ]; then
		echo "Missing secret file: $1" >&2
		exit 1
	fi
	tr -d '\r\n' < "$1"
}

MYSQL_PASSWORD="$(read_secret /run/secrets/db_password)"
WORDPRESS_ADMIN_PASSWORD="$(read_secret /run/secrets/wp_admin_password)"
WORDPRESS_USER_PASSWORD="$(read_secret /run/secrets/wp_user_password)"

generate_salt() {
	php -r 'echo bin2hex(random_bytes(32));'
}

mkdir -p /run/php /var/www/html

attempt=0
until mariadb -h"${WORDPRESS_DB_HOST}" -u"${MYSQL_USER}" -p"${MYSQL_PASSWORD}" -e "SELECT 1" >/dev/null 2>&1; do
	attempt=$((attempt + 1))
	if [ "$attempt" -ge 60 ]; then
		echo "MariaDB is not reachable from WordPress" >&2
		exit 1
	fi
	sleep 2
done

if [ ! -f /var/www/html/wp-load.php ]; then
	cp -a /usr/src/wordpress/. /var/www/html/
fi

if [ ! -f /var/www/html/wp-config.php ]; then
	cat <<-PHP > /var/www/html/wp-config.php
	<?php
	define('DB_NAME', '${MYSQL_DATABASE}');
	define('DB_USER', '${MYSQL_USER}');
	define('DB_PASSWORD', '${MYSQL_PASSWORD}');
	define('DB_HOST', '${WORDPRESS_DB_HOST}');
	define('DB_CHARSET', 'utf8');
	define('DB_COLLATE', '');

	define('AUTH_KEY',         '$(generate_salt)');
	define('SECURE_AUTH_KEY',  '$(generate_salt)');
	define('LOGGED_IN_KEY',    '$(generate_salt)');
	define('NONCE_KEY',        '$(generate_salt)');
	define('AUTH_SALT',        '$(generate_salt)');
	define('SECURE_AUTH_SALT', '$(generate_salt)');
	define('LOGGED_IN_SALT',   '$(generate_salt)');
	define('NONCE_SALT',       '$(generate_salt)');

	define('WP_HOME', 'https://${DOMAIN_NAME}');
	define('WP_SITEURL', 'https://${DOMAIN_NAME}');
	define('FS_METHOD', 'direct');

	if (isset(\$_SERVER['HTTP_X_FORWARDED_PROTO']) && \$_SERVER['HTTP_X_FORWARDED_PROTO'] === 'https') {
		\$_SERVER['HTTPS'] = 'on';
	}

	\$table_prefix = 'wp_';

	define('WP_DEBUG', false);

	if (! defined('ABSPATH')) {
		define('ABSPATH', __DIR__ . '/');
	}

	require_once ABSPATH . 'wp-settings.php';
	PHP
fi

chown -R www-data:www-data /var/www/html

php /usr/local/bin/bootstrap-wordpress.php

exec php-fpm8.2 -F
