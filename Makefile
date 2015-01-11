# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mpillet <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/01/05 10:14:39 by mpillet           #+#    #+#              #
#    Updated: 2015/01/11 11:02:15 by mpillet          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= ft_retro
CC			= g++
FLAGS		= -Wall -Werror -Wextra -pedantic
LIBS		= -L /usr/lib -lncurses
INC			= -I Game -I List -I Unit -I Player -I Level -I . -I IObject -I Enemy

SRC			=	main.cpp \
					Game/Game.accesors.cpp \
					Game/Game.constructors.cpp \
					Game/Game.methods.cpp \
					List/List.accesors.cpp \
					List/List.constructors.cpp \
					List/List.methods.cpp \
					Player/Player.accesors.cpp \
					Player/Player.constructors.cpp \
					Player/Player.methods.cpp \
					Unit/Unit.accesors.cpp \
					Unit/Unit.constructors.cpp \
					Unit/Unit.methods.cpp \
					Level/Level.constructors.cpp \
					Level/Level.methods.cpp \
					Level/Level.accesors.cpp \
					Enemy/Enemy.constructors.cpp \

DIR_OBJ		= .obj
DIR_LIST	= Game IObject List Unit Player Level Enemy

OBJ			= $(addprefix $(DIR_OBJ)/, $(SRC:.cpp=.o))

all: $(NAME)

$(addprefix $(DIR_OBJ)/, %.o): %.cpp **/*.hpp
	@printf "compiling \e[33m%-41s\e[0m" "$@..."
	@$(CC) $(FLAGS) $(INC) -o $@ -c $<
	@printf "\e[32m[✔]\e[0m\n"

$(NAME): $(DIR_OBJ) $(OBJ)
	@printf "\e[32m------------------------------------------------------\e[0m\n"
	@$(CC) $(FLAG) $(OBJ) $(LIBS) -o $(NAME)
	@printf "\e[34m%-51s\e[0m" "$@"
	@printf "\e[32m[✔]\e[0m\n"
	@printf "\e[32m------------------------------------------------------\e[0m\n"

$(DIR_OBJ) :
	@/bin/mkdir $(DIR_OBJ); \
		for DIR in $(DIR_LIST); \
		do \
		/bin/mkdir $(DIR_OBJ)/$$DIR; \
		done

clean:
	@/bin/rm -rf $(DIR_OBJ);
	@printf "\e[32m[✔]\e[0m Project cleaned.\n"

fclean: clean
	@/bin/rm -rf $(NAME);
	@printf "\e[32m[✔]\e[0m Project fcleaned.\n"

re: fclean all

.PHONY: clean fclean re
