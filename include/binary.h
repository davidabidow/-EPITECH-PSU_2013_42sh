/*
** binary.h for 42sh in /home/tran_0/rendu/rendugit/PSU_2013_42sh/include
** 
** Made by david tran
** Login   <tran_0@epitech.net>
** 
** Started on  Wed May 14 21:52:57 2014 david tran
** Last update Tue May 20 22:53:46 2014 david tran
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
/*
** Parsing Funcs
*/
int			parsing_exec(char **, t_env *);
int			check_wone(char *, char **);
int			parsing_command(char **, t_bin *, t_pars *);
int			parsing_redir(char **, t_bin *, t_pars *);
int			parsing_built(char **, t_bin *, t_pars *);
int			parsing_ope(char **, t_bin *, t_pars *);

typedef struct		s_pinit
{
  char			ch;
  int			(*func)(char **, t_bin *, t_pars *);
}			t_pinit;

extern t_pinit		go_init[];

#endif /* !__BINARY_H__ */
