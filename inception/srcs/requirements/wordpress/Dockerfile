FROM debian:bookworm

ARG DEBIAN_FRONTEND=noninteractive
ARG WORDPRESS_VERSION=6.9.1

RUN apt-get update \
	&& apt-get install -y --no-install-recommends \
		php8.2-fpm \
		php8.2-cli \
		php8.2-mysql \
		php8.2-curl \
		php8.2-gd \
		php8.2-mbstring \
		php8.2-xml \
		php8.2-zip \
		curl \
		mariadb-client \
		procps \
		ca-certificates \
	&& rm -rf /var/lib/apt/lists/*

RUN curl -fsSL "https://wordpress.org/wordpress-${WORDPRESS_VERSION}.tar.gz" -o /tmp/wordpress.tar.gz \
	&& curl -fsSL "https://wordpress.org/wordpress-${WORDPRESS_VERSION}.tar.gz.sha1" -o /tmp/wordpress.tar.gz.sha1 \
	&& echo "$(cat /tmp/wordpress.tar.gz.sha1)  /tmp/wordpress.tar.gz" | sha1sum -c - \
	&& mkdir -p /usr/src/wordpress \
	&& tar -xzf /tmp/wordpress.tar.gz --strip-components=1 -C /usr/src/wordpress \
	&& rm -f /tmp/wordpress.tar.gz /tmp/wordpress.tar.gz.sha1

COPY conf/www.conf /etc/php/8.2/fpm/pool.d/www.conf
COPY tools/bootstrap.php /usr/local/bin/bootstrap-wordpress.php
COPY tools/healthcheck.php /usr/local/bin/wordpress-healthcheck.php
COPY tools/entrypoint.sh /usr/local/bin/wordpress-entrypoint.sh

RUN chmod 755 /usr/local/bin/wordpress-entrypoint.sh \
	&& chmod 644 /usr/local/bin/bootstrap-wordpress.php \
	&& chmod 644 /usr/local/bin/wordpress-healthcheck.php \
	&& mkdir -p /run/php /var/www/html

EXPOSE 9000

ENTRYPOINT ["/usr/local/bin/wordpress-entrypoint.sh"]
