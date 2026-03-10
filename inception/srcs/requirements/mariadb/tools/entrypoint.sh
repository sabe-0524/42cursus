#!/bin/sh
set -eu

read_secret() {
	if [ ! -f "$1" ]; then
		echo "Missing secret file: $1" >&2
		exit 1
	fi
	tr -d '\r\n' < "$1"
}

MYSQL_ROOT_PASSWORD="$(read_secret /run/secrets/db_root_password)"
MYSQL_PASSWORD="$(read_secret /run/secrets/db_password)"

mkdir -p /run/mysqld /var/lib/mysql
chown -R mysql:mysql /run/mysqld /var/lib/mysql

start_temp_server() {
	mysqld --user=mysql --skip-networking --socket=/run/mysqld/mysqld.sock &
	temp_pid="$!"

	attempt=0
	until mariadb-admin --socket=/run/mysqld/mysqld.sock ping >/dev/null 2>&1; do
		attempt=$((attempt + 1))
		if [ "$attempt" -ge 60 ]; then
			echo "MariaDB temporary server failed to start" >&2
			kill "$temp_pid"
			wait "$temp_pid" || true
			exit 1
		fi
		sleep 1
	done
}

stop_temp_server() {
	mariadb-admin --socket=/run/mysqld/mysqld.sock -uroot -p"${MYSQL_ROOT_PASSWORD}" shutdown
	wait "$temp_pid"
}

initialized=0
if [ ! -d /var/lib/mysql/mysql ]; then
	mariadb-install-db --user=mysql --datadir=/var/lib/mysql >/dev/null
	initialized=1
fi

start_temp_server

if [ "$initialized" -eq 1 ]; then
	mariadb --socket=/run/mysqld/mysqld.sock <<-SQL
		ALTER USER 'root'@'localhost' IDENTIFIED VIA mysql_native_password USING PASSWORD('${MYSQL_ROOT_PASSWORD}');
		DELETE FROM mysql.user WHERE User='';
		DROP DATABASE IF EXISTS test;
		DELETE FROM mysql.db WHERE Db='test' OR Db='test\\_%';
		FLUSH PRIVILEGES;
	SQL
else
	mariadb --socket=/run/mysqld/mysqld.sock -uroot -p"${MYSQL_ROOT_PASSWORD}" <<-SQL
		ALTER USER 'root'@'localhost' IDENTIFIED VIA mysql_native_password USING PASSWORD('${MYSQL_ROOT_PASSWORD}');
		FLUSH PRIVILEGES;
	SQL
fi

mariadb --socket=/run/mysqld/mysqld.sock -uroot -p"${MYSQL_ROOT_PASSWORD}" <<-SQL
	CREATE DATABASE IF NOT EXISTS ${MYSQL_DATABASE} CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci;
	CREATE USER IF NOT EXISTS '${MYSQL_USER}'@'%' IDENTIFIED BY '${MYSQL_PASSWORD}';
	ALTER USER '${MYSQL_USER}'@'%' IDENTIFIED BY '${MYSQL_PASSWORD}';
	GRANT ALL PRIVILEGES ON ${MYSQL_DATABASE}.* TO '${MYSQL_USER}'@'%';
	FLUSH PRIVILEGES;
SQL

stop_temp_server

exec mysqld --user=mysql --console
