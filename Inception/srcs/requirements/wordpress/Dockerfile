FROM debian:buster

RUN apt-get update -yq \
&& apt-get upgrade -y \
&& apt-get install php php7.3-fpm php-mysql -y
RUN apt-get install  wget -y

COPY ./conf/ivloisy.42.fr.conf /etc/php/7.3/fpm/pool.d
COPY ./tools/entrypoint.sh /usr/local/bin
COPY ./conf/wp-config.php /tmp

RUN mkdir -p /run/php && mkdir -p /var/log/php7.3-fpm

ENTRYPOINT ["sh", "/usr/local/bin/entrypoint.sh"]

EXPOSE 9000
