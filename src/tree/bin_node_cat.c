/*
** bin_node_cat.c for 42sh in /home/tran_0/rendu/rendugit/PSU_2013_42sh
** 
** Made by david tran
** Login   <tran_0@epitech.net>
** 
** Started on  Thu May 22 11:20:52 2014 david tran
** Last update Thu May 22 11:28:44 2014 david tran
*/

#include "42sh.h"
#include "my.h"

int	bin_command_cat(t_bin *bin, char *str)
{
  t_bin	*tmp;

  tmp = bin->head;
  while (tmp->left)
    tmp = tmp->left;
  while (tmp->right)
    tmp = tmp->right;
  if (!tmp->command)
    return (EXIT_FAILURE);
  if (!(tmp->command = wordtab_realloc
	(tmp->command, my_strstrlen(tmp->command) + 2)))
    return (-1);
  if (!(tmp->command = wordtabcat(tmp->command, str)))
    return (-1);
  return (EXIT_SUCCESS);
}
