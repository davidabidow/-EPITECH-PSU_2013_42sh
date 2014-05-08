/*
** my_strdup.c<2> for lib in /home/tran_0/rendu/rendugit/PSU_2013_42sh/lib
** 
** Made by david tran
** Login   <tran_0@epitech.net>
** 
** Started on  Tue May  6 06:12:27 2014 david tran
** Last update Wed May  7 18:08:21 2014 david tran
*/

#include "my.h"

char	*my_strndup(char *str, int len)
{
  char	*dest;
  int	j;

  if ((dest = malloc(sizeof(char) * (len + 1))) == NULL)
    return (NULL);
  j = 0;
  while (str[j] && j < len)
    {
      dest[j] = str[j];
      j++;
    }
  dest[len] = 0;
  return (dest);
}

char	*my_strdup(char *str)
{
  int	i;
  char	*dest;
  int	j;

  i = my_strlen(str);
  if ((dest = malloc(sizeof(char) * (i + 1))) == NULL)
    return (NULL);
  dest[i] = 0;
  j = 0;
  while (j < i)
    {
      dest[j] = str[j];
      j++;
    }
  return (dest);
}
