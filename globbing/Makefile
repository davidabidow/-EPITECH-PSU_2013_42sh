##
## Makefile for 42sh in /home/briard_g/rendu/PSU_2013_42sh
## 
## Made by Guillaume Briard
## Login   <briard_g@epitech.net>
## 
## Started on  Thu May 15 09:55:07 2014 Guillaume Briard
## Last update Tue May 20 15:45:26 2014 Guillaume Briard
##

CC	=	gcc

RM	=	rm -f

NAME	=	globbing

SRC	=	main.c

OBJ	=	$(SRC:.c=.o)

CFLAGS	=	-W -Wextra -Werror

$(NAME):	$(OBJ)
		$(CC) -o $(NAME) $(OBJ)

all:		$(NAME)

clean:
		$(RM) $(OBJ)

fclean:		clean
		$(RM) $(NAME)

re:		fclean all

.PHONY:		all clean fclean re
