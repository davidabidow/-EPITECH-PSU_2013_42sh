/*
** parsing_command.c for 42sh in /home/tran_0/rendu/rendugit/PSU_2013_42sh/src
** 
** Made by david tran
** Login   <tran_0@epitech.net>
** 
** Started on  Mon May 19 13:05:55 2014 david tran
** Last update Wed May 21 13:47:30 2014 david tran
*/

#include "42sh.h"
#include "my.h"

char	*recup_princ(char **path, char *src)
{
  char	*str;
  int	i;

  i = 0;
  while (path[i])
    {
      while (path[i] && !(str = my_strcatslash(path[i], src)))
	i++;
      if (access(str, F_OK) == 0)
	return (str);
      i++;
    }
  if (access(src, F_OK) == 0)
    return (src);
  return (NULL);
}

int	parsing_command(char **src, t_bin *bin, t_pars *pars)
{
  if (!(pars->command = my_taballoc(sizeof(*pars->command))))
    return (-1);
  pars->command[0] = NULL;
  if (!(pars->princ = recup_princ(pars->path, src[pars->i])))
    return (-1);
  if (!(pars->command = wordtab_realloc(pars->command, 3)))
    return (-1);
  if (!(pars->command = wordtabcat(pars->command, src[pars->i++])))
    return (-1);
  while (src[pars->i] && check_wone(src[pars->i], pars->path) == -1)
    {
      my_putstr(src[pars->i]);
      my_putchar('\n');
      if (!(pars->command = wordtab_realloc(pars->command,
					    my_strstrlen(pars->command) + 2)))
	return (-1);
      if (!(pars->command = wordtabcat(pars->command, src[pars->i++])))
	return (-1);
    }
  if (create_nodd_command(bin, wordtabdup(pars->command),
			  my_strdup(pars->princ)) == -1)
    return (-1);
  return (EXIT_SUCCESS);
}
