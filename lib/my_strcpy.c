/*
** my_strcpy.c<2> for lib in /home/tran_0/rendu/rendugit/PSU_2013_42sh/src
** 
** Made by david tran
** Login   <tran_0@epitech.net>
** 
** Started on  Tue May  6 15:36:35 2014 david tran
** Last update Wed May  7 02:44:22 2014 david tran
*/

#include "my.h"

char	*my_strncpy(char *dest, char *src, int len)
{
  int	i;

  i = 0;
  while (src[i] && i < len)
    {
      dest[i] = src[i];
      i++;
    }
  dest[i] = 0;
  return (dest);
}

char	*my_strcpy(char *dest, char *src)
{
  int	i;

  i = 0;
  while (src[i])
    {
      dest[i] = src[i];
      i++;
    }
  dest[i] = 0;
  return (dest);
}
