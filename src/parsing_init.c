/*
** parsing_init.c for 42sh in /home/tran_0/rendu/rendugit/PSU_2013_42sh/src
** 
** Made by david tran
** Login   <tran_0@epitech.net>
** 
** Started on  Mon May 19 01:00:50 2014 david tran
** Last update Mon May 19 17:10:11 2014 david tran
*/

#include "42sh.h"
#include "my.h"

int	check_wone_other(char *str)
{
  int	i;

  i = 0;
  while (built[i].name)
    if (my_strcmp(built[i++].name, str) == 0)
      return (2);
  i = 0;
  while (oper[i].oper)
    if (my_strcmp(oper[i++].oper, str) == 0)
      return (3);
  return (0);
}

int	check_wone(char *str, char **path)
{
  int	i;
  char	*tmp;

  i = 0;
  if (access(str, F_OK) == 0)
    return (0);
  while (path[i])
    {
      tmp = my_strcatslash(path[i++], str);
      if (access(tmp, F_OK) == 0)
	return (0);
    }
  i = 0;
  while (redir[i].redir)
    if (my_strcmp(redir[i++].redir, str) == 0)
      return (1);
  if ((i = check_wone_other(str)) == 2)
    return (2);
  else if (i == 3)
    return (3);
  return (-1);
}

char	**search_path(t_env *list)
{
  char	*str;
  char	**path;

  if (!(str = recupvar(list)))
    return (NULL);
  if (!(path = wordtab(str, ":")))
    return (NULL);
  return (path);
}

int		parsing_exec(char **src, t_env *list)
{
  int		tmp;
  t_bin		*bin;
  t_pars	pars;

  pars.i = 0;
  if (!(bin = malloc(sizeof(t_bin))))
    return (-1);
  if (!(pars.path = search_path(list)))
    return (-1);
  while (src[pars.i])
    {
      if ((pars.tmp = check_wone(src[pars.i], pars.path)) == -1)
	{
	  my_puterr("Parsing error\n");
	  return (-1);
	}
      else if (tmp == 0)
	parsing_command(src, bin, &pars);
      else if (tmp == 1)
	;
      else if (tmp == 2)
	;
      else if (tmp == 3)
	;
      else if (tmp == 4)
	;
      pars.i++;
    }
  return (EXIT_SUCCESS);
}
