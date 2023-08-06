NAME=cub3D
SRCS=main.c
OBJS_DIR=objs/
OBJS=$(addprefix $(OBJS_DIR), $(SRCS:.c=.o))
LIBFT_DIR=libft/
LIBFT_A=$(LIBFT_DIR)libft.a
INCLUDE=-I$(LIBFT_DIR) -Iheaders/
CC=cc
# CFLAGS=-Wall -Wextra -Werro
CFLAGS=
MINILBX=-Lmlx -lmlx -framework OpenGL -framework AppKit
RM=rm -rf

all: $(OBJS_DIR) $(NAME)

$(NAME): $(LIBFT_A) $(OBJS)  
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT_A) $(INCLUDE) $(MINILBX) -o $(NAME)
	@echo $(NAME) was created :\)

$(OBJS_DIR):
	mkdir -p $(OBJS_DIR)

$(LIBFT_A):
	$(MAKE) -C $(LIBFT_DIR)

$(OBJS_DIR)%.o:%.c
	$(CC) $(CFLAGS) $(INCLUDE) -c -o $@ $^

clean:
	$(MAKE) clean -C $(LIBFT_DIR)
	$(RM) $(OBJS_DIR)

fclean: clean
	$(MAKE) fclean -C $(LIBFT_DIR)
	$(RM) $(NAME)

re: fclean all