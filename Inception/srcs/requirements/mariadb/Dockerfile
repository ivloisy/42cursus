FROM debian:buster

RUN apt-get update -yq \
&& apt-get upgrade -y \
&& apt-get install mariadb-server mariadb-client -y

RUN mkdir -p /var/run/mysqld \
&& chown -R mysql:mysql /var/run/mysqld \
&& chown -R mysql:mysql /var/lib/mysql

RUN     rm -rf /etc/mysql/my.cnf

COPY ./tools/entrypoint.sh /tmp
COPY ./tools/wordpress.sql /tmp
COPY ./conf/my.cnf /etc/mysql

EXPOSE 3306

RUN chown -R mysql:mysql /tmp
RUN chown -R mysql:mysql /etc/mysql

USER mysql

ENTRYPOINT ["sh", "/tmp/entrypoint.sh"]
