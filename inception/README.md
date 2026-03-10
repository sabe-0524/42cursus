*This project has been created as part of the 42 curriculum by sabe.*

# Description

This repository implements the 42 Inception mandatory infrastructure with Docker Compose. The stack is intentionally small and explicit: `nginx` is the only public entrypoint, `wordpress` runs PHP-FPM and bootstraps the CMS automatically, and `mariadb` provides the database backend. Persistent data is stored in two Docker named volumes whose host-side storage is placed under `/home/sabe/data`.

The project exists to demonstrate service isolation, container networking, persistent storage, TLS termination, and reproducible local setup on a virtual machine. All service images are built from local Dockerfiles based on `debian:bookworm`, which is an explicit stable Debian release and avoids the forbidden `latest` tag.

## Project Sources

The repository contains:

- `srcs/docker-compose.yml`: the service topology, network, named volumes, and secrets wiring.
- `srcs/.env.example`: template for local non-secret environment values such as domain, usernames, and site metadata.
- `srcs/requirements/mariadb`: MariaDB image, configuration, and initialization entrypoint.
- `srcs/requirements/wordpress`: WordPress + PHP-FPM image with a build-time WordPress source bundle and a local PHP bootstrap.
- `srcs/requirements/nginx`: NGINX image, TLS bootstrap script, and reverse-proxy configuration.
- `Makefile`: the single entrypoint used to prepare secrets, create host directories, and start the stack.
- `secrets/README.md`: explanation of locally generated secret files that are kept out of git.

## Design Choices

- Debian Bookworm was chosen over Alpine to keep package names, PHP modules, and service tooling straightforward during defense and maintenance.
- WordPress installation is automated with a local PHP bootstrap so the site is reproducible without browser-side setup, while the WordPress core files are baked into the image at build time to avoid a first-boot network dependency.
- Sensitive values are generated into ignored files under `secrets/` and injected through Docker secrets, while the local `srcs/.env` keeps only non-secret configuration copied from `srcs/.env.example`.
- The two persistent storages are declared as Docker named volumes and use the local driver so their data lives under `/home/sabe/data`, matching the subject requirement.
- NGINX generates a local self-signed certificate on container start because the project targets a local VM domain and must expose HTTPS only.

## Instructions

1. Ensure `sabe.42.fr` resolves to the machine hosting Docker. On a local VM this usually means adding the VM IP to `/etc/hosts` on the client machine.
2. Copy `srcs/.env.example` to `srcs/.env`, then replace the placeholder values with the local login, domain, and email addresses.
3. Run `make` from the repository root. The Makefile creates host data directories and generates local secret files if they do not exist yet.
4. Open `https://sabe.42.fr` in a browser and accept the self-signed certificate warning.
5. Use `make logs` or `make ps` to inspect the stack.
6. Stop the project with `make down`.

## Comparisons

### Virtual Machines vs Docker

Virtual machines emulate an entire operating system with its own kernel, which is heavier but offers strong isolation. Docker containers share the host kernel and isolate processes at the namespace and cgroup level, which makes this project faster to build, easier to reset, and more aligned with modern deployment practices.

### Secrets vs Environment Variables

Environment variables are convenient for non-sensitive configuration that should be visible in Compose and shell tooling. Secrets are better for passwords because they are mounted as files at runtime, reduce accidental exposure in process listings, and keep credentials out of versioned configuration.

### Docker Network vs Host Network

An explicit Docker bridge network gives clear service discovery (`mariadb`, `wordpress`, `nginx`) and limits exposure to the containers that need to talk to each other. Host networking removes that boundary, couples services to the VM network stack, and is forbidden by the subject.

### Docker Volumes vs Bind Mounts

Docker volumes are managed storage objects with predictable lifecycle and better portability in Compose. Bind mounts directly expose arbitrary host paths and are easier to misuse. This project keeps the mandatory persistent storages as named volumes while steering their host-side storage into `/home/sabe/data`.

## Resources

- Docker Compose specification: https://docs.docker.com/compose/compose-file/
- Docker volumes: https://docs.docker.com/storage/volumes/
- Docker secrets in Compose: https://docs.docker.com/compose/how-tos/use-secrets/
- NGINX SSL module: https://nginx.org/en/docs/http/configuring_https_servers.html
- PHP-FPM documentation: https://www.php.net/manual/en/install.fpm.php
- MariaDB server documentation: https://mariadb.com/kb/en/documentation/

AI was used to accelerate subject analysis, generate an implementation checklist, and run a separate review loop against the written requirements. The final repository layout, container behavior, configuration choices, and validation steps were checked manually and iterated locally.
