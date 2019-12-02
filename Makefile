# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: padelord <padelord@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/05 18:58:28 by padelord          #+#    #+#              #
#    Updated: 2019/10/09 17:26:40 by padelord         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libftprintf.a

CC		=	gcc

SRCS	=	main.c

OBJS	=	$(SRCS:.c=.o)

CFLAGS	=	-Wall -Wextra -Werror -I./ -I./libft/

HEADERS = libftprintf.h

all: $(NAME)

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -o $@ -c $<

test:
	make -C tests

clean:
	@rm -f $(OBJS)
	@echo "Deleted libftprintf objects"

fclean:	clean
	@rm -f $(NAME)
	@echo "Deleted $(NAME)"

re:	fclean all
