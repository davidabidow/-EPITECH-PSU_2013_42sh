/*
** catwordtab.c for lib in /home/tran_0/rendu/rendugit/PSU_2013_42sh
** 
** Made by david tran
** Login   <tran_0@epitech.net>
** 
** Started on  Sun May 25 04:01:30 2014 david tran
** Last update Sun May 25 04:13:06 2014 david tran
*/

#include "my.h"

char	**catwordtab(char **dest, char **src)
{
  int	i;
  int	j;

  i = my_strstrlen(dest);
  j = 0;
  while (src[j])
    if (!(dest[i++] = my_strdup(src[j++])))
      return (NULL);
  return (dest);
}
