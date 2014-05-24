##
## Makefile for lem_in in /home/tran_0/rendu/rendugit/PSU_2013_42sh
## 
## Made by david tran
## Login   <tran_0@epitech.net>
## 
## Started on  Tue May  6 00:42:35 2014 david tran
## Last update Sat May 24 02:22:42 2014 david tran
##

RM	=	rm -f

NAME	=	mysh

SOUR	=	src/

BUILT	=	builtin/

REDIR	=	redir/

PARS	=	parsing/

TREE	=	tree/

EDITION	=	edition_de_ligne/

SRCS	=	$(SOUR)main.c				\
		$(SOUR)signal.c				\
		$(SOUR)my_put_in_list.c			\
		$(SOUR)infinite_loop.c			\
		$(SOUR)read_buffer.c			\
		$(SOUR)env_funcs.c			\
		$(SOUR)env_transform.c			\
		$(SOUR)operation_init.c			\
		$(SOUR)free_env.c			\
		$(SOUR)infinite_pipe.c			\
		$(SOUR)$(BUILT)built_cd.c		\
		$(SOUR)$(BUILT)built_cd_other.c		\
		$(SOUR)$(BUILT)built_env.c		\
		$(SOUR)$(BUILT)built_setenv.c		\
		$(SOUR)$(BUILT)built_unsetenv.c		\
		$(SOUR)$(BUILT)search_builtin.c		\
		$(SOUR)$(REDIR)double_invert.c		\
		$(SOUR)$(REDIR)double_normal.c		\
		$(SOUR)$(REDIR)my_put_redir.c		\
		$(SOUR)$(REDIR)search_redir.c		\
		$(SOUR)$(REDIR)simple_invert.c		\
		$(SOUR)$(REDIR)simple_normal.c		\
		$(SOUR)$(PARS)parsing_built.c		\
		$(SOUR)$(PARS)parsing_check_wone.c	\
		$(SOUR)$(PARS)parsing_command.c		\
		$(SOUR)$(PARS)parsing_init.c		\
		$(SOUR)$(PARS)parsing_oper.c		\
		$(SOUR)$(PARS)parsing_redir.c		\
		$(SOUR)$(PARS)parsing_send.c		\
		$(SOUR)$(PARS)parsing_add_ope.c		\
		$(SOUR)$(PARS)parsing_add_redir.c	\
		$(SOUR)$(PARS)parsing_add_command.c	\
		$(SOUR)$(PARS)parsing_add_built.c	\
		$(SOUR)$(TREE)bin_free.c		\
		$(SOUR)$(TREE)bin_node.c		\
		$(SOUR)$(TREE)bin_aff.c			\
		$(SOUR)$(TREE)bin_node_cat.c		\
		$(SOUR)$(TREE)bin_node_other.c		\
		$(EDITION)main.c 			\
		$(EDITION)set_term_mode.c 		\
		$(EDITION)string.c 			\
		$(EDITION)ptrfunc.c 			\
		$(EDITION)deplacement.c 		\
		$(EDITION)supp_delete.c 		\
		$(EDITION)start_end_buffer.c 		\
		$(EDITION)ctrl.c 			\
		$(EDITION)history.c 			\
		$(EDITION)list.c 			\
		$(EDITION)my_str_to_wordtab.c 		\
		$(EDITION)utility.c 			\
		$(EDITION)history_deplacement.c

OBJ	=	$(SRCS:.c=.o)

LIB	=	-L./lib -lmy

CFLAGS	=	-W -Wall -Wextra -g3 -g -I./include

$(NAME):	$(OBJ)
		cd ./lib && $(MAKE) re
		cc -o $(NAME) $(OBJ) -lncurses $(LIB)

all:		$(NAME)

clean:
		$(RM) $(OBJ)
		cd ./lib && $(MAKE) clean

fclean: 	clean
		$(RM) $(NAME)
		cd ./lib && $(MAKE) fclean

re:		fclean all

.PHONY:		fclean re all
