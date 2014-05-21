/*
** parsing_init.c for 42sh in /home/tran_0/rendu/rendugit/PSU_2013_42sh/src
** 
** Made by david tran
** Login   <tran_0@epitech.net>
** 
** Started on  Mon May 19 01:00:50 2014 david tran
** Last update Wed May 21 16:27:55 2014 david tran
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

/* t_pinit		go_pars[] = */
/*   { */
/*     {0, &add_command}, */
/*     {1, &add_redir}, */
/*     {2, &add_built}, */
/*     {3, &add_ope}, */
/*   }; */

char	**search_path(t_env *list)
{
  char	*str;
  char	**path;

  if (!(str = recupvar(list, "PATH")))
    {
      my_putstr("No PATH found, Can't exec\n");
      return (NULL);
    }
  if (!(path = wordtab(str, ":")))
    return (NULL);
  return (path);
}

int		finish_parsing(char **src, t_bin *bin, t_pars *pars)
{
  /* int		tmp; */

  /* while (src[pars->i]) */
  /*   { */
  /*     if ((tmp = check_wone(src[pars->i], pars->path)) == -1 && check_nodes == EXIT_FAILURE) */
  /* 	return (-1); */
  /*   } */
}

int		check_first_pars(char **src, t_bin *bin, t_pars *pars)
{
  int		tmp;

  if ((tmp = check_wone(src[pars->i], pars->path)) == -1)
    {
      my_puterr("Command not Found: ");
      my_puterr(src[pars->i]);
      my_puterr("\n");
      while (src[pars->i] && my_strcmp(src[pars->i], "||") != 0)
	pars->i++;
      if (!src[pars->i])
	return (EXIT_FAILURE);
    }
  else if (go_init[tmp].func(src, bin, pars) == -1)
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
    return (EXIT_FAILURE);
  if (check_first_pars(src, bin, &pars) == -1)
    return (EXIT_FAILURE);
  return (EXIT_SUCCESS);
}
