# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/21 14:38:01 by arobu             #+#    #+#              #
#    Updated: 2023/05/18 13:16:47 by arobu            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Variables
NAME			= minirt
INCLUDE			= -I include/ -I libft-printf/include/ -I MLX42/include/MLX42/ -I ./src/vector/ -I ./src/transform -I ./src/camera -I ./src/quaternion -I ./src/scene -I ./src/logger -I ./src/tester
DSYM			= ./minirt.dSYM
SRC_DIR			= ./src
OBJ_DIR			= ./obj
LIBFT_FOLDER	= ./libft-printf
LIBFT_LIB		= ./libft-printf/libft.a
MAIN_FILE		= main.c
MLX_LIB			= ./MLX42/build
GLFW_LIB		= ./glfw/build/src
GLFW_BUILD		= ./glfw/build
MLX_BUILD		= ./MLX42/build
NORM_INCLUDE	= ./include
VPATH			= ./src/vector/:./src/transform

# Modules

VECTOR_DIR		= ./src/vector/
VECTOR_OBJ_DIR	= ./obj/vector

TRANSFORM_DIR 		= ./src/transform/
TRANSFORM_OBJ_DIR	= ./obj/transform

CAMERA_DIR		= ./src/camera/
CAMERA_OBJ_DIR	= ./obj/camera

QUATERNION_DIR	= ./src/quaternion/
QUATERNION_OBJ_DIR	= ./obj/quaternion

LOGGER_DIR		= ./src/logger/
LOGGER_OBJ_DIR	= ./obj/logger

TESTER_DIR		= ./src/tester/
TESTER_OBJ_DIR	= ./obj/tester

# Compiler
CC			= cc #-Wall -Werror -Wextra
CFLAGS		= -Ofast -march=nocona -flto
ASAN		= #-fsanitize=address -g3
#CFLAGS		= -Ofast -march=native -flto #-fsanitize=address -g3 #-g3 -Wall -Werror -Wextra -g3 #
FRAMEWORK	= -framework Cocoa -framework OpenGL -framework IOKit
LDLFLAGS	= -L $(LIBFT_FOLDER) -L $(MLX_LIB) -L $(GLFW_LIB)
LIBFLAGS	= -lft -lmlx42 -lglfw3 -lm
#LDLFLAGS	= -lft -L ./libft/ -lmlx42 -L ./MLX42/build -ldl -lglfw -pthread

#Archive and Remove
RM			= rm -f
AR			= ar rcs

