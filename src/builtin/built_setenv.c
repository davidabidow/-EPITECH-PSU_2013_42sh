/*
** built_setenv.c for 42sh in /home/tran_0/rendu/rendugit/PSU_2013_42sh/src
** 
** Made by david tran
** Login   <tran_0@epitech.net>
** 
** Started on  Mon May 12 15:13:37 2014 david tran
** Last update Mon May 12 22:26:34 2014 david tran
*/

#include "42sh"
#include "my.h"

int	setinend(t_env *list, char *dest, char **str)
{
  if (!(*str = searchvar(dest)) || !dest)
    {
      my_putstr("Could not Set in Env\n");
      return (-1);
    }
  if (my_countchain(*list) == 0)
    {
      if (!(put_in_chainlist(list, dest)))
	return (-1);
      return (EXIT_SUCCESS);
    }
  return (EXIT_FAILURE);
}

int	setinlist(t_env *list, char *dest)
{
  t_env	*tmp;
  char	*str;
  int	i;

  tmp = list->head;
  str = NULL;
  if ((i = setinend(list, dest, &str)) == -1)
    return (EXIT_FAILURE);
  if (i == 0)
    return (EXIT_SUCCESS);
  while (tmp)
    {
      if (my_strenv(tmp->data, str) == EXIT_FAILURE)
	tmp = tmp->next;
      else
	{
	  list = tmp;
	  list->data = dest;
	  return (EXIT_SUCCESS);
	}
    }
  if (!put_in_chainlist(list, dest))
    return (EXIT_FAILURE);
  return (EXIT_SUCCESS);
}
