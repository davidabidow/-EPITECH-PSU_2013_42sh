/*
** my_isnumb.c for lib in /home/tran_0/rendu/rendugit/PSU_2013_42sh/src/builtin
** 
** Made by david tran
** Login   <tran_0@epitech.net>
** 
** Started on  Tue May 13 19:16:36 2014 david tran
** Last update Tue May 13 22:44:25 2014 david tran
*/

#include "my.h"

int	my_isnumb(char *str)
{
  int	i;

  i = 0;
  while (str[i])
    {
      if (str[i] < '0' || str[i] > '9')
	return (EXIT_FAILURE);
      i++;
    }
  return (EXIT_SUCCESS);
}
