/*
** my_strlen.c for lib in /home/tran_0/rendu/rendugit/PSU_2013_42sh/lib
** 
** Made by david tran
** Login   <tran_0@epitech.net>
** 
** Started on  Tue May  6 06:09:48 2014 david tran
** Last update Fri May  9 00:54:05 2014 david tran
*/

#include "my.h"

int	my_strstrlen(char **str)
{
  int	i;

  i = 0;
  while (str[i])
    i++;
  return (i);
}

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  while (str[i])
    i++;
  return (i);
}
