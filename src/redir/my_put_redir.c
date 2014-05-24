/*
** my_put_redir.c for 42sh in /home/tran_0/rendu/rendugit/PSU_2013_42sh/src
** 
** Made by david tran
** Login   <tran_0@epitech.net>
** 
** Started on  Mon May 19 22:05:56 2014 david tran
** Last update Fri May 23 13:43:45 2014 david tran
*/

#include "42sh.h"
#include "my.h"

int		my_put_redir(t_bin *tmp, int fd)
{
  t_redirec	*new;
  t_redirec	*detailledsearch;

  if (!(new = malloc(sizeof(t_redirec))))
    return (-1);
  new->next = NULL;
  new->fd = fd;
  if (!tmp->head)
    tmp->redo->head = new;
  else
    {
      detailledsearch = tmp->redo->head;
      while (detailledsearch && detailledsearch->next)
	detailledsearch = detailledsearch->next;
      if (!detailledsearch)
	detailledsearch = new;
      else
	detailledsearch->next = new;
    }
  return (EXIT_SUCCESS);
}

int		my_put_princ(t_bin *tmp, int fd, char *str)
{
  t_redirec	*new;
  t_redirec	*se;

  if ((fd == -1 && !str) || !(new = malloc(sizeof(t_redirec))))
    return (-1);
  new->fd = fd;
  new->dinv = NULL;
  new->next = NULL;
  if (str)
    if (!(new->dinv = my_strdup(str)))
      return (-1);
  if (!tmp->head)
    tmp->pre->head = new;
  else
    {
      se = tmp->pre->head;
      while (se->next)
	se = se->next;
      se->next = new;
    }
  return (EXIT_SUCCESS);
}
