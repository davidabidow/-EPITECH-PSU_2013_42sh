/*
** search_builtin.c for 42sh in /home/tran_0/rendu/rendugit/PSU_2013_42sh/src
** 
** Made by david tran
** Login   <tran_0@epitech.net>
** 
** Started on  Mon May 12 02:14:50 2014 david tran
** Last update Mon May 12 23:22:37 2014 david tran
*/

#include "42sh"
#include "my.h"

int		fill_struct_builtin(t_buin *builtin)
{
  builtin[0].name = "env";
  builtin[1].name = "setenv";
  builtin[2].name = "cd";
  builtin[3].name = "unsetenv";
  builtin[4].name = "echo";
  builtin[0].func = &my_affchain;
  builtin[1].func = &setinlist;
  builtin[2].func = &changedirect;
  builtin[3].func = &supplist;
  builtin[4].func = &echo_func;
}

int	search_builtin(char *buffer, t_env *list, char **dest, t_buin *built)
{
  int	i;

  i = 0;
  while (built[i])
    {
      if (my_strcmp(built[i].name, buffer) == 0)
	{
	  if (built[i].func(list, dest) == -1)
	    return (-1);
	  return (EXIT_SUCCESS);
	}
      i++;
    }
  return (EXIT_FAILURE);
}

int	exit_or_nothing(char *buffer, char *second)
{
  if (buffer && my_strcmp(buffer, "\n") == 0)
    return (EXIT_SUCCESS);
  if (buffer && second && my_strcmp() == 0)
    {
      my_puterr(second);
      return (-1);
    }
  return (EXIT_FAILURE);
}
