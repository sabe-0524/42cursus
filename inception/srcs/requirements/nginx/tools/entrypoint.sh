#!/bin/sh
set -eu

: "${DOMAIN_NAME:?DOMAIN_NAME is required}"

mkdir -p /etc/nginx/ssl

if [ ! -f /etc/nginx/ssl/inception.key ] || [ ! -f /etc/nginx/ssl/inception.crt ]; then
	openssl req -x509 -nodes -newkey rsa:2048 -sha256 -days 365 \
		-subj "/CN=${DOMAIN_NAME}" \
		-keyout /etc/nginx/ssl/inception.key \
		-out /etc/nginx/ssl/inception.crt
	chmod 600 /etc/nginx/ssl/inception.key
	chmod 644 /etc/nginx/ssl/inception.crt
fi

	envsubst '${DOMAIN_NAME}' < /etc/nginx/templates/default.conf.template > /etc/nginx/conf.d/default.conf

exec nginx -g 'daemon off;'

