FROM debian:bookworm

ARG DEBIAN_FRONTEND=noninteractive

RUN apt-get update \
	&& apt-get install -y --no-install-recommends nginx openssl gettext-base ca-certificates \
	&& rm -rf /var/lib/apt/lists/* \
	&& rm -f /etc/nginx/sites-enabled/default

COPY conf/default.conf.template /etc/nginx/templates/default.conf.template
COPY tools/entrypoint.sh /usr/local/bin/nginx-entrypoint.sh

RUN chmod 755 /usr/local/bin/nginx-entrypoint.sh \
	&& mkdir -p /etc/nginx/ssl

EXPOSE 443

ENTRYPOINT ["/usr/local/bin/nginx-entrypoint.sh"]
