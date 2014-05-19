/*
** built_env.c for 42sh in /home/tran_0/rendu/rendugit/PSU_2013_42sh/src
** 
** Made by david tran
** Login   <tran_0@epitech.net>
** 
** Started on  Mon May 12 15:00:04 2014 david tran
** Last update Thu May 15 18:47:14 2014 david tran
*/

#include "42sh.h"
#include "my.h"

int	my_affchain(t_env *list, char *data)
{
  t_env	*tmp;

  (void *)data;
  tmp = list->head;
  while (tmp)
    {
      my_putstr(tmp->data);
      my_putchar('\n');
      tmp = tmp->next;
    }
  return (EXIT_SUCCESS);
}
