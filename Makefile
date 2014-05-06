##
## Makefile for lem_in in /home/tran_0/rendu/rendugit/PSU_2013_42sh
## 
## Made by david tran
## Login   <tran_0@epitech.net>
## 
## Started on  Tue May  6 00:42:35 2014 david tran
## Last update Tue May  6 05:58:41 2014 david tran
##

RM	=	rm -f

NAME	=	mysh

SOUR	=	src/

SRCS	=	$(SOUR)main.c		\
		$(SOUR)signal.c		\
		$(SOUR)my_put_in_list.c	\

OBJ	=	$(SRCS:.c=.o)

CFLAGS	=	-W -Wall -Wextra -g3 -g -Iinclude

$(NAME):	$(OBJ)
		cc -o $(NAME) $(OBJ)

all:		$(NAME)

clean:
		$(RM) $(OBJ)

fclean: 	clean
		$(RM) $(NAME)

re:		fclean all

.PHONY:		fclean re all
