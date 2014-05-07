/*
** wortab.c for lib in /home/tran_0/rendu/rendugit/PSU_2013_42sh
** 
** Made by david tran
** Login   <tran_0@epitech.net>
** 
** Started on  Wed May  7 00:48:32 2014 david tran
** Last update Wed May  7 02:45:22 2014 david tran
*/

#include "my.h"

char	**wortab(char *str, char *pat)
{
  int	i;
  int	j;
  int	k;
  int	l;
  char	**dest;

  i = 0;
  k = 0;
  j = count_separ(str, pat);
  if ((dest = malloc(sizeof(*dest) * j + 1)) == NULL)
    return (NULL);
  while (str[k])
    {
      l = k;
      while (str[l] && str[l] != ' ')
	l++;
      if ((dest[i++] = my_strndup(&str[k], l - k)) == NULL)
	return (NULL);
      k = l;
    }
  return (dest);
}
