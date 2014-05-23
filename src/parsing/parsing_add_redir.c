/*
** parsing_add_redir.c for 42sh.h in /home/tran_0/rendu/rendugit/PSU_2013_42sh
** 
** Made by david tran
** Login   <tran_0@epitech.net>
** 
** Started on  Thu May 22 02:40:17 2014 david tran
** Last update Fri May 23 02:22:18 2014 david tran
*/

#include "42sh.h"
#include "my.h"

int	add_redir_checkafter(char **src, t_bin *bin, t_pars *pars)
{
  int	tmp;

  if ((tmp = check_wone(src[pars->i], pars->path)) != -1 &&
      tmp != 0 && tmp != 2)
    return (EXIT_FAILURE);
  if (add_command(src, bin, pars) == -1)
    return (-1);
  return (EXIT_SUCCESS);
}

int	add_redir_attribute(char **src, t_bin *bin, t_pars *pars, int j)
{
  char	*str;
  int	fd;

  if (j == -1)
    {
      if (!(str = double_invert(src[pars->i])))
	return (-1);
      if (add_redir_princ(bin, j, str) == -1)
	return (-1);
    }
  else
    {
      if ((fd = redir[j].func(src[pars->i])) == -1)
	return (-1);
      if (j == 1)
	{
	  if (add_redir_princ(bin, fd, NULL) == -1)
	    return (-1);
	}
      else
	if (add_redir_final(bin, fd) == -1)
	  return (-1);
    }
  return (EXIT_SUCCESS);
}

int	add_redir_next(char **src, t_bin *bin, t_pars *pars, int j)
{
  int	tmp;

  if ((tmp = check_wone(src[pars->i], pars->path)) == 1 || tmp == 3)
    {
      my_puterr("Parsing error near '");
      my_puterr(src[pars->i]);
      my_puterr("' \n");
      return (-1);
    }
  if (add_redir_attribute(src, bin, pars, j) == -1)
    return (-1);
  pars->i++;
  if (src[pars->i])
    if (add_redir_checkafter(src, bin, pars) == -1)
      return (-1);
  return (EXIT_SUCCESS);
}

int	add_redir(char **src, t_bin *bin, t_pars *pars)
{
  int	j;

  j = 0;
  while (redir[j].name && my_strcmp(src[pars->i], redir[j].name) != 0)
    j++;
  if (my_strcmp(src[pars->i], "<<") == 0)
    j = -1;
  pars->i++;
  if (!src[pars->i])
    {
      my_puterr("Parse error near </<</>>/>\n");
      return (-1);
    }
  if (add_redir_next(src, bin, pars, j) == -1)
    return (-1);
  return (EXIT_SUCCESS);
}
