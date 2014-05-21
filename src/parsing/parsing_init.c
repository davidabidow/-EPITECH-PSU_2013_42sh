/*
** parsing_init.c for 42sh in /home/tran_0/rendu/rendugit/PSU_2013_42sh/src
** 
** Made by david tran
** Login   <tran_0@epitech.net>
** 
** Started on  Mon May 19 01:00:50 2014 david tran
** Last update Wed May 21 13:39:23 2014 david tran
*/

#include "42sh.h"
#include "my.h"

t_pinit		go_init[] =
  {
    {0, &parsing_command},
    {1, &parsing_redir},
    {2, &parsing_built},
    {3, &parsing_ope},
  };

char	**search_path(t_env *list)
{
  char	*str;
  char	**path;

  if (!(str = recupvar(list, "PATH")))
    return (NULL);
  if (!(path = wordtab(str, ":")))
    return (NULL);
  return (path);
}

int		check_first_pars(char **src, t_bin *bin, t_pars *pars)
{
  int		tmp;

  if ((tmp = check_wone(src[pars->i], pars->path)) == -1)
    {
      my_puterr("Command not Found\n");
      return (EXIT_FAILURE);
    }
  if (go_init[tmp].func(src, bin, pars) == -1)
    return (-1);
  return (EXIT_SUCCESS);
}

int		parsing_exec(char **src, t_env *list)
{
  t_bin		*bin;
  t_pars	pars;

  pars.i = 0;
  if (!(bin = malloc(sizeof(t_bin))))
    return (-1);
  bin->head = NULL;
  if (!(pars.path = search_path(list)))
    return (-1);
  if (check_first_pars(src, bin, &pars) == -1)
    return (EXIT_FAILURE);
  return (EXIT_SUCCESS);
}
