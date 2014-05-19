/*
** search_builtin.c for 42sh in /home/tran_0/rendu/rendugit/PSU_2013_42sh/src
** 
** Made by david tran
** Login   <tran_0@epitech.net>
** 
** Started on  Mon May 12 02:14:50 2014 david tran
** Last update Mon May 19 01:33:29 2014 david tran
*/

#include "42sh.h"
#include "my.h"

t_buin		built[] =
  {
    {"env", &my_affchain},
    {"setenv", &setinlist},
    {"cd", &changedirect},
    {"unsetenv", &supplist},
    /* {"echo", &echo_func}, */
  };

int	search_builtin(char *buffer, t_env *list, char **dest, t_buin *built)
{
  int	i;

  i = 0;
  while (built[i].name)
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
  if (buffer && my_strcmp(buffer, "\0") == 0)
    return (EXIT_SUCCESS);
  if (buffer && my_strcmp(buffer, "exit") == 0)
    {
      if (second && !my_isnumb(second))
	{
	  my_putstr("Exit parameter isn't a number\n");
	  return (EXIT_SUCCESS);
	}
      if (second)
	my_puterr(second);
      return (-1);
    }
  return (EXIT_FAILURE);
}
