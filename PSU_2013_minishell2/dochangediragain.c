/*
** dochangediragain.c for dochangediragain in /home/tran_0/rendu/PSU_2013_minishell2
** 
** Made by david tran
** Login   <tran_0@epitech.net>
** 
** Started on  Fri Feb 14 02:25:45 2014 david tran
** Last update Sun Mar  9 18:23:58 2014 david tran
*/

#include "minishell2.h"

char	*analizefdeb(char *dest, char *path)
{
  int	j;
  int	i;

  i = 0;
  j = 0;
  while (path[j] != 0)
    {
      if (path[j] == '.' && path[j + 1] == '.' && path[j + 2] == '/')
	{
	  while (dest[i] != '/')
	    i--;
	  i++;
	  while (path[j] != 0 && path[j] != '/')
	    j++;
	}
      else if (path[j] == '.' && path[j + 1] == '/')
	j = j + 2;
      dest[i] = path[j];
      i++;
      j++;
    }
  dest[i] = 0;
  return (dest);
}

char	*analizeall(char *dest, char *path, int i)
{
  int	j;

  j = 0;

  while (path[j] != 0)
    {
      if (path[j] == '.' && path[j + 1] == '.' &&
	  (path[j + 2] == '/' || path[j + 2] == 0))
	{
	  i--;
	  while (dest[i] != '/')
	    i--;
	  j = j + 3;
	}
      else if (path[j] == '.' && (path[j + 1] == '/' || path[j + 1] == 0))
	j = j + 2;
      dest[i] = path[j];
      i++;
      j++;
    }
  dest[i] = 0;
  return (dest);
}

void	goinghome(t_data *list)
{
  char	*home;
  char	*path;

  home = recupvar(list, "HOME");
  path = recupvar(list, "PWD");
  if (home == NULL || path == NULL)
    {
      my_putstr("Can't go home\n");
      return ;
    }
  if (access(home, F_OK) == -1)
    my_putstr("Can't access the file\n");
  else if (chdir(home) == -1)
    my_putstr("Can't open the file\n");
  else
    {
      setinlist(list, my_strcat("PWD=", home));
      setinlist(list, my_strcat("OLDPWD=", path));
    }
}

void	dirminus(t_data *list)
{
  char	*path;
  char	*oldpath;

  path = recupvar(list, "PWD");
  oldpath = recupvar(list, "OLDPWD");
  if (oldpath == NULL || path == NULL)
    {
      my_putstr("Can't go back\n");
      return ;
    }
  if (access(oldpath, F_OK) == -1)
    my_putstr("Can't access the file\n");
  else if (chdir(oldpath) == -1)
    my_putstr("Can't open the file\n");
  else
    {
      setinlist(list, my_strcat("PWD=", oldpath));
      setinlist(list, my_strcat("OLDPWD=", path));
    }
}
