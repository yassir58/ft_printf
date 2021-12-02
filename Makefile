# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yelatman <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/17 18:56:04 by yelatman          #+#    #+#              #
#    Updated: 2021/11/17 18:56:18 by yelatman         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


CC=gcc
CFLAGS= -Wall -Wextra -Werror
SRCS = ft_printf.c print_hex.c add_print.c print_pointer.c\
	  ft_putnbr_fd.c ft_putstr_fd.c ft_putchar_fd.c ft_strlen.c\
	 print_unsigned.c
HEADER = ft_printf.h
NAME = libftprintf.a
OBJS = $(SRCS:.c=.o)


$(NAME): $(OBJS) $(HEADER) 
	ar -rc $@ $(OBJS)

%.o : %.c $(HEADER)
	$(CC) $(CFLAGS) -c $<

all : $(NAME)

clean:
	rm -f *.o

fclean : clean
	rm -f $(NAME)

re : fclean all
