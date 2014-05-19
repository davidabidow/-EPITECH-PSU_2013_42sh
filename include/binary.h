/*
** binary.h for 42sh in /home/tran_0/rendu/rendugit/PSU_2013_42sh/include
** 
** Made by david tran
** Login   <tran_0@epitech.net>
** 
** Started on  Wed May 14 21:52:57 2014 david tran
** Last update Mon May 19 21:47:47 2014 david tran
*/

#ifndef BINARY_H__
# define BINARY_H__

typedef struct		s_redirec
{
  int			fd;
  struct s_redir	*next;
  struct s_redir	*head;
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
  struct s_bin		*head;
  struct s_bin		*left;
  struct s_bin		*right;
}			t_bin;

#endif /* !__BINARY_H__ */
