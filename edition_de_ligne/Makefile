##
## Makefile for corewar in /home/lacour_a/rendu/corewar
##
## Made by arthur lacour
## Login   <lacour_a@epitech.net>
##
## Started on  Thu Mar 20 10:06:01 2014 arthur lacour
## Last update Wed May  7 19:29:00 2014 valentin wallet
##

RM	=	rm -f

CC	=	gcc

SRC	=	main.c \
		set_term_mode.c \
		string.c \
		deplacement.c

OBJ	=	$(SRC:.c=.o)

NAME	=	mysh

CFLAGS	=	-g3

$(NAME):	$(OBJ)
		$(CC) -o $(NAME) $(OBJ) -lncurses 

all:		$(NAME)

clean:
		$(RM) $(OBJ)

fclean:		clean
		$(RM) $(NAME)

re:		fclean all
