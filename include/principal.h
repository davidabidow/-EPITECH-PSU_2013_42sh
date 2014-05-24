/*
** principal.h for 42sh in /home/tran_0/rendu/rendugit/PSU_2013_42sh
** 
** Made by david tran
** Login   <tran_0@epitech.net>
** 
** Started on  Tue May  6 03:28:08 2014 david tran
** Last update Sat May 24 16:51:53 2014 david tran
*/

#ifndef PRINCIPAL_H__
# define PRINCIPAL_H__
# define BUFFER_SIZE 1023

typedef struct		s_env
{
  char			*data;
  struct s_env		*next;
  struct s_env		*prev;
  struct s_env		*head;
  struct s_env		*end;
}			t_env;

char			woexit;

typedef struct		s_signa
{
  int			sign;
  char			*signal;
}			t_signa;

/*
** Signal function
*/
void			dontquit();
void			aff_signalcaught(int);
/*
** Chained lists
*/
int			init_list(t_env *, char **);
int			put_in_chainlist(t_env *, char *);
char			*makeread();
void			infiniteloop(t_env *);
/*
** Builtin
*/
int			my_affchain(t_env *, char **);
int			setinlist(t_env *, char **);
int			changedirect(t_env *, char **);
int			supplist(t_env *, char **);
int			exit_or_nothing(char *, char *);
int			suppend(t_env *, char *, t_env *, t_env *);
void			suppother(t_env *, t_env *, t_env *);
void			goinghome(t_env *);
int			countpointpoint(char *);
char			*createnewpwd(int, char *, char *);
int			put_env_var(char *, int *, t_env *);
void			esc_char(char **, t_env *);
int			my_echo(t_env *, char **);
int			put_esc_char(char *, int *);
int			put_one_esc(char *, t_env *);
void			esc_char(char **, t_env *);
int			setinlist_cd(t_env *, char *);
/*
** Env Funcs
*/
char			*searchvar(char *);
int			my_strenv(char *, char *);
int			my_countchain(t_env *);
char			*recupvar(t_env *, char *);
char			*cutbuffer(char *);
void			free_env_list(t_env *);
char			**transform_list(t_env *);
int			count_env(t_env *);
/*
** Redir Funcs
*/
int			double_normal(char *);
char			*double_invert(char *);
int			simple_invert(char *);
int			simple_normal(char *);

typedef struct		s_buin
{
  char			*name;
  int			(*func)(t_env *, char **);
}			t_buin;

typedef struct		s_ope
{
  char			*oper;
}			t_ope;

typedef struct		s_redir
{
  char			*name;
  int			(*func)(char *);
}			t_redir;

extern t_redir		redir[];
extern t_buin		built[];
extern t_ope		operate[];
extern t_signa		sesign[];

#endif /* !PRINCIPAL_H__ */
