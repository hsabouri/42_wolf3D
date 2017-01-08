# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hsabouri <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/08/19 10:32:42 by hsabouri          #+#    #+#              #
#    Updated: 2016/12/18 16:15:36 by hsabouri         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
INCLUDES = ./includes
CFLAGS = -Wall -Werror -Wextra
#CFLAGS +=-g -fsanitize=address
CC = gcc
SRC	= ft_atoi.c ft_bzero.c ft_isalnum.c ft_isalpha.c ft_isascii.c\
	  ft_isblank.c ft_isblankn.c ft_isdigit.c ft_isprint.c ft_isspace.c\
	  ft_itoa.c ft_lstnew.c ft_memalloc.c ft_memccpy.c ft_memchr.c\
	  ft_memcmp.c ft_memcpy.c ft_memdel.c ft_memmove.c ft_memrchr.c ft_memset.c\
	  ft_putchar.c ft_putchar_fd.c ft_putendl.c ft_putendl_fd.c ft_putnbr.c\
	  ft_putnbr_fd.c ft_putstr.c ft_putstr_fd.c ft_strcat.c ft_strchr.c\
	  ft_strclr.c ft_strcmp.c ft_strcpy.c ft_strdel.c ft_strdup.c ft_strequ.c\
	  ft_striter.c ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlen.c\
	  ft_strmap.c ft_strmapi.c ft_strncat.c ft_strncmp.c ft_strncpy.c\
	  ft_strnequ.c ft_strnew.c ft_strnstr.c ft_strrchr.c ft_strsplit.c\
	  ft_strstr.c ft_strsub.c ft_strtrim.c ft_tolower.c ft_toupper.c\
	  ft_lstdelone.c ft_lstdel.c ft_lstnew.c ft_lstadd.c ft_lstiter.c\
	  ft_lstmap.c ft_sin.c ft_cos.c ft_tan.c ft_power.c ft_factoriel.c\
	  ft_sqrt.c ft_lstpushback.c ft_lstgoto.c ft_memjoin.c get_next_line.c\
	  ft_swap.c ft_realloc.c 
OBJ	= $(SRC:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $@ $^
	ranlib $@

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $< -I$(INCLUDES)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean
	$(MAKE) all
