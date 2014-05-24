##
## Makefile for 42sh in /home/briard_g/rendu/PSU_2013_42sh
## 
## Made by Guillaume Briard
## Login   <briard_g@epitech.net>
## 
## Started on  Thu May 15 09:55:07 2014 Guillaume Briard
## Last update Fri May 23 22:39:14 2014 samy tabet-helal
##

CC	=	gcc

RM	=	rm -f

NAME	=	globbing

SRC	=	main.c

OBJ	=	$(SRC:.c=.o)

CFLAGS	=	-W -Wextra -Werror -g3

$(NAME):	$(OBJ)
		$(CC) -o $(NAME) $(OBJ)

all:		$(NAME)

clean:
		$(RM) $(OBJ)

fclean:		clean
		$(RM) $(NAME)

re:		fclean all

.PHONY:		all clean fclean re
