# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ivloisy <ivloisy@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/04 14:57:46 by ivloisy           #+#    #+#              #
#    Updated: 2022/04/05 18:02:22 by ivloisy          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

DATA=$(HOME)/data
YML=./srcs/docker-compose.yml

all: up

vol:
	mkdir -p $(DATA)
	mkdir -p $(DATA)/wordpress
	mkdir -p $(DATA)/mariadb

del:
	sudo rm -r $(DATA)

up: vol
	docker-compose -f $(YML) up -d --build

down:
	docker-compose -f $(YML) down

clean: down del
	docker system prune -f

fclean: clean
	docker system prune -af
	docker volume rm srcs_db_volume
	docker volume rm srcs_wp_volume

re: fclean all

.PHONY: all up down clean fclean re
