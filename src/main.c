/*
** main.c for 42sh in /home/tran_0/rendu/rendugit/PSU_2013_42sh/src
** 
** Made by david tran
** Login   <tran_0@epitech.net>
** 
** Started on  Mon May  5 18:48:27 2014 david tran
** Last update Wed May 21 15:21:14 2014 david tran
*/

#include "42sh.h"
#include "my.h"

int		main(int ac __attribute__((unused)), char **av
		     __attribute__((unused)), char **env)
{
  t_env		*list;

  list = NULL;
  if ((list = malloc(sizeof(*list))) == NULL)
    return (EXIT_FAILURE);
  list->head = NULL;
  list->end = NULL;
  signal(SIGINT, dontquit);
  if (init_list(list, env) == EXIT_FAILURE)
    return (EXIT_FAILURE);
  infiniteloop(list);
  free_env_list(list);
  return (EXIT_SUCCESS);
}
