COMPOSE_FILE := srcs/docker-compose.yml
ENV_FILE := srcs/.env
SECRETS_DIR := secrets
LOGIN := $(shell awk -F= '/^HOST_LOGIN=/{print $$2}' $(ENV_FILE))
DATA_DIR := /home/$(LOGIN)/data
COMPOSE := docker compose -f $(COMPOSE_FILE) --env-file $(ENV_FILE)

.PHONY: all up down build logs ps restart clean fclean re prepare

all: up

up: prepare
	$(COMPOSE) up --build -d

build: prepare
	$(COMPOSE) build

down:
	$(COMPOSE) down

logs:
	$(COMPOSE) logs -f

ps:
	$(COMPOSE) ps

restart:
	$(COMPOSE) restart

clean:
	$(COMPOSE) down --volumes --remove-orphans

fclean: clean
	docker image rm -f mariadb wordpress nginx 2>/dev/null || true
	rm -rf $(DATA_DIR)

re: down up

prepare:
	mkdir -p $(SECRETS_DIR) $(DATA_DIR)/mariadb $(DATA_DIR)/wordpress
	test -f $(SECRETS_DIR)/db_root_password.txt || openssl rand -hex 24 > $(SECRETS_DIR)/db_root_password.txt
	test -f $(SECRETS_DIR)/db_password.txt || openssl rand -hex 24 > $(SECRETS_DIR)/db_password.txt
	test -f $(SECRETS_DIR)/wp_admin_password.txt || openssl rand -hex 24 > $(SECRETS_DIR)/wp_admin_password.txt
	test -f $(SECRETS_DIR)/wp_user_password.txt || openssl rand -hex 24 > $(SECRETS_DIR)/wp_user_password.txt
	printf "Domain: %s\nDB name: %s\nDB user: %s\nWP admin user: %s\nWP user: %s\nAdmin password file: %s/wp_admin_password.txt\nUser password file: %s/wp_user_password.txt\nDB password file: %s/db_password.txt\nDB root password file: %s/db_root_password.txt\n" \
		"$$(awk -F= '/^DOMAIN_NAME=/{print $$2}' $(ENV_FILE))" \
		"$$(awk -F= '/^MYSQL_DATABASE=/{print $$2}' $(ENV_FILE))" \
		"$$(awk -F= '/^MYSQL_USER=/{print $$2}' $(ENV_FILE))" \
		"$$(awk -F= '/^WORDPRESS_ADMIN_USER=/{print $$2}' $(ENV_FILE))" \
		"$$(awk -F= '/^WORDPRESS_USER=/{print $$2}' $(ENV_FILE))" \
		"$(SECRETS_DIR)" \
		"$(SECRETS_DIR)" \
		"$(SECRETS_DIR)" \
		"$(SECRETS_DIR)" > $(SECRETS_DIR)/credentials.txt
	chmod 600 $(SECRETS_DIR)/*.txt
