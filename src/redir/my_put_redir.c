/*
** my_put_redir.c for 42sh in /home/tran_0/rendu/rendugit/PSU_2013_42sh/src
** 
** Made by david tran
** Login   <tran_0@epitech.net>
** 
** Started on  Mon May 19 22:05:56 2014 david tran
** Last update Mon May 19 22:15:23 2014 david tran
*/

#include "42sh.h"
#include "my.h"

int		my_put_redir(t_bin *tmp, int fd)
{
  t_redirec	*new;
  t_redirec	*se;

  if (!(new = malloc(sizeof(t_redirec))))
    return (-1);
  new->fd = fd;
  if (!se)
    {
      tmp->redo = new;
      tmp->redo->head = new;
    }
  else
    {
      se = tmp->redo->head;
      while (se->next)
	se = se->next;
      se->next = new;
    }
  return (EXIT_SUCCESS);
}
