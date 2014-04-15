/*
** forkpipe.c for forkpipe in /home/tran_0/rendu/PSU_2013_minishell2
** 
** Made by david tran
** Login   <tran_0@epitech.net>
** 
** Started on  Wed Mar  5 13:38:27 2014 david tran
** Last update Sun Mar  9 17:43:10 2014 david tran
*/

#include "minishell2.h"

int	pipeplace(char **src, int max)
{
  if (max != 0)
    max++;
  while (src[max] != NULL)
    {
      if (src[max][0] == '|')
	return (max);
      max++;
    }
  return (max);
}

int		pipeaccess(char **path, char **dest, char **env)
{
  t_pipe	pipe;
  char		**eve;

  pipe.k = 0;
  pipe.l = 0;
  pipe.j = my_strstrlen(path);
  if ((eve = malloc((countinfinitepipe(dest) + 2) * sizeof(*eve))) == NULL)
    return (1);
  while (dest[pipe.k] != NULL)
    if ((eve = pipeall(dest, path, eve, &pipe)) == NULL)
      return (1);
  eve[pipe.l] = NULL;
  infinitepipe(eve, env, dest);
  return (0);
}

void	feedchild(t_redi redi, char **env, char **eve, int pipefd[2])
{
  if (redi.i == 0)
    {
      close(pipefd[0]);
      dup2(pipefd[1], 1);
    }
  else if (redi.i < redi.fd - 1)
    {
      dup2(pipefd[0], 0);
      dup2(pipefd[1], 1);
      dup2(pipefd[0], pipefd[1]);
    }
  else
    {
      close(pipefd[1]);
      dup2(pipefd[0], 0);
    }
  execve(eve[redi.i], redi.redir, env);
}

void	feeddad(t_redi *redi, int pipefd[2])
{
  wait(0);
  if (redi->i == 0)
    close(pipefd[1]);
  else if (redi->i == redi->fd - 1)
    close(pipefd[0]);
  else
    {
      close(pipefd[0]);
      close(pipefd[1]);
    }
}
