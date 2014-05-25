/*
** binary.h for 42sh in /home/tran_0/rendu/rendugit/PSU_2013_42sh/include
** 
** Made by david tran
** Login   <tran_0@epitech.net>
** 
** Started on  Wed May 14 21:52:57 2014 david tran
** Last update Sun May 25 08:52:16 2014 david tran
*/

#ifndef BINARY_H__
# define BINARY_H__

typedef struct		s_redirec
{
  int			fd;
  char			*dinv;
  struct s_redirec	*next;
  struct s_redirec	*head;
}			t_redirec;

typedef struct		s_pars
{
  int			i;
  char			**path;
  char			*princ;
  char			**command;
}			t_pars;

typedef struct		s_bin
{
  char			**command;
  char			*op;
  char			*princ;
  t_redirec		*redo;
  t_redirec		*pre;
  struct s_bin		*head;
  struct s_bin		*left;
  struct s_bin		*right;
}			t_bin;

typedef struct		s_exec
{
  int			save_pipeout;
  pid_t			pid;
  int			pipefd[2];
  int			status;
  int			ffd;
}			t_exec;

typedef struct		s_cmd
{
  char			*save;
  char			*restor;
  char			*curse_r;
  char			*curse_l;
  char			*curse_up;
  char			*curse;
  char			*cursef;
  char			*clearstr;
  char			*gotostr;
  char			*standstr;
  char			*stendstr;
  char			*underlines;
  char			*underlinef;
  char			*suppline;
}			t_cmd;

typedef struct		s_termcap
{
  t_cmd			data;
  char			*str;
  char			*tmp;
  int			buff;
  int			x;
}			t_termcap;

typedef struct		s_history
{
  char			*str;
  struct s_history	*next;
  struct s_history	*previous;
}			t_history;

typedef struct		s_loop
{
  char			**dest;
  int			min;
  int			max;
  char			**new;
  int			tmp;
  t_termcap		term;
  t_history		*history;
  struct winsize	mysizewin;
  struct termios	t;
  struct termios	tsave;
}			t_loop;

/*
** Tree Nodes
*/
int			create_nodd_command(t_bin *, char **, char *);
int			add_redir_final(t_bin *, int);
int			add_redir_princ(t_bin *, int, char *);
int			update_op(t_bin *, char *);
int			create_nodd_pipe(t_bin *, char **, char *);
int			my_put_redir(t_bin *, int);
int			my_put_princ(t_bin *, int, char *);
int			check_nodes(t_bin *);
int			check_feeded_node(t_bin *);
int			check_nodes(t_bin *);
int			bin_command_cat(t_bin *, char *);
int			update_command(t_bin *, char **, char *);
void			bin_aff(t_bin *);
int			parsing_send(t_bin *, t_env *);
/*
** Parsing Funcs
*/
int			parsing_exec(char **, t_env *);
int			check_wone(char *, char **);
int			parsing_command(char **, t_bin *, t_pars *);
int			parsing_redir(char **, t_bin *, t_pars *);
int			parsing_built(char **, t_bin *, t_pars *);
int			parsing_ope(char **, t_bin *, t_pars *);
char			*recup_princ(char **, char *);
int			infinite_loop_feed(t_loop *, t_env *);
/*
** Parsing Funcs Second Part
*/
int			add_command(char **, t_bin *, t_pars *);
int			add_redir(char **, t_bin *, t_pars *);
int			add_built(char **, t_bin *, t_pars *);
int			add_ope(char **, t_bin *, t_pars *);
int			loop_pipe(t_bin *, char **, t_env **);

typedef struct		s_pinit
{
  char			ch;
  int			(*func)(char **, t_bin *, t_pars *);
}			t_pinit;

extern t_pinit		go_init[];
extern t_pinit		go_pars[];

#endif /* !__BINARY_H__ */
