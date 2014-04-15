/*
** makeforkpipe.c for makeforkpipe in /home/tran_0/rendu/PSU_2013_minishell2
** 
** Made by david tran
** Login   <tran_0@epitech.net>
** 
** Started on  Tue Feb 18 22:07:12 2014 david tran
** Last update Sun Mar  9 18:24:38 2014 david tran
*/

#include "minishell2.h"

void	checkexecve(char *str, char **dest, char **env)
{
  if (execve(str, dest, env) == -1)
    my_putstr("Execve failure\n");
}

void	feedredirexec(char *str, char **dest, char **env, t_redi redi)
{
  int	j;

  j = redi.i;
  if ((redi.fd = countchev(dest[j])) != 0)
    {
      if ((redi.fd == 2 || redi.fd == 1) && dest[j + 1])
	{
	  redi.fd = opennormal(redi.fd, dest[j + 1]);
	  makefork(str, redi.redir, env, redi.fd);
	}
      else if ((redi.fd == 3 || redi.fd == 4) && dest[j + 1])
	{
	  if (redi.fd == 3)
	    {
	      redi.fd = invertanaly(redi.fd, dest[j + 1]);
	      makeforkinvert(str, redi.redir, env, redi.fd);
	    }
	  else
	    dodoubleinvert(str, dest[j + 1], env, redi.redir);
	}
    }
}

void	makeforkinvert(char *str, char **dest, char **env, int fd)
{
  pid_t	pid;

  if ((pid = fork()) == -1)
    {
      my_putstr("ERROR: FORK\n");
      return ;
    }
  else if (pid == 0)
    {
      if (fd != 0)
	dup2(fd, 0);
      checkexecve(str, dest, env);
    }
  else
    {
      wait(0);
      close(fd);
    }
}

void	makeforkdoubleinvert(char *str, char **dest, char **env, char *src)
{
  int	pipefd[2];
  pid_t	cpid;

  if (pipe(pipefd) == -1)
    return ;
  if ((cpid = fork()) == -1)
    return ;
  else if (cpid == 0)
    {
      close(pipefd[1]);
      dup2(pipefd[0], 0);
      execve(str, dest, env);
    }
  else
    {
      close(pipefd[0]);
      write(pipefd[1], src, my_strlen(src));
      close(pipefd[1]);
      wait(0);
    }
}

void		infinitepipe(char **eve, char **env, char **dest)
{
  t_redi	redi;
  int		pipefd[2];
  pid_t		pid;
  int		min;
  int		max;

  min = 0;
  redi.i = 0;
  if (pipe(pipefd) == -1)
    return ;
  redi.fd = countinfinitepipe(dest) + 1;
  while (redi.i < redi.fd)
    {
      max = pipeplace(dest, min);
      redi.redir = my_tab_to_wordtab(dest, min, max);
      if ((pid = fork()) == -1)
	return ;
      if (pid == 0)
	feedchild(redi, env, eve, pipefd);
      else
	feeddad(&redi, pipefd);
      freetabtab(redi.redir);
      min = max + 1;
      redi.i++;
    }
}
