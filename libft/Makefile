# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aessaoud <aessaoud@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/23 14:50:52 by aessaoud          #+#    #+#              #
#    Updated: 2023/05/10 21:14:54 by aessaoud         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC=gcc
CFLAGS=-Wall -Wextra -Werror
RM=rm -rf
NAME=libft.a

LIBFT_DIR=ft_libft/
PRINTF_DIR=ft_printf/
GNL_DIR=get_next_line/
OBJS_DIR=objs/

INC=-I./

count := 0

LIBFT_SRCS_LIST = ft_memset.c \
ft_atoi.c \
ft_bzero.c \
ft_tolower.c \
ft_toupper.c \
ft_strnstr.c \
ft_calloc.c \
ft_memchr.c \
ft_isalnum.c \
ft_memcmp.c \
ft_memcpy.c \
ft_memmove.c \
ft_strncmp.c \
ft_isalpha.c \
ft_strchr.c \
ft_isascii.c \
ft_strdup.c \
ft_isdigit.c \
ft_isprint.c \
ft_strrchr.c \
ft_strlcat.c \
ft_strlcpy.c \
ft_strlen.c \
ft_substr.c \
ft_strtrim.c \
ft_split.c \
ft_itoa.c \
ft_strjoin.c \
ft_striteri.c \
ft_strmapi.c \
ft_putchar_fd.c \
ft_putstr_fd.c \
ft_putendl_fd.c \
ft_putnbr_fd.c \
ft_lstadd_front.c \
ft_lstadd_back.c \
ft_lstclear.c \
ft_lstdelone.c \
ft_lstiter.c \
ft_lstlast.c \
ft_lstmap.c \
ft_lstnew.c \
ft_lstsize.c \

PRINTF_SRCS_LIST=ft_printf.c\
ft_putchar.c\
ft_putnbr.c\
ft_putnbru.c\
ft_putstr.c

GNL_SRCS_LIST=get_next_line.c\
get_next_line_utils.c\

LIBFT_PATH=$(addprefix $(LIBFT_DIR), $(LIBFT_SRCS_LIST))
PRINTF_PATH=$(addprefix $(PRINTF_DIR), $(PRINTF_SRCS_LIST))
GNL_PATH=$(addprefix $(GNL_DIR), $(GNL_SRCS_LIST))
SRCS=$(LIBFT_PATH) $(PRINTF_PATH) $(GNL_PATH)

OBJ_1=$(LIBFT_SRCS_LIST:.c=.o)
OBJ_2=$(PRINTF_SRCS_LIST:.c=.o)
OBJ_3=$(GNL_SRCS_LIST:.c=.o)

OBJS_LIST=$(OBJ_1) $(OBJ_2) $(OBJ_3)

OBJS=$(addprefix $(OBJS_DIR), $(OBJS_LIST))

all:$(OBJS_DIR) $(NAME)

$(OBJS_DIR):
	@mkdir -p objs
	
${NAME}:${OBJS}
	@ar -rc $(NAME) $(OBJS) 
	
$(OBJS_DIR)%.o:$(LIBFT_DIR)%.c
	@$(CC) $(CFLAGS) $(INC) -c -o $@ $^
	
$(OBJS_DIR)%.o:$(PRINTF_DIR)%.c
	@$(CC) $(CFLAGS) $(INC) -c -o $@ $^

$(OBJS_DIR)%.o:$(GNL_DIR)%.c
	@$(CC) $(CFLAGS) $(INC) -c -o $@ $^
	
clean:
	@$(RM) $(OBJS_DIR)

fclean: clean
	@$(RM) $(NAME)

re: fclean all
