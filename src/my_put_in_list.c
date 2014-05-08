/*
** my_put_in_list.c for 42sh in /home/tran_0/rendu/rendugit/PSU_2013_42sh
** 
** Made by david tran
** Login   <tran_0@epitech.net>
** 
** Started on  Tue May  6 05:39:02 2014 david tran
** Last update Fri May  9 01:27:34 2014 david tran
*/

#include "42sh.h"
#include "my.h"

int	init_list(t_env *list, char **env)
{
  if ((list = malloc(sizeof(*list))) == NULL)
    return (EXIT_FAILURE);
    list->head = NULL;
    list->end = NULL;
    while (*env != NULL)
      {
	if (!(put_in_chainlist(list, my_strdup(*env))))
	  return (EXIT_FAILURE);
	env++;
      }
    return (EXIT_SUCCESS);
}

int		put_in_chainlist(t_env *list, char *env)
{
  t_env		*new;

  if (!(new = malloc(sizeof(*new))))
    return (EXIT_FAILURE);
  if (new == NULL)
    return (EXIT_FAILURE);
  new->data = env;
  new->prev = list->end;
  new->next = NULL;
  if (list->end != NULL)
    list->end->next = new;
  else
    list->head = new;
  list->end = new;
  return (EXIT_SUCCESS);
}
