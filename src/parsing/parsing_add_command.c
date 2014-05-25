/*
** parsing_add_command.c for 42sh.h in /home/tran_0/rendu/rendugit/PSU_2013_42sh
** 
** Made by david tran
** Login   <tran_0@epitech.net>
** 
** Started on  Thu May 22 02:39:48 2014 david tran
** Last update Sun May 25 21:52:52 2014 david tran
*/

#include "42sh.h"
#include "my.h"

int	add_part_command(char **src, t_bin *bin, t_pars *pars)
{
  int	tmp;

  while (src[pars->i] &&
	 ((tmp = check_wone(src[pars->i], pars->path)) == -1
	  || tmp == 0 || tmp == 2))
    if (bin_command_cat(bin, src[pars->i++]) == -1)
      return (-1);
  return (EXIT_SUCCESS);
}

int	add_full_command(char **src, t_bin *bin, t_pars *pars)
{
  int	tmp;

  if (!(pars->command = my_taballoc(sizeof(*pars->command))))
    return (-1);
  pars->command[0] = NULL;
  if (!(pars->princ = recup_princ(pars->path, src[pars->i])))
    return (-1);
  if (!(pars->command = wordtab_realloc(pars->command, 3)))
    return (-1);
  if (!(pars->command = wordtabcat(pars->command, src[pars->i++])))
    return (-1);
  while (src[pars->i] && ((tmp = check_wone(src[pars->i], pars->path)) == -1 ||
			  tmp == 0 || tmp == 2))
    {
      if (!(pars->command = wordtab_realloc(pars->command,
					    my_strstrlen(pars->command) + 2)))
	return (-1);
      if (!(pars->command = wordtabcat(pars->command, src[pars->i++])))
	return (-1);
    }
  if (update_command(bin, pars->command, pars->princ) == -1)
    return (-1);
  return (EXIT_SUCCESS);
}

int	add_command(char **src, t_bin *bin, t_pars *pars)
{
  if (check_feeded_node(bin) == EXIT_FAILURE)
    {
      if (add_full_command(src, bin, pars) == -1)
	return (-1);
    }
  else
    {
      if (add_part_command(src, bin, pars) == -1)
	return (-1);
    }
  return (EXIT_SUCCESS);
}
