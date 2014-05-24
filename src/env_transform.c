/*
** env_transform.c for 42sh in /home/tran_0/rendu/rendugit/PSU_2013_42sh
** 
** Made by david tran
** Login   <tran_0@epitech.net>
** 
** Started on  Fri May 23 22:38:39 2014 david tran
** Last update Fri May 23 23:12:38 2014 david tran
*/

#include "42sh.h"
#include "my.h"

int	count_env(t_env *list)
{
  int	i;
  t_env	*tmp;

  i = 0;
  tmp = list->head;
  while (tmp)
    {
      i++;
      tmp = tmp->next;
    }
  return (i);
}

char	**transform_list(t_env *list)
{
  char	**dest;
  t_env	*tmp;

  tmp = list->head;
  if (!(dest = malloc(sizeof(char *) * (count_env(list) + 1))))
    return (NULL);
  dest[0] = NULL;
  while (tmp)
    {
      if (!(dest = wordtabcat(dest, tmp->data)))
	return (NULL);
      tmp = tmp->next;
    }
  return (dest);
}
