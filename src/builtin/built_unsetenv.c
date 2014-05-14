/*
** built_unsetenv.c for 42sh in /home/tran_0/rendu/rendugit/PSU_2013_42sh/src
** 
** Made by david tran
** Login   <tran_0@epitech.net>
** 
** Started on  Mon May 12 23:52:26 2014 david tran
** Last update Tue May 13 22:58:58 2014 david tran
*/

#include "42sh.h"
#include "my.h"

int		suppend(t_env *list, char *str, t_env *current, t_env *tmp)
{
  t_env		*fnext;

  if (!str || !list)
    return (EXIT_FAILURE);
  if (my_strenv(tmp->data, str))
    {
      current = list->head;
      fnext = list->head->next;
      list->head = fnext;
      free(current->data);
      free(current);
      return (EXIT_SUCCESS);
    }
  return (EXIT_FAILURE);
}

void		suppother(t_env *list, t_env *tmp, t_env *current)
{
  list = tmp;
  if (current != list->end)
    {
      list->next = current->next;
      free(current->data);
      free(current);
    }
  else if (current == list->end)
    {
      list->end->prev->next = NULL;
      list->end = list->end->prev;
      free(current->data);
      free(current);
    }
}

int		supplist(t_env *list, char *str)
{
  t_env		*tmp;
  t_env		*current;

  tmp = list->head;
  current = list->head;
  if (suppend(list, str, current, tmp))
    return (EXIT_SUCCESS);
  while (current)
    {
      if (my_strenv(current->data, str))
	{
	  tmp = tmp->next;
	  current = current->next;
	}
      else
	{
	  suppother(list, tmp, current);
	  return (EXIT_SUCCESS);
	}
    }
  return (EXIT_FAILURE);
}
