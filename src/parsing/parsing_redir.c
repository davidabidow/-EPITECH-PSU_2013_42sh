/*
** parsing_redir.c for 42sh in /home/tran_0/rendu/rendugit/PSU_2013_42sh/src
** 
** Made by david tran
** Login   <tran_0@epitech.net>
** 
** Started on  Tue May 20 09:49:30 2014 david tran
** Last update Wed May 21 00:02:09 2014 david tran
*/

#include "42sh.h"
#include "my.h"

int		parsing_dinver(char **src, t_bin *bin, t_pars *pars)
{
  if (!(pars->princ = double_invert(src[++pars->i])))
    return (-1);
  if (add_redir_princ(bin, -1, pars->princ) == -1)
    return (-1);
  pars->i += 1;
  return (EXIT_SUCCESS);
}

int		parsing_redir(char **src, t_bin *bin, t_pars *pars)
{
  int		j;

  j = 0;
  if (create_nodd_command(bin, NULL, NULL) == -1)
    return (-1);
  if (!src[pars->i + 1])
    {
      my_putstr("Parsing error near <</>>/</>\n");
      return (-1);
    }
  if (my_strcmp(src[pars->i], "<<") == 0)
    return (parsing_dinver(src, bin, pars));
  while (redir[j].name && my_strcmp(src[pars->i], redir[j].name) != 0)
    j++;
  pars->i += 1;
  if (j == 1)
    return (add_redir_princ(bin, redir[j].func(src[pars->i++]), NULL));
  else if (j == 0 || j == 2)
    return (add_redir_final(bin, redir[j].func(src[pars->i++])));
  return (EXIT_SUCCESS);
}
