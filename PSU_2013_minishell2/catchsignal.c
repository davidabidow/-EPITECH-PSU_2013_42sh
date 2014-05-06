/*
** catchsignal.c for minishell2 in /home/tran_0/rendu/rendugit/PSU_2013_42sh/PSU_2013_minishell2
** 
** Made by david tran
** Login   <tran_0@epitech.net>
** 
** Started on  Thu Apr 24 08:29:11 2014 david tran
** Last update Thu Apr 24 08:29:58 2014 david tran
*/

#include "minishell2.h"

void	sigsevcatch()
{
  my_putstr("Catched signal SIGSEV\n");
}
