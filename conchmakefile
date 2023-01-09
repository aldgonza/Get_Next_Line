# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aldgonza <aldgonza@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/10 20:16:48 by aldgonza          #+#    #+#              #
#    Updated: 2022/09/10 21:07:36 by aldgonza         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= get_next_line.a
HEADER	= get_next_line.h
SRCS	= get_next_line.c \
		get_next_line_utils.c \

CC		= gcc
CFLAGS	= -Wall -Wextra -Werror
OBJS	= ${SRCS:%.c=%.o}

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): ${HEADER} ${OBJS}
		ar rc $(NAME) $(OBJS)


all: $(NAME)


clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
