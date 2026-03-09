FROM debian:bookworm

ARG DEBIAN_FRONTEND=noninteractive

RUN apt-get update \
	&& apt-get install -y --no-install-recommends mariadb-server ca-certificates \
	&& rm -rf /var/lib/apt/lists/*

COPY conf/50-server.cnf /etc/mysql/mariadb.conf.d/50-server.cnf
COPY tools/entrypoint.sh /usr/local/bin/mariadb-entrypoint.sh

RUN chmod 755 /usr/local/bin/mariadb-entrypoint.sh \
	&& mkdir -p /run/mysqld \
	&& chown -R mysql:mysql /run/mysqld

EXPOSE 3306

ENTRYPOINT ["/usr/local/bin/mariadb-entrypoint.sh"]
