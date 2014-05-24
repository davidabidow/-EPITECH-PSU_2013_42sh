/*
** putwordtab.c for lib in /home/tran_0/rendu/rendugit/PSU_2013_42sh
** 
** Made by david tran
** Login   <tran_0@epitech.net>
** 
** Started on  Thu May 22 22:21:26 2014 david tran
** Last update Sat May 24 02:36:57 2014 david tran
*/

#include "my.h"

void	putwordtab(char **src)
{
  int	i;

  i = 0;
  while (src[i])
    {
      my_putstr(src[i]);
      i++;
      my_putchar('\n');
    }
}
