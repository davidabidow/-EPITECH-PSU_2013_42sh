/*
** parsing_built.c for 42sh in /home/tran_0/rendu/rendugit/PSU_2013_42sh/src
** 
** Made by david tran
** Login   <tran_0@epitech.net>
** 
** Started on  Tue May 20 15:43:48 2014 david tran
** Last update Sat May 24 16:45:55 2014 david tran
*/

#include "42sh.h"
#include "my.h"

int	parsing_built(char **src, t_bin *bin, t_pars *pars)
{
  int	tmp;

  if (!(pars->command = my_taballoc(sizeof(*pars->command) + 1)))
    return (-1);
  pars->command[0] = NULL;
  if (!(pars->command = wordtab_realloc(pars->command, 2)))
    return (-1);
  if (!(pars->command = wordtabcat(pars->command, src[pars->i++])))
    return (-1);
  while (src[pars->i] && ((tmp = check_wone(src[pars->i], pars->path)) == -1 ||
			  tmp == 0 || tmp == 2))
    {
      if (!(pars->command = wordtab_realloc(pars->command,
					    my_strstrlen(pars->command) + 2)))
	return (-1);
      if (!(pars->command = wordtabcat(pars->command, src[(pars->i)++])))
	return (-1);
    }
  if (create_nodd_command(bin, pars->command, pars->princ) == -1)
    return (-1);
  return (EXIT_SUCCESS);
}
