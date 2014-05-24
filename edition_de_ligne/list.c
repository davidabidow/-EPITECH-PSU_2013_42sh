/*
** list.c for Pushswap in /home/lacour_a/rendu/CPE_2013_Pushswap
**
** Made by arthur lacour
** Login   <lacour_a@epitech.net>
**
** Started on  Wed Dec 25 23:43:48 2013 arthur lacour
** Last update Sat May 24 03:00:06 2014 david tran
*/

#include "42sh.h"
#include "my.h"

t_history		*my_put_in_list(t_history *list, char *name)
{
  t_history		*elem;

  elem = malloc(sizeof(*elem));
  if (elem == NULL)
    return (list);
  elem->str = name;
  elem->next = list;
  elem->previous = NULL;
  if (list != NULL)
    list->previous = elem;
  list = elem;
  return (list);
}

t_history		*my_put_in_end_list(t_history *list, char *name)
{
  t_history		*elem;

  if (list == NULL)
    list = my_put_in_list(list, name);
  else
    {
      elem = malloc(sizeof(*elem));
      if (elem == NULL)
	return (list);
      elem->str = name;
      elem->next = NULL;
      while (list->next != NULL)
	list = list->next;
      elem->previous = list;
      list->next = elem;
      while (list->previous != NULL)
	list = list->previous;
    }
  return (list);
}

t_history		*go_end_list(t_history *list)
{
  if (list != NULL)
    {
      while (list->next != NULL)
	list = list->next;
    }
  return (list);
}

void			free_list(t_history *history)
{
  if (history->next)
    free_list(history->next);
  free(history);
}
