# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aessaoud <aessaoud@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/07 11:51:49 by aessaoud          #+#    #+#              #
#    Updated: 2023/08/23 16:07:13 by aessaoud         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=cub3D
NAME_BONUS=cub3D_bonus
HEADER=cub3d_header.h

LIBFT_DIR=libft/
SRCS_DIR=mandatory/
BONUS_SRCS_DIR=bonus/
INCLUDE= -I$(LIBFT_DIR) -Iheaders/
LIBS=MLX42/libmlx42.a
SRCS=main.c key_me.c init_.c checker.c checker_2.c extract_map.c cast.c render_wall.c draw_update_objects.c horizontal_intersection.c vertical_intersection.c utils.c extract_texture.c extract_mbp.c extract_mcp.c render_wall2.c free_me.c
BONUS_SRCS=main.c key_me.c init_.c checker.c checker_2.c extract_map.c cast.c render_wall.c draw_update_objects.c horizontal_intersection.c vertical_intersection.c utils.c extract_texture.c extract_mbp.c extract_mcp.c render_wall2.c free_me.c draw_me.c mouse_me.c

OBJS_DIR=objs/
BONUS_OBJS_DIR=objs_bonus/

OBJS=$(addprefix $(OBJS_DIR), $(SRCS:.c=.o))
BONUS_OBJS=$(addprefix $(BONUS_OBJS_DIR), $(BONUS_SRCS:.c=.o))
LIBFT_A=$(LIBFT_DIR)libft.a
CFLAGS = -Wall -Werror -Wextra


CC=cc
RM=rm -rf
GLFW = $(shell brew --prefix glfw)
MLX_FLAGS=$(LIBS) -framework Cocoa -framework OpenGL -framework IOKit -lglfw -L"$(GLFW)/lib" -O3

all: $(OBJS_DIR) $(NAME)
bonus: $(BONUS_OBJS_DIR) $(NAME_BONUS)

$(NAME): $(LIBFT_A) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT_A) $(MLX_FLAGS) $(INCLUDE) -o $(NAME) 
	@echo $(NAME) was created :\)


$(NAME_BONUS):$(LIBFT_A) $(BONUS_OBJS)
	$(CC) $(CFLAGS) $(BONUS_OBJS) $(LIBFT_A) $(MLX_FLAGS) $(INCLUDE) -o $(NAME_BONUS) 
	@echo $(NAME_BONUS) was created :\)
	
$(OBJS_DIR):
	mkdir -p $(OBJS_DIR)
$(BONUS_OBJS_DIR):
	mkdir -p $(BONUS_OBJS_DIR)


$(LIBFT_A):
	make -C $(LIBFT_DIR)

$(OBJS_DIR)%.o:$(SRCS_DIR)%.c
	$(CC) $(CFLAGS) $(INCLUDE) -c -o $@ $^
$(BONUS_OBJS_DIR)%.o:$(BONUS_SRCS_DIR)%.c
	$(CC) $(CFLAGS) $(INCLUDE) -c -o $@ $^


clean:
	make clean -C $(LIBFT_DIR)
	$(RM) $(OBJS_DIR)
	$(RM) $(BONUS_OBJS_DIR)

fclean: clean
	make fclean -C $(LIBFT_DIR)
	$(RM) $(NAME)
	$(RM) $(NAME_BONUS)


re: fclean all