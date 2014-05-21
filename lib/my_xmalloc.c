/*
** my_xmalloc.c for lib in /home/tran_0/rendu/rendugit/PSU_2013_42sh
** 
** Made by david tran
** Login   <tran_0@epitech.net>
** 
** Started on  Tue May 20 23:44:40 2014 david tran
** Last update Tue May 20 23:52:28 2014 david tran
*/

#include "my.h"

char	**my_taballoc(int len)
{
  char	**str;

  if (!(str = malloc(len)))
    my_putstr("Malloc Error\n");
  return (str);

}

char	*my_xmalloc(int len)
{
  char	*str;

  if (!(str = malloc(len)))
    my_putstr("Malloc Error\n");
  return (str);
}
