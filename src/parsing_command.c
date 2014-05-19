/*
** parsing_command.c for 42sh in /home/tran_0/rendu/rendugit/PSU_2013_42sh/src
** 
** Made by david tran
** Login   <tran_0@epitech.net>
** 
** Started on  Mon May 19 13:05:55 2014 david tran
** Last update Mon May 19 21:42:25 2014 david tran
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

int	add_redir_command(char **src, t_bin *bin, t_pars *pars)
{

}

int	add_pipe_command(char **src, t_bin *bin, t_pars *pars)
{
  
}

int	parsing_command(char **src, t_bin *bin, t_pars *pars)
{
  if (!(pars->command = malloc(sizeof(*pars->command))))
    return (-1);
  pars->command[0] = NULL;
  if (!(pars->princ = recup_princ(path, src[pars->i])))
    return (-1);
  if (!(pars->command = wordtab_realloc(pars->command,
					my_strstrlen(pars->command) + 1)))
    return (-1);
  if (!(pars->command = wordtabcat(pars->command, src[pars->i])))
    return (-1);
  while (src[pars->i] && check_wone == -1)
    {
      if (!(pars->command = wordtab_realloc(pars->command,
					    my_strstrlen(pars->command) + 1)))
	return (-1);
      if (!(pars->command = wordtabcat(pars->command, src[(pars->i)++])))
	return (-1);
    }
  if (create_nodd_command(bin, pars->command, pars->princ) == EXIT_FAILURE)
    return (-1);
  if (src[pars->i])
    if (add_pipe_command(src, bin, pars) == -1)
      return (-1);
  return (EXIT_SUCCESS);
}
