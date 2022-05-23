#!/bin/sh

if [ -f /var/www/html/wordpress/wp-config.php ]

then
	echo "Wordpress already installed"

else
	wget https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar
	chmod +x wp-cli.phar
	mv wp-cli.phar /usr/local/bin/wp
	cd /var/www/html/wordpress
	wp core download --allow-root
	wp core config --dbname=$MYSQL_DATABASE --dbuser=$MYSQL_USER --dbpass=$MYSQL_PASSWORD --dbhost=mariadb --skip-check --extra-php --allow-root <<PHP
define( 'WP_DEBUG', true );
PHP
	sleep 10
	wp core install --url=$WP_URL --title=$WP_TITLE --admin_user=$MYSQL_USER --admin_email=$WP_MAIL --admin_password=$WP_PASSWORD --allow-root --path=/var/www/html/wordpress/

fi

/usr/sbin/php-fpm7.3 -F

exec "$@"
