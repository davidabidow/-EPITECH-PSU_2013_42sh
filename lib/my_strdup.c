/*
** my_strdup.c<2> for lib in /home/tran_0/rendu/rendugit/PSU_2013_42sh/lib
** 
** Made by david tran
** Login   <tran_0@epitech.net>
** 
** Started on  Tue May  6 06:12:27 2014 david tran
** Last update Tue May 20 23:49:48 2014 david tran
*/

#include "my.h"

char	*my_strndup(char *str, int len)
{
  char	*dest;
  int	j;

  if ((dest = my_xmalloc(sizeof(char) * (len + 1))) == NULL)
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

  i = my_strlen(str);
  if (!(dest = my_xmalloc(sizeof(char) * (i + 1))))
    return (NULL);
  my_strcpy(dest, str);
  return (dest);
}
