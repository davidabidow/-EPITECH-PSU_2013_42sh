/*
** wordtabdup.c for wordtabdup.c in /home/tran_0/rendu/rendugit/PSU_2013_42sh/lib
** 
** Made by david tran
** Login   <tran_0@epitech.net>
** 
** Started on  Sun May 18 22:26:36 2014 david tran
** Last update Sun May 18 22:49:38 2014 david tran
*/

#include "my.h"

char	**wordtabdup(char **str)
{
  int	i;
  char	**dest;

  i = my_strstrlen(str);
  if (!(dest = malloc(sizeof(*dest) * (i + 1))))
    return (NULL);
  dest = wordtabcpy(dest, str);
  return (dest);
}
