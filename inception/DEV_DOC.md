# Developer Documentation

## Prerequisites

- Linux virtual machine with Docker Engine and Docker Compose plugin installed
- Rootful Docker, or a host configured to allow binding privileged port `443` when using rootless Docker
- A user account named `sabe` or an updated `HOST_LOGIN` value inside the local `srcs/.env`
- Permission to create `/home/sabe/data`
- DNS or `/etc/hosts` mapping for `sabe.42.fr`

## Setup From Scratch

1. Copy `srcs/.env.example` to `srcs/.env`.
2. Replace the placeholder values in `srcs/.env` with the local login, domain, and email addresses.
3. Run `make`.
4. The Makefile creates `/home/sabe/data/mariadb` and `/home/sabe/data/wordpress`.
5. The Makefile also generates missing files inside `secrets/` and keeps them outside version control.

If you are using rootless Docker, the host may refuse the mandatory `443:443` port mapping. In that case, adjust the host configuration for privileged ports or run a rootful Docker daemon. The Compose file should stay on port `443`, because changing the public port would violate the subject.

## Build And Launch Flow

- `make`: runs `prepare`, then `docker compose up --build -d`
- `make build`: rebuilds the images without starting the stack
- `make down`: stops and removes the running containers
- `make re`: recreates the stack

The Compose file is `srcs/docker-compose.yml`. Keep a local `srcs/.env` file created from `srcs/.env.example`.

## Managing Containers And Volumes

- Show container status: `make ps`
- Stream logs: `make logs`
- Remove containers and volumes: `make clean`
- Remove containers, volumes, images, and `/home/sabe/data`: `make fclean`
- List Docker volumes: `docker volume ls`
- Inspect the project network: `docker network inspect inception`

## Connecting To MariaDB

The MariaDB service runs in the `mariadb` container. The database name and
application user are defined in `srcs/.env`, while the passwords are generated
locally under `secrets/`.

- Application password: `secrets/db_password.txt`
- Root password: `secrets/db_root_password.txt`

Open a shell inside the MariaDB container:

`docker exec -it mariadb sh`

Then connect as the application user:

`mysql -u"$MYSQL_USER" -p"$(cat /run/secrets/db_password)" "$MYSQL_DATABASE"`

Connect as root:

`mysql -uroot -p"$(cat /run/secrets/db_root_password)"`

To verify that root access without a password is rejected:

`mysql -uroot`

## Persistence Layout

Two named volumes are declared in Compose:

- `mariadb_data` mounted at `/var/lib/mysql`
- `wordpress_data` mounted at `/var/www/html`

Their host-side storage is configured under:

- `/home/sabe/data/mariadb`
- `/home/sabe/data/wordpress`

This ensures that rebuilding containers does not remove the database or WordPress files.

## Relevant Files

- `srcs/requirements/mariadb/tools/entrypoint.sh`: initializes the database and required user
- `srcs/requirements/wordpress/tools/entrypoint.sh`: prepares the build-bundled WordPress files and starts PHP-FPM
- `srcs/requirements/wordpress/tools/bootstrap.php`: performs the idempotent WordPress installation and user creation logic
- `srcs/requirements/nginx/tools/entrypoint.sh`: renders the NGINX config and creates the self-signed TLS certificate
