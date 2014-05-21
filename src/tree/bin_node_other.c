/*
** bin_node_other.c for 42sh in /home/tran_0/rendu/rendugit/PSU_2013_42sh
** 
** Made by david tran
** Login   <tran_0@epitech.net>
** 
** Started on  Wed May 21 12:47:58 2014 david tran
** Last update Thu May 22 01:28:34 2014 david tran
*/

#include "42sh.h"
#include "my.h"

void		add_nodd_command(t_bin *bin, t_bin *new)
{
  t_bin		*tmp;

  if (!bin->head)
    {
      bin->head = new;
    }
  else
    {
      tmp = bin->head;
      while (tmp->left)
	tmp = tmp->left;
      tmp->left = new;
    }
}

int		create_nodd_command(t_bin *bin, char **command, char *princ)
{
  t_bin		*new;

  if (!(new = malloc(sizeof(t_bin))))
    return (-1);
  new->command = NULL;
  if (command)
    if (!(new->command = wordtabdup(command)))
      return (-1);
  new->princ = princ;
  new->op = NULL;
  new->redo = NULL;
  new->pre = NULL;
  new->left = NULL;
  new->right = NULL;
  add_nodd_command(bin, new);
  return (EXIT_SUCCESS);
}

int		check_nodes(t_bin *bin)
{
  t_bin		*tmp;

  tmp = bin->head;
  if (!tmp->left)
    return (EXIT_FAILURE);
  return (EXIT_SUCCESS);
}
