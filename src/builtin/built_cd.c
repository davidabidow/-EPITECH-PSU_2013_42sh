/*
** build_cd.c for 42sh in /home/tran_0/rendu/rendugit/PSU_2013_42sh/src
** 
** Made by david tran
** Login   <tran_0@epitech.net>
** 
** Started on  Tue May 13 00:13:56 2014 david tran
** Last update Sat May 24 19:01:49 2014 david tran
*/

#include "42sh.h"
#include "my.h"

void		changedirenv(t_env *list, char *dest)
{
  char		*path;
  int		j;
  char		*str;
  char		*pwd;
  char		*oldpwd;

  if (!(pwd = my_strdup("PWD=")) || !(oldpwd = my_strdup("OLDPWD=")) ||
      !(path = recupvar(list, "PWD")))
    {
      my_putstr("Can't set PWD/OLDPWD");
      return ;
    }
  j = countpointpoint(dest);
  if (!(str = createnewpwd(j, path, dest)))
    {
      my_putstr("Can't change PWD | OLDPWD in env\n");
      return ;
    }
  if (!(pwd = my_realloc(pwd, my_strlen(str) + 5)) ||
      !(oldpwd = my_realloc(oldpwd, my_strlen(path) + 8)))
    return ;
  if (setinlist_cd(list, my_strcat(pwd, str)))
    my_putstr("Can't set PWD\n");
  if (setinlist_cd(list, my_strcat(oldpwd, path)))
    my_putstr("Can't set OLDPWD\n");
}

void		dirminus(t_env *list)
{
  char		*path;
  char		*oldpath;
  char		*pwd;
  char		*oldpwd;

  if (!(path = recupvar(list, "PWD")) || !(oldpath = recupvar(list, "OLDPWD"))
      || !(pwd = my_strdup("PWD=")) || !(oldpwd = my_strdup("OLDPWD=")))
    {
      my_putstr("Can't go home\n");
      return ;
    }
  if (!(pwd = my_realloc(pwd, my_strlen(path) + 5)) ||
      !(oldpwd = my_realloc(oldpwd, my_strlen(oldpath) + 8)))
    return ;
  if (access(oldpath, F_OK) == -1)
    my_putstr("Can't access the repository\n");
  else if (chdir(oldpath) == -1)
    my_putstr("Can't open the repository\n");
  else
    {
      if (setinlist_cd(list, my_strcat(pwd, path)))
	my_putstr("Can't set PWD\n");
      if (setinlist_cd(list, my_strcat(oldpwd, oldpath)))
	my_putstr("Can't set OLDPWD\n");
    }
}

void		goinghome(t_env *list)
{
  char		*home;
  char		*path;
  char		*pwd;
  char		*oldpwd;

  if (!(home = recupvar(list, "HOME")) || !(path = recupvar(list, "PWD"))
      || !(pwd = my_strdup("PWD=")) || !(oldpwd = my_strdup("OLDPWD=")))
    {
      my_putstr("Can't go home\n");
      return ;
    }
  if (!(pwd = my_realloc(pwd, my_strlen(home) + 5)) ||
      !(oldpwd = my_realloc(oldpwd, my_strlen(path) + 8)))
    return ;
  if (access(home, F_OK) == -1)
    my_putstr("Can't access home\n");
  else if (chdir(home) == -1)
    my_putstr("Can't go to home\n");
  else
    {
      if (setinlist_cd(list, my_strcat(pwd, home)) == EXIT_FAILURE)
	my_putstr("Can't set PWD\n");
      if (setinlist_cd(list, my_strcat(oldpwd, path)) == EXIT_FAILURE)
	my_putstr("Can't set OLDPWD\n");
    }
}

int		changedirect(t_env *list, char **dest)
{
  if (!dest[1])
    goinghome(list);
  else if (dest[1][0] && dest[1][1] && dest[1][0] == '-' && dest[1][1] == 0)
    dirminus(list);
  else if (access(dest[1], F_OK) == -1)
    my_putstr("Can't access to repository\n");
  else if (chdir(dest[1]) == -1)
    my_putstr("Can't open the repository\n");
  else
    changedirenv(list, dest[1]);
  return (EXIT_SUCCESS);
}
