/*
** parsing_oper.c for 42sh in /home/tran_0/rendu/rendugit/PSU_2013_42sh/src
** 
** Made by david tran
** Login   <tran_0@epitech.net>
** 
** Started on  Tue May 20 16:13:03 2014 david tran
** Last update Tue May 20 22:37:02 2014 david tran
*/

#include "42sh.h"
#include "my.h"

int	parsing_ope(char **src, t_bin *bin, t_pars *pars)
{
  bin = bin;
  my_putstr("Parsing error near '");
  my_putstr(src[pars->i]);
  my_putstr("'\n");
  return (-1);
}
