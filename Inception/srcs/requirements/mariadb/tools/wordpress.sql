CREATE DATABASE wordpress;

CREATE USER 'ivloisy'@'%' IDENTIFIED BY 'ivloisy';
GRANT ALL PRIVILEGES ON wordpress.* TO 'ivloisy'@'%' IDENTIFIED BY 'ivloisy';
FLUSH PRIVILEGES;
ALTER USER 'root'@'localhost' IDENTIFIED BY 'root';
