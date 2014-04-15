/*
** makefork.c for makefork in /home/tran_0/rendu/PSU_2013_minishell2
** 
** Made by david tran
** Login   <tran_0@epitech.net>
** 
** Started on  Thu Jan 23 17:23:37 2014 david tran
** Last update Tue Apr 15 13:46:41 2014 david tran
*/

#include "minishell2.h"

void		doredirexec(char *str, char **dest, char **env)
{
  t_redi	redi;

  redi.i = 0;
  redi.redir = my_tab_to_wordtab(dest, 0, whenredirect(dest));
  while (dest[redi.i] != NULL)
    {
      feedredirexec(str, dest, env, redi);
      redi.i++;
    }
}

void	doexec(char *str, char **dest, char **env)
{
  if (searchchev(dest) == 1)
    doredirexec(str, dest, env);
  else
    makefork(str, dest, env, 1);
}

int	checkaccess(char **path, char **dest, char **env)
{
  int	i;
  char	*str;
  int	j;

  j = my_strstrlen(path);
  i = 0;
  if (countinfinitepipe(dest) != 0)
    if (pipeaccess(path, dest, env) == 1)
      return (1);
  while (i < (j - 1))
    {
      str = my_strcatslash(path[i], dest[0]);
      if (access(str, F_OK) == 0)
  	{
  	  doexec(str, dest, env);
  	  return (0);
  	}
      i++;
    }
  if (access(dest[0], F_OK) == 0)
    {
      doexec(dest[0], dest, env);
      return (0);
    }
  return (1);
}

void	testexec(char *buffer, char **dest, t_data *list)
{
  char	**COMBOpath;
  char	**env;
  char	*str;

  if ((str = my_searchinchain(list, "PATH")) == NULL)
    {
      my_putstr("Command not found: No PATH in Env\n");
      return ;
    }
  if ((COMBOpath = my_path_towordtab(str)) == NULL)
    return ;
  env = chain_to_wordtab(list);
  if (checkaccess(COMBOpath, dest, env) == 1)
    my_putstr("Command not found\n");
  freetabtab(COMBOpath);
}

void	makefork(char *str, char **dest, char **env, int fd)
{
  pid_t	pid;

  if ((pid = fork()) == -1)
    {
      my_putstr("ERROR: FORK\n");
      return ;
    }
  else if (pid == 0)
    {
      if (fd != 1)
	dup2(fd, 1);
      checkexecve(str, dest, env);
      exit(1);
    }
  else
    {
      wait(0);
      if (fd != 1)
	close(fd);
    }
}
