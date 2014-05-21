/*
** free_env.c for 42sh in /home/tran_0/rendu/rendugit/PSU_2013_42sh
** 
** Made by david tran
** Login   <tran_0@epitech.net>
** 
** Started on  Wed May 21 15:17:12 2014 david tran
** Last update Wed May 21 15:20:54 2014 david tran
*/

#include "42sh.h"
#include "my.h"

void	free_env_list(t_env *list)
{
  t_env	*env;
  t_env *tmp;

  tmp = list->head;
  env = list->head;
  while (tmp->next)
    {
      env = tmp;
      tmp = tmp->next;
      free(env->data);
      free(env);
    }
  free(tmp->data);
  free(tmp);
}
