FROM debian:buster

RUN apt-get update -yq \
&& apt-get upgrade -y \
&& apt-get install nginx openssl -y

RUN mkdir -p /etc/nginx/ssl && mkdir -p /run/nginx
RUN openssl req -newkey rsa:4096 -x509 -sha256 -days 365 -nodes -out /etc/nginx/ssl/ivloisy.42.fr.crt -keyout /etc/nginx/ssl/ivloisy.42.fr.key -subj "/C=FR/ST=IDF/L=Paris/O=42/OU=ivloisy/CN=ivloisy.42.fr"

COPY ./conf/ivloisy.42.fr /etc/nginx/sites-available
COPY ./conf/ivloisy.42.fr /etc/nginx/sites-enabled

CMD [ "nginx", "-g", "daemon off;" ]

EXPOSE 443
