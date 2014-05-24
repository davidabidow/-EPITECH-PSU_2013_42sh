/*
** parsing_send.c for 42sh in /home/tran_0/rendu/rendugit/PSU_2013_42sh
** 
** Made by david tran
** Login   <tran_0@epitech.net>
** 
** Started on  Fri May 23 14:21:33 2014 david tran
** Last update Sat May 24 16:27:17 2014 david tran
*/

#include "42sh.h"
#include "my.h"

int		parsing_send_find(t_bin **tmp, char **list, t_env *env)
{
  int		ret;

  if ((ret = loop_pipe(*tmp, list, env)) == -1)
    return (-1);
  if ((ret == EXIT_FAILURE && (*tmp)->op && my_strcmp((*tmp)->op, "&&") == 0))
    {
      (*tmp) = (*tmp)->left;
      while ((*tmp) && (((*tmp)->op && my_strcmp((*tmp)->op, "||") != 0)
			|| !(*tmp)->op))
	(*tmp) = (*tmp)->left;
    }
  else if (ret == EXIT_SUCCESS && (*tmp)->op && my_strcmp((*tmp)->op, "||")
	   == 0)
    {
      (*tmp) = (*tmp)->left;
      while ((*tmp) && (((*tmp)->op && my_strcmp((*tmp)->op, "&&") != 0)
			|| !(*tmp)->op))
	(*tmp) = (*tmp)->left;
    }
  else
    (*tmp) = (*tmp)->left;
  return (EXIT_SUCCESS);
}

int		parsing_send(t_bin *bin, t_env *list)
{
  t_bin		*tmp;
  char		**env;

  if (!(env = transform_list(list)))
    return (EXIT_FAILURE);
  tmp = bin->head;
  if (!tmp)
    return (EXIT_FAILURE);
  while (tmp)
    if (parsing_send_find(&tmp, env, list) == -1)
      return (-1);
  free_wordtab(env);
  return (EXIT_SUCCESS);
}
