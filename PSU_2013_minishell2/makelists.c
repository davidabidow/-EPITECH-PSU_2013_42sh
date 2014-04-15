/*
** makelists.c for makelists in /home/tran_0/rendu/PSU_2013_minishell2
** 
** Made by david tran
** Login   <tran_0@epitech.net>
** 
** Started on  Thu Jan 23 13:44:16 2014 david tran
** Last update Mon Feb 17 20:09:38 2014 david tran
*/

#include "minishell2.h"

void		my_affchain(t_data *list)
{
  t_data	*tmp;
  int		i;

  tmp = list->head;
  i = 0;
  while (tmp && tmp != NULL)
    {
      my_putstr(tmp->data);
      my_putstr("\n");
      tmp = tmp->next;
      i++;
    }
}

void		put_in_chainlist(t_data *list, char *env)
{
  t_data	*new;

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

int		suppend(t_data *list, char *str, t_data *current, t_data *tmp)
{
  t_data	*fnext;

  if (str == NULL || list == NULL)
    return (1);
  if (my_strenv(tmp->data, str) == 1)
    {
      current = list->head;
      fnext = list->head->next;
      list->head = fnext;
      free(current->data);
      free(current);
      return (1);
    }
  return (0);
}

void		suppother(t_data *list, t_data *tmp, t_data *current)
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

void		supplist(t_data *list, char *str)
{
  t_data	*tmp;
  t_data	*current;

  tmp = list->head;
  current = list->head;
  if (suppend(list, str, current, tmp) == 1)
    return ;
  current = current->next;
  while (current != NULL)
    {
      if (my_strenv(current->data, str) == 0)
	{
	  tmp = tmp->next;
	  current = current->next;
	}
      else
	{
	  suppother(list, tmp, current);
	  return ;
	}
    }
}
