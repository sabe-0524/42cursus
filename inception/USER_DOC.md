# User Documentation

## Provided Services

The stack provides three services:

- `nginx`: HTTPS entrypoint on port `443`.
- `wordpress`: the PHP-FPM application serving the WordPress site.
- `mariadb`: the database used by WordPress.

## Start And Stop

- Start everything: `make`
- Stop containers: `make down`
- View running services: `make ps`
- Follow logs: `make logs`

## Access The Website And Admin Panel

- Website: `https://sabe.42.fr`
- WordPress admin: `https://sabe.42.fr/wp-admin`

The TLS certificate is self-signed for local development, so the browser will display a warning the first time you connect.

## Credentials

Credentials are generated locally under `secrets/` the first time `make` runs.

- `secrets/wp_admin_password.txt`: WordPress administrator password
- `secrets/wp_user_password.txt`: regular WordPress user password
- `secrets/db_password.txt`: MariaDB application password
- `secrets/db_root_password.txt`: MariaDB root password
- `secrets/credentials.txt`: summary of usernames, domain, and the password file locations

Create `srcs/.env` by copying `srcs/.env.example`, then replace the placeholder values with the local login, domain, and email addresses.
Usernames and non-secret configuration values are stored in the local `srcs/.env`.

## Health Checks

You can verify the stack with the following commands:

- `make ps`: shows whether the containers are up
- `docker compose -f srcs/docker-compose.yml --env-file srcs/.env logs mariadb`
- `docker compose -f srcs/docker-compose.yml --env-file srcs/.env logs wordpress`
- `docker compose -f srcs/docker-compose.yml --env-file srcs/.env logs nginx`
- `curl -kI https://sabe.42.fr`

If the website is unavailable, check that `sabe.42.fr` resolves to the correct machine and that Docker is running.
