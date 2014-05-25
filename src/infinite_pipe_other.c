/*
** infinite_pipe_other.c for 42sh in /home/tran_0/rendu/rendugit/PSU_2013_42sh
** 
** Made by david tran
** Login   <tran_0@epitech.net>
** 
** Started on  Sun May 25 19:41:09 2014 david tran
** Last update Sun May 25 20:02:23 2014 david tran
*/

#include "42sh.h"
#include "my.h"

int	son_error(t_bin *bin, char **list, t_exec *execa)
{
  if (go_son(bin, list, execa) == -1)
    {
      my_putstr("Command not found : ");
      my_putstr(bin->princ);
      my_putstr("\n");
      woexit = EXIT_FAILURE;
    }
  return (-1);
}
