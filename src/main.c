/*
** main.c for 42sh in /home/tran_0/rendu/rendugit/PSU_2013_42sh/src
** 
** Made by david tran
** Login   <tran_0@epitech.net>
** 
** Started on  Mon May  5 18:48:27 2014 david tran
** Last update Tue May  6 05:59:01 2014 david tran
*/

#include "42sh.h"

int		main(int ac __attribute__((unused)), char **av
		     __attribute__((unused)), char **env)
{
  t_env		*list;

  signal(SIGINT, dontquit);
  init_list(list, env);
  return (EXIT_SUCCESS);
}
