/*
** dochangedir.c for dochangedir in /home/tran_0/rendu/PSU_2013_minishell2
** 
** Made by david tran
** Login   <tran_0@epitech.net>
** 
** Started on  Wed Feb 12 18:29:13 2014 david tran
** Last update Sat Feb 15 10:09:48 2014 david tran
*/

#include "minishell2.h"

int	countpointpoint(char *str)
{
  int	i;
  int	j;

  i = 0;
  j = 0;
  while (str[i] != 0)
    {
      if (str[i] == '.' && str[i + 1] != 0 && str[i + 1] == '.' &&
	  str[i + 2] != 0 && str[i + 2] == '/')
	j++;
      i++;
    }
  return (j);
}

char		*recupvar(t_data *list, char *str)
{
  t_data	*tmp;

  tmp = list->head;
  while (tmp != NULL)
    {
      if (my_strenv(tmp->data, str) == 1)
	return (cutbuffer(tmp->data));
      tmp = tmp->next;
    }
  return (NULL);
}

char	*createnewpwd(int j, char *str, char *path)
{
  char	*dest;
  int	i;

  i = my_strlen(str);
  if (path[0] == '/')
    i = 0;
  if ((dest = malloc((i + my_strlen(path) - (3 * j) + 2) *\
		     sizeof(char))) == NULL)
    return (NULL);
  if (path[0] != '/')
    {
      i = 0;
      while (str[i] != 0)
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
void	changedirenv(t_data *list, char *dest)
{
  char	*path;
  int	j;
  char	*str;

  path = recupvar(list, "PWD");
  j = countpointpoint(dest);
  if ((str = createnewpwd(j, path, dest)) == NULL)
    {
      my_putstr("Can't change PWD or OLDPWD in env\n");
      return ;
    }
  setinlist(list, my_strcat("PWD=", str));
  setinlist(list, my_strcat("OLDPWD=", path));
}

void	changedirect(t_data *list, char *dest)
{
  if (dest == NULL)
    goinghome(list);
  else if (dest[0] == '-' && dest[1] == 0)
    dirminus(list);
  else if (access(dest, F_OK) == -1)
    my_putstr("Can't access the file\n");
  else if (chdir(dest) == -1)
    my_putstr("Can't open the file\n");
  else
    changedirenv(list, dest);
}
