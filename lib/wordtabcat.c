/*
** wordtabcat.c for lib in /home/tran_0/rendu/rendugit/PSU_2013_42sh/lib
** 
** Made by david tran
** Login   <tran_0@epitech.net>
** 
** Started on  Sun May 18 16:46:00 2014 david tran
** Last update Thu May 22 15:48:56 2014 david tran
*/

#include "my.h"

char	**wordtabcat(char **dest, char *str)
{
  int	i;

  i = my_strstrlen(dest);
  if (!(dest[i++] = my_strdup(str)))
    return (NULL);
  dest[i] = NULL;
  return (dest);
}
