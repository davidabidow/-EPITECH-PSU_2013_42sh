/*
** build_cd.c for 42sh in /home/tran_0/rendu/rendugit/PSU_2013_42sh/src
** 
** Made by david tran
** Login   <tran_0@epitech.net>
** 
** Started on  Tue May 13 00:13:56 2014 david tran
** Last update Tue May 13 01:37:47 2014 david tran
*/

#include "42sh.h"
#include "my.h"

void		goinghome(t_env *list)
{
  char		*home;
  char		*path;

  home = recupvar(list, "HOME");
  path = recupvar(list, "PWD");
  if (!home || !path)
    {
      my_putstr("Can't go home\n");
      return ;
    }
  if (access(home, F_OK) == -1)
    my_putstr("Can't access home\n");
  else if (chdir(home) == -1)
    my_putstr("Can't go to home\n");
  else
    {
      setinlist(list, my_strcat("PWD=", home));
      setinlist(list, my_strcat("OLDPWD=", path));
    }
}

int		changedirect(t_env *list, char *dest)
{
  if (!dest)
    goinghome(list);
  else if (dest[0] == ' ' && dest[1] == 0)
    dirminus(list);
  else if (access(dest, F_OK) == -1)
    my_putstr("Can't access to repository\n");
  else if (chdir(dest) == -1)
    my_putstr("Can't open the repository\n");
  else
    changedirenv(list, dest);
  return (EXIT_SUCCESS);
}
