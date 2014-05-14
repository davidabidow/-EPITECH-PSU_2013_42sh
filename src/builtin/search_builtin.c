/*
** search_builtin.c for 42sh in /home/tran_0/rendu/rendugit/PSU_2013_42sh/src
** 
** Made by david tran
** Login   <tran_0@epitech.net>
** 
** Started on  Mon May 12 02:14:50 2014 david tran
** Last update Wed May 14 13:16:19 2014 david tran
*/

#include "42sh.h"
#include "my.h"

int		fill_struct_builtin(t_buin *builtin)
{
  builtin[0].name = "env";
  builtin[1].name = "setenv";
  builtin[2].name = "cd";
  builtin[3].name = "unsetenv";
  //  builtin[4].name = "echo";
  builtin[0].func = &my_affchain;
  builtin[1].func = &setinlist;
  builtin[2].func = &changedirect;
  builtin[3].func = &supplist;
  //builtin[4].func = &echo_func;
}

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
  my_putstr(buffer);
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
