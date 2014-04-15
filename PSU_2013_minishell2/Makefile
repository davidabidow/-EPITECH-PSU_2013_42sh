##
## Makefile for Makefile in /home/tran_0/rendu/PSU_2013_minishell2
## 
## Made by david tran
## Login   <tran_0@epitech.net>
## 
## Started on  Thu Jan 23 15:58:03 2014 david tran
## Last update Wed Mar  5 19:29:28 2014 david tran
##

RM	= rm -f

NAME	= mysh

SRCS	= minishell.c \
	  my_putstr.c \
	  my_strdup.c \
	  makelists.c \
	  my_str_to_wordtab.c \
	  my_strcmp.c \
	  makefork.c \
	  my_path_towordtab.c \
	  chain_to_wordtab.c \
	  dosetenv.c \
	  dochangedir.c \
	  dochangediragain.c \
	  my_tab_to_wordtab.c \
	  my_str_redirect.c \
	  makeforkpipe.c \
	  invertchev.c \
	  returnline_to_tab.c \
	  tradepipe.c \
	  forkpipe.c

OBJ	= $(SRCS:.c=.o)

CFLAGS	= -W -Wall -Wextra -g3

$(NAME): $(OBJ)
	cc -o $(NAME) $(OBJ)

all: $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all
