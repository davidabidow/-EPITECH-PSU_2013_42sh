/*
** infinite_pipe.c for infinite_pipe in /home/wallet_v/PSU_2013_42sh/src/tree
** 
** Made by valentin wallet
** Login   <wallet_v@epitech.net>
** 
** Started on  Wed May 21 19:45:51 2014 valentin wallet
** Last update Sun May 25 01:11:53 2014 david tran
*/

#include "42sh.h"
#include "my.h"

void		built_dad(t_exec *execa, t_bin *bin, t_env **env)
{
  int		i;

  i = 0;
  while (built[i].name && bin->command && bin->command[0] &&
	 my_strcmp(built[i].name, bin->command[0]) != 0)
    i++;
  if (i < 5)
    {
      if (bin->right)
	dup2(execa->pipefd[1], 1);
      built[i].func(*env, bin->command);
    }
}
int		go_son(t_bin *bin, char **list, t_exec *execa, t_env **env)
{
  int		i;

  i = 0;
  (bin->pre->head && bin->pre->head->fd != -1) ? dup2(bin->pre->head->fd, 0) :
    dup2(execa->save_pipeout, 0);
  if (execa->save_pipeout == 0)
    dup2(execa->pipefd[0], 0);
  if (bin->right != NULL)
    dup2(execa->pipefd[1], 1);
  close(execa->pipefd[0]);
  close(execa->pipefd[1]);
  while (built[i].name && bin->command && bin->command[0] &&
	 my_strcmp(built[i].name, bin->command[0]) != 0)
    i++;
  if (i >= 5)
    execve(bin->princ, bin->command, list);
  return (EXIT_SUCCESS);
}

int		go_dad(t_exec *execa, t_env **env, t_bin *bin)
{
  if (bin->pre->head && bin->pre->head->dinv)
    {
      close(execa->pipefd[0]);
      write(execa->pipefd[1], bin->pre->head->dinv,
	    my_strlen(bin->pre->head->dinv));
    }
  else
    built_dad(execa, bin, env);
  close(execa->pipefd[1]);
  wait(&execa->status);
  if (WIFSIGNALED(execa->status) == true)
    aff_signalcaught(WTERMSIG(execa->status));
  execa->save_pipeout = execa->pipefd[0];
  return (WEXITSTATUS(execa->status));
}

int		loop_pipe(t_bin *tmp, char **list, t_env **env)
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
	  //	  setpgid(0, 0);
	  if (go_son(bin, list, &execa, env) == -1)
	    woexit = EXIT_FAILURE;
	  return (-1);
	}
      else
	{
	  if (go_dad(&execa, env, bin) == EXIT_FAILURE)
	      return (EXIT_FAILURE);
	  bin = bin->right;
	}
    }
  return (EXIT_SUCCESS);
}
