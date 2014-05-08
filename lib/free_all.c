/*
** free_all.c for lib in /home/tran_0/rendu/rendugit/PSU_2013_42sh
** 
** Made by david tran
** Login   <tran_0@epitech.net>
** 
** Started on  Fri May  9 01:08:59 2014 david tran
** Last update Fri May  9 01:19:40 2014 david tran
*/

#include "42sh.h"
#include "my.h"

void	free_wordtab(char **src)
{
  char	*dest;
  int	i;

  i = 0;
  while (src[i])
    {
      dest = src[i++];
      free(dest);
    }
  free(src);
}
