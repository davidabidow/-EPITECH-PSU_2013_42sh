##
## Makefile for lib in /home/tran_0/rendu/rendugit/PSU_2013_42sh/lib
## 
## Made by david tran
## Login   <tran_0@epitech.net>
## 
## Started on  Tue May  6 06:01:43 2014 david tran
## Last update Wed May  7 02:48:57 2014 david tran
##

NAME		= 	libmy.a

SRC		=	my_getnbr.c			\
			my_putchar.c			\
			my_put_nbr.c			\
			my_putstr.c			\
			my_strcat.c			\
			my_strcmp.c			\
			my_strcpy.c			\
			my_strdup.c			\
			my_strlen.c			\
			my_getnbr.c			\
			epur_str.c			\
			wordtab.c

OBJ		=	$(SRC:.c=.o)

CFLAGS		=	-I../include -W -Wextra -Wall

RM		=	rm -f

%.o:			%.c
			@cc $(CFLAGS) -c $< -o $@

$(NAME):		$(OBJ)
			ar rc $(NAME) $(OBJ)
			ranlib $(NAME)

all:			$(NAME)

clean:
			$(RM) $(OBJ)

fclean:			clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:			all clean re
