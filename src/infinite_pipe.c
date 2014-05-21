/*
** infinite_pipe.c for infinite_pipe in /home/wallet_v/PSU_2013_42sh/src/tree
** 
** Made by valentin wallet
** Login   <wallet_v@epitech.net>
** 
** Started on  Wed May 21 19:45:51 2014 valentin wallet
** Last update Wed May 21 22:16:47 2014 valentin wallet
*/

#include "42sh.h"
#include "my.h"

int		loop_pipe(t_bin *bin)
{
  int		status;
  int		pipefd[2];
  pid_t		pid;
  int		save_pipeout;

  save_pipeout = 0;
  while (bin->right != NULL)
    {
      pipe(pipefd);
      if ((pid = fork()) == -1)
	return (EXIT_FAILURE);
      else if (pid == 0)
	{
	  dup2(save_pipeout, 0);
	  if (bin->right != NULL)
	    dup2(pipefd[1], 1);
	  close(pipefd[0]);
	  // execve
	}
      else
	{
	  wait(&status);
	  close(pipefd[1]);
	  save_pipeout = pipefd[0];
	  bin = bin->right;
	}
    }
}
