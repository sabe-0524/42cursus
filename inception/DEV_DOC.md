# Developer Documentation

## Prerequisites

- Linux virtual machine with Docker Engine and Docker Compose plugin installed
- Rootful Docker, or a host configured to allow binding privileged port `443` when using rootless Docker
- A user account named `sabe` or an updated `HOST_LOGIN` value inside `srcs/.env`
- Permission to create `/home/sabe/data`
- DNS or `/etc/hosts` mapping for `sabe.42.fr`

## Setup From Scratch

1. Review `srcs/.env` and update the non-secret values if needed.
2. Run `make`.
3. The Makefile creates `/home/sabe/data/mariadb` and `/home/sabe/data/wordpress`.
4. The Makefile also generates missing files inside `secrets/` and keeps them outside version control.

If you are using rootless Docker, the host may refuse the mandatory `443:443` port mapping. In that case, adjust the host configuration for privileged ports or run a rootful Docker daemon. The Compose file should stay on port `443`, because changing the public port would violate the subject.

## Build And Launch Flow

- `make`: runs `prepare`, then `docker compose up --build -d`
- `make build`: rebuilds the images without starting the stack
- `make down`: stops and removes the running containers
- `make re`: recreates the stack

The Compose file is `srcs/docker-compose.yml`, and the corresponding environment file is `srcs/.env`.

## Managing Containers And Volumes

- Show container status: `make ps`
- Stream logs: `make logs`
- Remove containers and volumes: `make clean`
- Remove containers, volumes, images, and `/home/sabe/data`: `make fclean`
- List Docker volumes: `docker volume ls`
- Inspect the project network: `docker network inspect inception`

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
