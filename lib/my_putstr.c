/*
** my_putstr.c for lib in /home/tran_0/rendu/rendugit/PSU_2013_42sh/lib
** 
** Made by david tran
** Login   <tran_0@epitech.net>
** 
** Started on  Tue May  6 06:10:45 2014 david tran
** Last update Tue May  6 06:11:41 2014 david tran
*/

#include "my.h"

void	my_putstr(char *str)
{
  write(1, str, my_strlen(str));
}
