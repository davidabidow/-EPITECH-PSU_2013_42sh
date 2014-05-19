/*
** wordtabcpy.c for lib in /home/tran_0/rendu/rendugit/PSU_2013_42sh/lib
** 
** Made by david tran
** Login   <tran_0@epitech.net>
** 
** Started on  Sun May 18 16:43:14 2014 david tran
** Last update Sun May 18 22:27:45 2014 david tran
*/

#include "my.h"

char	**wordtabcpy(char **dest, char **src)
{
  int	i;

  i = 0;
  while (src[i])
    {
      dest[i] = my_strdup(src[i]);
      i++;
    }
  dest[i] = NULL;
  return (dest);
}
