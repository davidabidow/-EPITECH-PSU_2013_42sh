/*
** simple_normal.c for 42sh in /home/tran_0/rendu/rendugit/PSU_2013_42sh/src/redir
** 
** Made by david tran
** Login   <tran_0@epitech.net>
** 
** Started on  Thu May 15 17:58:53 2014 david tran
** Last update Thu May 15 18:22:08 2014 david tran
*/

#include "42sh.h"
#include "my.h"

int		simple_normal(char *file)
{
  return (open(file, O_RDWR | O_CREAT | O_TRUNC, 0644));
}
