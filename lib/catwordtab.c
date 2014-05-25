/*
** catwordtab.c for lib in /home/tran_0/rendu/rendugit/PSU_2013_42sh
** 
** Made by david tran
** Login   <tran_0@epitech.net>
** 
** Started on  Sun May 25 04:01:30 2014 david tran
** Last update Sun May 25 21:01:16 2014 david tran
*/

#include "my.h"

char	**catwordtab(char **dest, char **src, int x)
{
  int	i;
  int	j;
  int	len;
  char	**go;

  len = my_strstrlen(dest);
  j = 0;
  i = 0;
  if (!(go = my_taballoc((len + my_strstrlen(src) + 2) * sizeof(char *))))
    return (NULL);
  while (i < x)
    {
      if (!(go[i] = my_strdup(dest[i])))
	return (NULL);
      i++;
    }
  len = i + 1;
  while (src[j])
    if (!(go[i++] = my_strdup(src[j++])))
      return (NULL);
  while (dest[len])
    if (!(go[i++] = my_strdup(dest[len++])))
      return (NULL);
  go[i] = NULL;
  return (go);
}
