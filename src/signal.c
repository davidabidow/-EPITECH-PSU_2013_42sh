/*
** signal.c for 42sh in /home/tran_0/rendu/rendugit/PSU_2013_42sh/src
** 
** Made by david tran
** Login   <tran_0@epitech.net>
** 
** Started on  Mon May  5 19:00:00 2014 david tran
** Last update Fri May  9 21:19:30 2014 david tran
*/

#include "42sh.h"

void	dontquit()
{
  write(2, "\n$42sh>", 8);
}
