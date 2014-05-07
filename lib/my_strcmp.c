/*
** my_strcmp.c for lib in /home/tran_0/rendu/rendugit/PSU_2013_42sh/src
** 
** Made by david tran
** Login   <tran_0@epitech.net>
** 
** Started on  Tue May  6 15:41:39 2014 david tran
** Last update Wed May  7 15:36:22 2014 david tran
*/

#include "my.h"

int	my_strncmp(char *dest, char *src, int len)
{
  int	i;

  i = 0;
  while (src[i] && dest[i] && src[i] == dest[i] && i < len - 1)
    i++;
  return (src[i] - dest[i]);
}

int	my_strcmp(char *dest, char *src)
{
  int	i;

  i = 0;
  while (src[i] && dest[i] && src[i] == dest[i])
    i++;
  return (src[i] - dest[i]);
}
