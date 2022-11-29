# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: llachgar <llachgar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/16 19:52:48 by saghrous            #+#    #+#            #
#    Updated: 2020/02/16 21:31:38 by llachgar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = rtv1

SRC_NAME = main.c \
			rtv1.c \
			objects.c \
			ray_inter.c \
			utils.c

OBJ_NAME =	$(SRC_NAME:.c=.o)

SRC_PATH =	source
OBJ_PATH =	objet

SRC = $(addprefix $(SRC_PATH)/, $(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH)/, $(OBJ_NAME))

CC = gcc -Wall -Wextra -Werror

LIB =  libft/libft.a \
	   source/parser/parser.a \
	   source/vector/vector.a \
	   miniLibX/libmlx.a -framework OpenGL -framework AppKit
	#    -lmlx -framework OpenGL -framework AppKit
		
DEPS = include/rtv1.h

INC = -Iinclude -Ilibft/inc -Isource/parser/inc -Isource/vector/inc

all : $(NAME)

$(NAME) : $(OBJ) lib_ft vec_ft par_ft
	@clear
	@echo "\033[1;34mCreating $(NAME)\033[0m"
	@$(CC) $(OBJ) $(LIB)  -o $@

lib_ft :
	@make -C libft

par_ft :
	@make -C source/parser

vec_ft :
	@make -C source/vector

$(OBJ_PATH)/%.o : $(SRC_PATH)/%.c $(DEPS)
	@clear
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	@$(CC) $(INC) -o $@ -c $< 
	@echo "Compiling \033[1;36m[$<]\033[0m to \033[1;32m[$@]\033[0m"

clean :
	@make clean -C libft
	@make clean -C source/parser
	@make clean -C source/vector
	@echo "\033[1;33mRemoving $(NAME)'s objects directory\033[0m"
	@rm -rf $(OBJ_PATH) 2> /dev/null

fclean : clean
	@make fclean -C libft
	@make fclean -C source/parser
	@make fclean -C source/vector
	@echo "\033[1;33mRemoving $(NAME)\033[0m"
	@rm -rf $(NAME)

re : fclean all

