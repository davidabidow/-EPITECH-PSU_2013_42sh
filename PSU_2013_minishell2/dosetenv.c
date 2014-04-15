/*
** dosetenv.c for dosetenv in /home/tran_0/rendu/PSU_2013_minishell2
** 
** Made by david tran
** Login   <tran_0@epitech.net>
** 
** Started on  Wed Feb 12 13:38:19 2014 david tran
** Last update Sun Mar  9 20:40:49 2014 david tran
*/

#include "minishell2.h"

char		*setinend(t_data *list, char *dest, char *str)
{
  if ((str = searchvar(dest)) == NULL || dest == NULL)
    {
      my_putstr("Could not Set in Env\n");
      return (NULL);
    }
  if (my_countchain(*list) == 0)
    {
      put_in_chainlist(list, dest);
      return (NULL);
    }
  return (str);
}

void		setinlist(t_data *list, char *dest)
{
  t_data	*tmp;
  char		*str;

  tmp = list->head;
  str = NULL;
  if ((str = setinend(list, dest, str)) == NULL)
    return ;
  while (tmp != NULL)
    {
      if (my_strenv(tmp->data, str) == 0)
	tmp = tmp->next;
      else
	{
	  list = tmp;
	  list->data = dest;
	  return ;
	}
    }
  put_in_chainlist(list, dest);
}

void		freelist(t_data *list)
{
  t_data	*tmp;
  t_data	*tmfr;

  tmp = list->head;
  tmfr = list->head;
  while (tmp && tmp != list->end)
    {
      tmfr = tmp;
      tmp = tmp->next;
      free(tmfr->data);
      free(tmfr);
    }
  free(list);
}
