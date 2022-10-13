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
get_next_line: get_next_line.c get_next_line_utils.c
	gcc -g -o get_next_line get_next_line.c get_next_line_utils.c -I.