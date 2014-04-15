/*
** my_putstr.c for my_putstr in /home/tran_0/rendu/PSU_2013_minishell2
** 
** Made by david tran
** Login   <tran_0@epitech.net>
** 
** Started on  Thu Jan 23 14:42:29 2014 david tran
** Last update Sun Mar  9 20:02:15 2014 david tran
*/

#include "minishell2.h"

void	my_putstr(char *str)
{
  write(1, str, my_strlen(str));
}

int	my_strstrlen(char **path)
{
  int	i;

  i = 0;
  while (path[i] != NULL)
    i++;
  return (i);
}

char	*my_strcatslash(char *dest, char *src)
{
  int	i;
  int	j;
  char	*str;

  j = 0;
  i = 0;
  if ((str = malloc((my_strlen(dest) + my_strlen(src) + 3)
		    * sizeof(char))) == NULL)
    return (NULL);
  while (dest[i] != 0)
    {
      str[i] = dest[i];
      i++;
    }
  str[i++] = '/';
  while (src[j] != 0)
    {
      str[i] = src[j];
      j++;
      i++;
    }
  str[i] = 0;
  return (str);
}

char		*my_searchinchain(t_data *list, char *str)
{
  t_data	*tmp;

  tmp = list->head;
  while (tmp != NULL)
    {
      if (my_strenv(tmp->data, str) == 1)
	return (my_strdup(tmp->data));
      tmp = tmp->next;
    }
  return (NULL);
}

char		*searchvar(char *str)
{
  int		i;
  int		j;
  char		*dest;

  i = 0;
  j = 0;
  if (str == NULL)
    return (NULL);
  while (str[i] != '=')
    {
      if (str[i] == 0)
	return (NULL);
      i++;
    }
  if ((dest = malloc((i + 1) * sizeof (*dest))) == NULL)
    return (NULL);
  while (j < i)
    {
      dest[j] = str[j];
      j++;
    }
  dest[j] = 0;
  return (dest);
}
