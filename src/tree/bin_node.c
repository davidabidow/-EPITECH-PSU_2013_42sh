/*
** bin_node.c for 42sh in /home/tran_0/rendu/rendugit/PSU_2013_42sh/include
** 
** Made by david tran
** Login   <tran_0@epitech.net>
** 
** Started on  Thu May 15 01:01:29 2014 david tran
** Last update Wed May 21 12:48:38 2014 david tran
*/

#include "42sh.h"
#include "my.h"

int		add_redir_final(t_bin *bin, int fd)
{
  t_bin		*tmp;

  tmp = bin->head;
  while (tmp->left)
    tmp = tmp->left;
  if (my_put_redir(tmp, fd) == -1)
    return (-1);
  return (EXIT_SUCCESS);
}

int		add_redir_princ(t_bin *bin, int fd, char *str)
{
  t_bin		*tmp;

  tmp = bin->head;
  while (tmp->left)
    tmp = tmp->left;
  while (tmp->right)
    tmp = tmp->right;
  if (my_put_princ(tmp, fd, str) == -1)
    return (-1);
  return (EXIT_SUCCESS);
}

int		update_op(t_bin *bin, char *op)
{
  t_bin		*tmp;

  tmp = bin->head;
  while (tmp->left)
    tmp = tmp->left;
  if (!(tmp->op = my_strdup(op)))
    return (-1);
  return (EXIT_SUCCESS);
}

int		create_nodd_pipe(t_bin *bin, char **command, char *princ)
{
  t_bin		*new;
  t_bin		*tmp;

  if (!(new = malloc(sizeof(t_bin))))
    return (EXIT_FAILURE);
  new->command = wordtabdup(command);
  if (!(new->princ = my_strdup(princ)) || !new->command)
    return (-1);
  new->op = NULL;
  new->left = NULL;
  new->right = NULL;
  tmp = bin->head;
  while (tmp->left)
    tmp = tmp->left;
  while (tmp->right)
    tmp = tmp->right;
  tmp->right = new;
  return (EXIT_SUCCESS);
}
