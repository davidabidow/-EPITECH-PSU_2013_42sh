/*
** tab_wordtab.c for lib in /home/tran_0/rendu/rendugit/PSU_2013_42sh
** 
** Made by david tran
** Login   <tran_0@epitech.net>
** 
** Started on  Fri May  9 01:03:38 2014 david tran
** Last update Fri May  9 01:18:33 2014 david tran
*/

#include "42sh.h"
#include "my.h"

char	**tab_wordtab(char **src, int min, int max)
{
  char	**dest;
  int	i;

  i = 0;
  if (!(dest = malloc(sizeof(*dest) * (max - min + 1))))
    return (NULL);
  while (src[min] && min < max)
    {
      if (!(dest[i] = malloc(sizeof(*dest) * (my_strlen(src[min]) + 1))))
	return (NULL);
      my_strcpy(dest[i], src[min]);
      i++;
      min += 1;
    }
  dest[i] = NULL;
  return (dest);
}
