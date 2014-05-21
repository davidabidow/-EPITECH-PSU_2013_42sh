/*
** my_realloc.c for lib in /home/tran_0/rendu/rendugit/PSU_2013_42sh/lib
** 
** Made by david tran
** Login   <tran_0@epitech.net>
** 
** Started on  Sun May 18 16:48:31 2014 david tran
** Last update Tue May 20 23:53:13 2014 david tran
*/

#include "my.h"

char	**wordtab_realloc(char **str, int len)
{
  char	**dest;

  if (!(dest = my_taballoc(sizeof(*dest) * len + 1)))
    return (NULL);
  dest = wordtabcpy(dest, str);
  free_wordtab(str);
  return (dest);
}

char	*my_realloc(char *str, int len)
{
  char	*dest;

  if (!(dest = my_xmalloc(len + 1)))
    return (NULL);
  dest = my_strcpy(dest, str);
  free(str);
  return (dest);
}
