# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ael-abdi <ael-abdi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/18 17:52:56 by ael-abdi          #+#    #+#              #
#    Updated: 2024/02/24 15:03:50 by ael-abdi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex
HEADER = pipex.h
CC = cc
CFLAGS = -Wall -Werror -Wextra
RM = rm -f
obj = pipex.c ft_split.c ft_strjoin.c ft_strncmp.c tools.c main.c

OFILES = $(obj:.c=.o)
all: $(NAME)

$(NAME): $(OFILES)
	$(CC) $(CFLAGS) $(OFILES) -o ${NAME}

%.o : %.c pipex.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OFILES)

fclean: clean
	$(RM) $(NAME)
re: fclean all

.PHONY: all clean fclean re
