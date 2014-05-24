/*
** infinite_pipe.c for infinite_pipe in /home/wallet_v/PSU_2013_42sh/src/tree
** 
** Made by valentin wallet
** Login   <wallet_v@epitech.net>
** 
** Started on  Wed May 21 19:45:51 2014 valentin wallet
** Last update Sat May 24 05:48:33 2014 david tran
*/

#include "42sh.h"
#include "my.h"

int		go_son(t_bin *bin, char **list, t_exec *execa)
{
  dup2(execa->save_pipeout, 0);
  if (bin->right != NULL)
    dup2(execa->pipefd[1], 1);
  close(execa->pipefd[0]);
  execve(bin->princ, bin->command, list);
  return (EXIT_SUCCESS);
}

int		go_dad(t_exec *execa)
{
  int		i;

  i = 0;
  wait(&execa->status);
  if (WIFSIGNALED(execa->status) == true)
    aff_signalcaught(WTERMSIG(execa->status));
  close(execa->pipefd[1]);
  execa->save_pipeout = execa->pipefd[0];
  return (WEXITSTATUS(execa->status));
}

int		loop_pipe(t_bin *tmp, char **list)
{
  t_exec	execa;
  t_bin		*bin;

  bin = tmp;
  execa.save_pipeout = 0;
  while (bin != NULL)
    {
      pipe(execa.pipefd);
      if ((execa.pid = fork()) == -1)
	return (EXIT_FAILURE);
      else if (execa.pid == 0)
	{
	  setpgid(0, 0);
	  if (go_son(bin, list, &execa) == -1)
	    woexit = EXIT_FAILURE;
	  return (-1);
	}
      else
	{
	  if (go_dad(&execa) == EXIT_FAILURE)
	    return (EXIT_FAILURE);
	  bin = bin->right;
	}
    }
  return (EXIT_SUCCESS);
}
