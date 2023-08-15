# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aessaoud <aessaoud@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/07 11:51:49 by aessaoud          #+#    #+#              #
#    Updated: 2023/08/15 10:37:07 by aessaoud         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=cub3D
LIBFT_DIR=libft/

HEADERS=  -I$(LIBFT_DIR)
LIBS=MLX42/libmlx42.a
SRCS=main.c draw_me.c key_me.c checker.c extract_map.c cast.c render_wall.c
OBJS_DIR=objs/
OBJS=$(addprefix $(OBJS_DIR), $(SRCS:.c=.o))
LIBFT_A=$(LIBFT_DIR)libft.a
# CFLAGS = -fsanitize=address

CC=cc
RM=rm -rf
GLFW = $(shell brew --prefix glfw)
MLX_FLAGS=$(LIBS) -framework Cocoa -framework OpenGL -framework IOKit -lglfw -L"$(GLFW)/lib" 

all: $(OBJS_DIR) $(NAME)


$(NAME): $(LIBFT_A) $(OBJS) Cub3dHeader.h
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT_A) $(MLX_FLAGS) -o $(NAME) 
	@echo $(NAME) was created :\)

$(OBJS_DIR):
	mkdir -p $(OBJS_DIR)

$(LIBFT_A):
	make -C $(LIBFT_DIR)

$(OBJS_DIR)%.o:%.c
	$(CC) $(CFLAGS) $(HEADERS) -c -o $@ $^

clean:
	make clean -C $(LIBFT_DIR)
	$(RM) $(OBJS_DIR)

fclean: clean
	make fclean -C $(LIBFT_DIR)
	$(RM) $(NAME)

re: fclean all