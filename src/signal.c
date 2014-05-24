/*
** signal.c for 42sh in /home/tran_0/rendu/rendugit/PSU_2013_42sh/src
** 
** Made by david tran
** Login   <tran_0@epitech.net>
** 
** Started on  Mon May  5 19:00:00 2014 david tran
** Last update Sat May 24 05:51:18 2014 david tran
*/

#include "42sh.h"
#include "my.h"

t_signa		sesign[] =
  {
    {1, "SIGHUP"},
    {2, "SIGINT"},
    {3, "SIGQUIT"},
    {4, "SIGILL"},
    {6, "SIGABRT"},
    {8, "SIGFPE"},
    {11, "SIGKILL"},
    {13, "SIGPIPE"},
    {14, "SIGALRM"},
    {15, "SIGTERM"},
    {10, "SIGBUS"},
    {7, "SIGBUS"},
  };

void		dontquit()
{
  write(2, "\n$42sh>", 8);
}

void		aff_signalcaught(int flag)
{
  int		i;

  i = 0;
  while (i < 12 && sesign[i].sign != flag)
    i++;
  if (i == 12)
    my_putstr("Catched unknown signal... \n");
  else
    {
      my_putstr("Catched signal : '");
      my_putstr(sesign[i].signal);
      my_putstr("'\n");
    }
}
