# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hsabouri <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/08/19 10:32:42 by hsabouri          #+#    #+#              #
#    Updated: 2017/01/08 09:55:40 by hsabouri         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = wolf3d
LIBPATH = libft
LIBNAME = libft.a
LIB = $(LIBNAME:%=$(LIBPATH)/%)
CFLAGS = -Wall -Wextra -I$(LIBINC) -I$(INC)
#CFLAGS += -O2 -march=native
CFLAGS += -g -fsanitize=address
LDFLAGS = -L $(LIBPATH) -l$(LIBNAME:lib%.a=%) -lmlx -framework OpenGL\
			-framework AppKit
CC = gcc
SRCDIR = srcs
SRCS = main.c init.c\
	   m_abs.c\
	   g_image.c\
	   g_keyboard.c\
	   g_loop.c
SRC = $(SRCS:%.c=$(SRCDIR)/%.c)
LIBINC = $(LIBPATH)/includes/
INC = includes
OBJ	= $(SRC:$(SRCDIR)/%.c=%.o)

all: $(NAME) $(LIB)

$(LIB):
	$(MAKE) -C $(LIBPATH)

$(NAME): $(OBJ) $(LIB)
	$(CC) -o $@ $(LDFLAGS) $(OBJ) $(CFLAGS)

%.o: $(SRCDIR)/%.c
	$(CC) $(CFLAGS) -o $@ -c $<

.PHONY: clean
clean:
	rm -rf $(OBJ)

.PHONY: fclean
fclean: clean
	rm -rf $(NAME)

re: fclean
	$(MAKE) all
