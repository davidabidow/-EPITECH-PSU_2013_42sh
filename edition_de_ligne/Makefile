##
## Makefile for corewar in /home/lacour_a/rendu/corewar
##
## Made by arthur lacour
## Login   <lacour_a@epitech.net>
##
## Started on  Thu Mar 20 10:06:01 2014 arthur lacour
## Last update Wed May 21 19:22:44 2014 valentin wallet
##

RM	=	rm -f

CC	=	gcc

SRC	=	main.c \
		set_term_mode.c \
		string.c \
		ptrfunc.c \
		deplacement.c \
		supp_delete.c \
		start_end_buffer.c \
		ctrl.c \
		history.c \
		list.c \
		my_str_to_wordtab.c \
		utility.c \
		history_deplacement.c

OBJ	=	$(SRC:.c=.o)

NAME	=	mysh

CFLAGS	=	-W -Wall -Wextra -g3

$(NAME):	$(OBJ)
		$(CC) -o $(NAME) $(OBJ) -lncurses 

all:		$(NAME)

clean:
		$(RM) $(OBJ)

fclean:		clean
		$(RM) $(NAME)

re:		fclean all
