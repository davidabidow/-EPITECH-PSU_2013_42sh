/*
** infinite_pipe_other.c for 42sh in /home/tran_0/rendu/rendugit/PSU_2013_42sh
** 
** Made by david tran
** Login   <tran_0@epitech.net>
** 
** Started on  Sun May 25 19:41:09 2014 david tran
** Last update Sun May 25 20:44:47 2014 david tran
*/

#include "42sh.h"
#include "my.h"

int	check_globbing(t_bin *bin)
{
  int	i;
  char	**src;

  i = 0;
  if (!bin->command || !bin->command[i++])
    return (EXIT_FAILURE);
  while (bin->command[i])
    {
      if (check_star(bin->command[i]) == EXIT_SUCCESS)
	{
	  if (!(src = check_glob(bin->command[i])))
	    return (-1);
	  if (!(bin->command = catwordtab(bin->command, src, i)))
	    return (-1);
	}
      i++;
    }
  return (EXIT_SUCCESS);
}

int	son_error(t_bin *bin, char **list, t_exec *execa)
{
  if (go_son(bin, list, execa) == -1)
    {
      my_putstr("Command not found : ");
      my_putstr(bin->princ);
      my_putstr("\n");
      woexit = EXIT_FAILURE;
    }
  return (-1);
}
