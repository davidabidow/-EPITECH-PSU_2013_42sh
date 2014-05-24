/*
** main.c for main in /home/briard_g/rendu/PSU_2013_42sh/globbing
** 
** Made by Guillaume Briard
** Login   <briard_g@epitech.net>
** 
** Started on  Fri May 23 18:11:43 2014 Guillaume Briard
** Last update Sat May 24 12:44:13 2014 samy tabet-helal
*/

#include <unistd.h>
#include <stdlib.h>
#include <glob.h>

char		**check_glob(char *path)
{
  glob_t	globbuf;

  if (glob(path, GLOB_DOOFS | GLOB_APPEND, NULL, &globbuf)
      == GLOB_NOMATCH)
    return (NULL);
  return (pglob.gl_pathv);
}

int	main(int ac, char **av)
{

  return (EXIT_SUCCESS);
}
