##
## Makefile for lem_in in /home/tran_0/rendu/rendugit/PSU_2013_42sh
## 
## Made by david tran
## Login   <tran_0@epitech.net>
## 
## Started on  Tue May  6 00:42:35 2014 david tran
## Last update Wed May  7 17:53:11 2014 david tran
##

RM	=	rm -f

NAME	=	mysh

SOUR	=	src/

SRCS	=	$(SOUR)main.c		\
		$(SOUR)signal.c		\
		$(SOUR)my_put_in_list.c	\

OBJ	=	$(SRCS:.c=.o)

LIB	=	-L./lib -lmy

CFLAGS	=	-W -Wall -Wextra -g3 -g -I./include

$(NAME):	$(OBJ)
		cd ./lib && $(MAKE) re
		cc -o $(NAME) $(OBJ) $(LIB)

all:		$(NAME)

clean:
		$(RM) $(OBJ)
		cd ./lib && $(MAKE) clean

fclean: 	clean
		$(RM) $(NAME)
		cd ./lib && $(MAKE) fclean

re:		fclean all

.PHONY:		fclean re all
