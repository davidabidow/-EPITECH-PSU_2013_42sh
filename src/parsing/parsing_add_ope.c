/*
** parsing_add_ope.c for 42sh.h in /home/tran_0/rendu/rendugit/PSU_2013_42sh
** 
** Made by david tran
** Login   <tran_0@epitech.net>
** 
** Started on  Thu May 22 02:42:35 2014 david tran
** Last update Fri May 23 12:51:44 2014 david tran
*/

#include "42sh.h"
#include "my.h"

int		add_ope(char **src, t_bin *bin, t_pars *pars)
{
  int		tmp;

  if (src[pars->i] && my_strcmp(src[pars->i], "|") == 0)
    {
      if (create_nodd_pipe(bin, NULL, NULL) == -1)
	return (-1);
      pars->i++;
    }
  else
    {
      if (pars->i != 0 &&
	  ((tmp = check_wone(src[pars->i - 1], pars->path)) == 1 || tmp == 3))
	{
	  my_puterr("Parsing error near '");
	  my_puterr(src[pars->i]);
	  my_puterr("' \n");
	  return (-1);
	}
      if (update_op(bin, src[pars->i++]) == -1)
	return (-1);
      if (create_nodd_command(bin, NULL, NULL) == -1)
	return (-1);
    }
  return (EXIT_SUCCESS);
}
