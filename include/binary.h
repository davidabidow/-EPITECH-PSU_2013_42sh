/*
** binary.h for 42sh in /home/tran_0/rendu/rendugit/PSU_2013_42sh/include
** 
** Made by david tran
** Login   <tran_0@epitech.net>
** 
** Started on  Wed May 14 21:52:57 2014 david tran
** Last update Thu May 15 01:23:05 2014 david tran
*/

#ifndef __BINARY_H__
# define __BINARY_H__

typedef struct		s_redir
{
  char			id;
  int			fd;
}			t_redir;

typedef struct		s_bin
{
  char			wone;
  char			**command;
  t_redir		redi;
  struct s_bin		*left;
  struct s_bin		*right;
}			t_bin;

#endif /* !__BINARY_H__ */
