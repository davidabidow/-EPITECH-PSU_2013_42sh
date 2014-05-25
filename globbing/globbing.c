/*
** main.c for main in /home/briard_g/rendu/PSU_2013_42sh/globbing
** 
** Made by Guillaume Briard
** Login   <briard_g@epitech.net>
** 
** Started on  Fri May 23 18:11:43 2014 Guillaume Briard
** Last update Sun May 25 21:09:34 2014 david tran
*/

#include "42sh.h"
#include "my.h"

int		check_star(char *str)
{
  int		i;

  i = 0;
  while (str && str[i])
    {
      if (str[i] == '*')
	return (EXIT_SUCCESS);
      i++;
    }
  return (EXIT_FAILURE);
}

char		**check_glob(char *path)
{
  glob_t	globbuf;
  int		tmp;
  char		**dup;

  globbuf.gl_pathv = NULL;
  if ((tmp = glob(path, 0, NULL, &globbuf)) != 0)
    {
      my_putstr("Globing error / No matches\n");
      return (NULL);
    }
  if (!(dup = wordtabdup(globbuf.gl_pathv)))
    return (NULL);
  globfree(&globbuf);
  return (dup);
}
