/*
** built_cd_other.c for 42sh in /home/tran_0/rendu/rendugit/PSU_2013_42sh/src/builtin
** 
** Made by david tran
** Login   <tran_0@epitech.net>
** 
** Started on  Tue May 13 13:57:12 2014 david tran
** Last update Tue May 13 22:57:23 2014 david tran
*/

#include "42sh.h"
#include "my.h"

char	*analizefdeb(char *dest, char *path)
{
  int	i;
  int	j;

  i = 0;
  j = 0;
  while (path[j])
    {
      if (path[j] == '.' && path[j + 1] == '.' && path[j + 2] == '/')
	{
	  while (dest[i] && dest[i] != '/')
	    i--;
	  i++;
	  while (path[j] && path[j] != '/')
	    j++;
	}
      else if (path[j] == '.' && path[j + 1] && path[j + 1] == '/')
	j += 2;
      dest[i++] = path[j++];
    }
  dest[i] = 0;
  return (dest);
}

char	*analizeall(char *dest, char *path, int i)
{
  int	j;

  j = 0;
  while (path[j])
    {
      if (path[j] == '.' && path[j + 1] && path[j + 1] == '.' &&
	  (!path[j + 2] || path[j + 2] == '/'))
	{
	  --i;
	  while (dest[i] != '/')
	    --i;
	  j += 3;
	}
      else if (path[j] == '.' && (!path[j + 1] || path[j + 1] == '/'))
	j += 2;
      dest[i++] = path[j++];
    }
  dest[i] = 0;
  return (dest);
}

int	countpointpoint(char *str)
{
  int	i;
  int	j;

  i = 0;
  j = 0;
  while (str[i])
    {
      if (str[i] == '.' && str[i + 1] && str[i + 1] == '.' &&
	  str[i + 2] && str[i + 2] == '/')
	j++;
      i++;
    }
  return (j);
}

char	*createnewpwd(int j, char *str, char *path)
{
  char	*dest;
  int	i;

  i = my_strlen(str);
  if (path[0] == '/')
    i = 0;
  if (!(dest = malloc((i + my_strlen(path) - (3 * j) + 2) * sizeof(char))))
    return (NULL);
  if (path[0] != '/')
    {
      i = 0;
      while (str[i])
	{
	  dest[i] = str[i];
	  i++;
	}
      dest[i] = 0;
    }
  if (path[0] == '/')
    dest = analizefdeb(dest, path);
  else
    dest = analizeall(dest, path, i);
  return (dest);
}
