/*
** my_strcat.c for lib in /home/tran_0/rendu/rendugit/PSU_2013_42sh/src
** 
** Made by david tran
** Login   <tran_0@epitech.net>
** 
** Started on  Tue May  6 15:20:38 2014 david tran
** Last update Fri May 23 13:55:13 2014 david tran
*/

#include "my.h"

char	*my_strcatslash(char *dest, char *src)
{
  int	i;
  int	j;
  char	*str;

  if (!(str = my_xmalloc(my_strlen(dest) + my_strlen(src) + 3)))
    return (NULL);
  i = 0;
  j = 0;
  while (dest[i])
    {
      str[i] = dest[i];
      i++;
    }
  str[i++] = '/';
  while (src[j])
    str[i++] = src[j++];
  str[i] = 0;
  return (str);
}

char	*my_strncat(char *dest, char *src, int len)
{
  int	i;
  int	j;

  i = my_strlen(dest);
  j = 0;
  while (src[j] && j < len)
    dest[i++] = src[j++];
  dest[i] = 0;
  return (dest);
}

char	*my_strcat(char *dest, char *src)
{
  int	i;
  int	j;

  i = my_strlen(dest);
  j = 0;
  while (src[j])
    dest[i++] = src[j++];
  dest[i] = 0;
  return (dest);
}
