/*
** wordtabcat.c for lib in /home/tran_0/rendu/rendugit/PSU_2013_42sh/lib
** 
** Made by david tran
** Login   <tran_0@epitech.net>
** 
** Started on  Sun May 18 16:46:00 2014 david tran
** Last update Mon May 19 02:10:16 2014 david tran
*/

#include "my.h"

char	**wordtabcat(char **dest, char *str)
{
  int	i;

  i = my_strstrlen(dest);
  dest[i++] = my_strdup(str);
  dest[i] = NULL;
  return (dest);
}
