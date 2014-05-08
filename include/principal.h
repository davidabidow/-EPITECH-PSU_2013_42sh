/*
** principal.h for 42sh in /home/tran_0/rendu/rendugit/PSU_2013_42sh
** 
** Made by david tran
** Login   <tran_0@epitech.net>
** 
** Started on  Tue May  6 03:28:08 2014 david tran
** Last update Wed May  7 18:01:28 2014 david tran
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

/*
** Signal function
*/
void			dontquit();
/*
** Chained lists
*/
int			init_list(t_env *, char **);
void			put_in_chainlist(t_env *, char *);

#endif /* !__PRINCIPAL_H__ */