# Colors
DEF_COLOR = \033[0;39m
RED = \033[0;91m
GREEN = \033[0;92m
YELLOW = \033[0;93m
BLUE = \033[0;94m
MAGENTA = \033[0;95m
CYAN = \033[0;96m
WHITE = \033[0;97m

# Sources
VECTOR_SRCS		=	$(wildcard $(VECTOR_DIR)*.c)
TRANSFORM_SRCS	=	$(wildcard $(TRANSFORM_DIR)*.c)
CAMERA_SRCS		=	$(wildcard $(CAMERA_DIR)*.c)
QUATERNION_SRCS	=	$(wildcard $(QUATERNION_DIR)*.c)
LOGGER_SRCS		=	$(wildcard $(LOGGER_DIR)*.c)
TESTER_SRCS		=	$(wildcard $(TESTER_DIR)*.c)

# Objects
VECTOR_OBJS		= 	$(patsubst $(VECTOR_DIR)%.c, $(VECTOR_OBJ_DIR)/%.o, $(VECTOR_SRCS))
TRANSFORM_OBJS	= 	$(patsubst $(TRANSFORM_DIR)%.c, $(TRANSFORM_OBJ_DIR)/%.o, $(TRANSFORM_SRCS))
CAMERA_OBJS		=	$(patsubst $(CAMERA_DIR)%.c, $(CAMERA_OBJ_DIR)/%.o, $(CAMERA_SRCS))
QUATERNION_OBJS	=	$(patsubst $(QUATERNION_DIR)%.c, $(QUATERNION_OBJ_DIR)/%.o, $(QUATERNION_SRCS))
LOGGER_OBJS		=	$(patsubst $(LOGGER_DIR)%.c, $(LOGGER_OBJ_DIR)/%.o, $(LOGGER_SRCS))
TESTER_OBJS		=	$(patsubst $(TESTER_DIR)%.c, $(TESTER_OBJ_DIR)/%.o, $(TESTER_SRCS))


# Dependencies
DEPS			= $(VECTOR_OBJS)
DEPS			+= $(TRANSFORM_OBJS)
DEPS			+= $(CAMERA_OBJS)
DEPS			+= $(QUATERNION_OBJS)
DEPS			+= $(LOGGER_OBJS)
DEPS			+= $(TESTER_OBJS)
# Rules
all:	libft	$(NAME) #deps

$(NAME): $(DEPS) $(MAIN_FILE)| $(OBJ_DIR)
	@$(CC) $(INCLUDE) $(FRAMEWORK) $(ASAN) $(DEPS) $(MAIN_FILE) -o $@ -lm $(LDLFLAGS) $(LIBFLAGS)
	@echo "$(YELLOW)MiniRT$(DEF_COLOR) $(CYAN)done.$(DEF_COLOR)"

$(VECTOR_OBJ_DIR)/%.o: $(VECTOR_DIR)/%.c | $(VECTOR_OBJ_DIR)
	@echo "$(MAGENTA)Compiling:$(DEF_COLOR) $<."
	@$(CC) $(INCLUDE) $(CFLAGS) -c $< -o $@ 
	
$(TRANSFORM_OBJ_DIR)/%.o: $(TRANSFORM_DIR)/%.c | $(TRANSFORM_OBJ_DIR)
	@echo "$(MAGENTA)Compiling:$(DEF_COLOR) $<."
	@$(CC) $(INCLUDE) $(CFLAGS) -c $< -o $@

$(CAMERA_OBJ_DIR)/%.o: $(CAMERA_DIR)/%.c | $(CAMERA_OBJ_DIR)
	@echo "$(MAGENTA)Compiling:$(DEF_COLOR) $<."
	@$(CC) $(INCLUDE) $(CFLAGS) -c $< -o $@

$(QUATERNION_OBJ_DIR)/%.o: $(QUATERNION_DIR)/%.c | $(QUATERNION_OBJ_DIR)
	@echo "$(MAGENTA)Compiling:$(DEF_COLOR) $<."
	@$(CC) $(INCLUDE) $(CFLAGS) -c $< -o $@

$(LOGGER_OBJ_DIR)/%.o: $(LOGGER_DIR)/%.c | $(LOGGER_OBJ_DIR)
	@echo "$(MAGENTA)Compiling:$(DEF_COLOR) $<."
	@$(CC) $(INCLUDE) $(CFLAGS) -c $< -o $@

$(TESTER_OBJ_DIR)/%.o: $(TESTER_DIR)/%.c | $(TESTER_OBJ_DIR)
	@echo "$(MAGENTA)Compiling:$(DEF_COLOR) $<."
	@$(CC) $(INCLUDE) $(CFLAGS) -c $< -o $@

$(VECTOR_OBJ_DIR):
	@mkdir -p $(VECTOR_OBJ_DIR)

 $(TRANSFORM_OBJ_DIR):
	@mkdir -p $(TRANSFORM_OBJ_DIR)

 $(CAMERA_OBJ_DIR):
	@mkdir -p $(CAMERA_OBJ_DIR)

 $(QUATERNION_OBJ_DIR):
	@mkdir -p $(QUATERNION_OBJ_DIR)

 $(LOGGER_OBJ_DIR):
	@mkdir -p $(LOGGER_OBJ_DIR)

 $(TESTER_OBJ_DIR):
	@mkdir -p $(TESTER_OBJ_DIR)

deps:
	@chmod +x ./install_deps.sh
	@echo "$(YELLOW)Installing dependencies..$(DEF_COLOR)"
	@./install_deps.sh

show:
	echo $(QUATERNION_OBJS)

libft:
			@make all -C $(LIBFT_FOLDER) -s

 clean:
			@$(RM) -rdf $(OBJ_DIR)
			@$(RM) -rdf $(DSYM)
			@echo "$(YELLOW)MiniRT$(DEF_COLOR) $(CYAN)successfully cleaned!$(DEF_COLOR)"

fclean:		clean
#			@make fclean -C $(LIBFT_FOLDER)
#			@rm -rdf $(GLFW_BUILD)
#			@rm -rdf $(MLX_BUILD)
			@$(RM) -f $(NAME)
			@echo "$(YELLOW)All$(DEF_COLOR) $(CYAN)objects successfully cleaned!$(DEF_COLOR)"

re:			fclean all

relibft:
			@make re -C $(LIBFT_FOLDER)

bonus:	libft	mlx	$(NAME)

.PHONY:		all mlx relibft libft clean fclean re norm
