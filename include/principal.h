/*
** principal.h for 42sh in /home/tran_0/rendu/rendugit/PSU_2013_42sh
** 
** Made by david tran
** Login   <tran_0@epitech.net>
** 
** Started on  Tue May  6 03:28:08 2014 david tran
** Last update Tue May 13 01:42:20 2014 david tran
*/

#ifndef __PRINCIPAL_H__
# define __PRINCIPAL_H__

typedef struct		s_env
{
  char			*data;
  struct s_env		*next;
  struct s_env		*prev;
  struct s_env		*head;
  struct s_env		*end;
}			t_env;

typedef struct		s_buin
{
  char			*name;
  int			(*func)(t_data *, char **);
}			t_buin;

/*
** Signal function
*/
void			dontquit();
/*
** Chained lists
*/
int			init_list(t_env *, char **);
int			put_in_chainlist(t_env *, char *);
char			*makeread(t_env *);
void			infiniteloop(t_env *);
/*
** Builtin
*/
int			my_affchain(t_env *, char *);
int			setinlist(t_env *, char *);
int			changedirect(t_env *, char *);
int			supplist(t_env *, char *);
int			echo_func(t_env *, char *);
int			exit_or_nothing(char *, char *);
int			suppend(t_env *, char *, t_env *, t_env *);
void			suppother(t_env *, t_env *, t_env *);
void			goinghome(t_env *);
/*
** Env Funcs
*/
char			*searchvar(char *);
int			my_strenv(char *, char *);
int			my_countchain(t_env *);
char			*recupvar(t_env *, char *);
char			*cutbuffer(char *);

#endif /* !__PRINCIPAL_H__ */
