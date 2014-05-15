/*
** search_redir.c for 42sh in /home/tran_0/rendu/rendugit/PSU_2013_42sh/src/redir
** 
** Made by david tran
** Login   <tran_0@epitech.net>
** 
** Started on  Thu May 15 01:57:23 2014 david tran
** Last update Thu May 15 16:26:20 2014 david tran
*/

#include "42sh.h"
#include "my.h"

t_redir		redir[] =
  {
    {">>", &double_normal},
    {"<<", &double_invert},
    {"<", &simple_invert},
    {">", simple_normal},
  };

int	search_redir(char *str, char *file)
{
  int	i;
  int	fd;

  i = 0;
  while (redir[i].redir)
    {
      if (my_strcmp(redir[i].redir] == 0)
	{
	  if ((fd = redir[i].func(file)) == -1)
	    return (EXIT_FAILURE);
	  return (EXIT_SUCCESS);
	}
      i++;
    }
  return (EXIT_FAILURE);
}
