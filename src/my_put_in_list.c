/*
** my_put_in_list.c for 42sh in /home/tran_0/rendu/rendugit/PSU_2013_42sh
** 
** Made by david tran
** Login   <tran_0@epitech.net>
** 
** Started on  Tue May  6 05:39:02 2014 david tran
** Last update Tue May  6 05:56:11 2014 david tran
*/

#include "42sh.h"

int	init_list(t_env *list, char **env)
{
    if ((list = malloc(sizeof(*list))) == NULL)
      return (1);
    list->head = NULL;
    list->end = NULL;
    while (*env != NULL)
      {
	put_in_chainlist(list, my_strdup(*env));
	env++;
      }
    return (0);
}

void		put_in_chainlist(t_env *list, char *env)
{
  t_env		*new;

  new = malloc(sizeof(*new));
  if (new == NULL)
    return ;
  new->data = env;
  new->prev = list->end;
  new->next = NULL;
  if (list->end != NULL)
    list->end->next = new;
  else
    list->head = new;
  list->end = new;
}
