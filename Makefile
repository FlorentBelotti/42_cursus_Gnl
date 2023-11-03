# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fbelotti <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/14 15:56:01 by fbelotti          #+#    #+#              #
#    Updated: 2023/11/03 16:18:53 by fbelotti         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC	=	get_next_line_utils.c \
		get_next_line.c \

CC	= gcc -Wall -Wextra -Werror

RM	= rm -f

NAME	=	get_next_line.a

OBJS	=	$(SRC:.c=.o)

HEADER	=	get_next_line.h

all: $(NAME)

$(NAME) : $(OBJS)
	ar rcs $(NAME) $(OBJS)

%.o: %.c $(HEADER)
	$(CC) -c $< -o $@

clean :
	rm -f $(OBJS) $(OBJSBONUS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
