/*
** minishell.c for minishell in /home/tran_0/rendu/PSU_2013_minishell2
** 
** Made by david tran
** Login   <tran_0@epitech.net>
** 
** Started on  Thu Jan 23 13:29:46 2014 david tran
** Last update Tue May  6 05:40:08 2014 david tran
*/

#include "minishell2.h"

int	comparemodes(char *buffer, t_data *list, char **dest)
{
  if (my_strcomma(buffer, "env") == 1)
    {
      my_affchain(list);
      return (0);
    }
  else if (my_strcomma(buffer, "setenv") == 1)
    {
      setinlist(list, dest[1]);
      return (0);
    }
  else if (my_strcomma(buffer, "cd") == 1)
    {
      changedirect(list, dest[1]);
      return (0);
    }
  else if (my_strcomma(buffer, "unsetenv") == 1)
    {
      supplist(list, dest[1]);
      return (0);
    }
  else if (my_strcomma(buffer, "exit") == 1)
    exit(1);
  else if (my_strcomma(buffer, "\n") == 1)
    return (0);
  return (1);
}

char		*makeread(t_data *list)
{
  char		buffer[1024];
  int		readed;
  int		a;

  signal(SIGINT, SIG_IGN);
  while ((readed = read(0, buffer, 1023)) != 0)
    {
      buffer[readed] = 0;
      a = 0;
      while (buffer[a] != 0)
	{
	  if (buffer[a] == '\n')
	    return (my_strdup(buffer));
	  a++;
	}
    }
  if (readed == 0)
    {
      my_putstr("EXIT \n");
      if (list->head && list->end)
      	freelist(list);
      exit(1);
    }
  return (NULL);
}

void	infiniteloop(t_data *list)
{
  char	*buffer;
  char	**dest;
  int	min;
  int	max;
  char	**new;

  while (42)
    {
      initinfiniteloop(&min, &max);
      if ((buffer = makeread(list)) == NULL)
	return ;
      if ((dest = my_str_towordtab(buffer)) == NULL)
	return ;
      while (max != my_strstrlen(dest))
      	{
      	  max = countpvir(dest, max);
      	  if ((new = my_tab_to_wordtab(dest, min, max)) == NULL)
	    return ;
	  if (comparemodes(buffer, list, new) == 1)
	    testexec(buffer, new, list);
	  min = max + 1;
	}
      freetabtab(dest);
    }
}

int		main(int ac, char **av, char **environ)
 {
  t_data	*list;

  (void)ac;
  (void)av;
  signal(SIGSEGV, sigsevcatch);
  if ((list = malloc(sizeof(*list))) == NULL)
    return (1);
  list->head = NULL;
  list->end = NULL;
  while (*environ != NULL)
    {
      put_in_chainlist(list, my_strdup(*environ));
      environ++;
    }
  infiniteloop(list);
  freelist(list);
  return (0);
}
