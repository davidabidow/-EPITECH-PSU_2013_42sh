/*
** parsing_check_wone.c for 42sh in /home/tran_0/rendu/rendugit/PSU_2013_42sh/src
** 
** Made by david tran
** Login   <tran_0@epitech.net>
** 
** Started on  Tue May 20 16:58:56 2014 david tran
** Last update Wed May 21 13:20:12 2014 david tran
*/

#include "42sh.h"
#include "my.h"

int	check_wone_other(char *str, char **path)
{
  char	*tmp;
  int	i;

  i = 0;
  while (operate[i].oper)
    if (my_strcmp(operate[i++].oper, str) == 0)
      return (3);
  if (access(str, F_OK) == 0)
    return (0);
  i = 0;
  while (path[i])
    {
      tmp = my_strcatslash(path[i++], str);
      if (access(tmp, F_OK) == 0)
	return (0);
    }
  return (-1);
}

int	check_wone(char *str, char **path)
{
  int	i;

  i = 0;
  if (my_strcmp(str, "<<") == 0)
    return (1);
  while (redir[i].name)
    if (my_strcmp(redir[i++].name, str) == 0)
      return (1);
  i = 0;
  while (built[i].name)
    if (my_strcmp(built[i++].name, str) == 0)
      return (2);
  return (check_wone_other(str, path));
}
