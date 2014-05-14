/*
** my_puterr.c for lib in /home/tran_0/rendu/rendugit/PSU_2013_42sh/src
** 
** Made by david tran
** Login   <tran_0@epitech.net>
** 
** Started on  Mon May 12 23:07:19 2014 david tran
** Last update Tue May 13 22:45:39 2014 david tran
*/

#include "my.h"

void	my_puterr(char *str)
{
  write(2, str, my_strlen(str));
}
