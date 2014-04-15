/*
** tradepipe.c for tradepipe in /home/tran_0/rendu/PSU_2013_minishell2
**
** Made by david tran
** Login   <tran_0@epitech.net>
**
** Started on  Tue Mar  4 13:49:06 2014 david tran
** Last update Fri Mar  7 23:54:59 2014 david tran
*/

#include "minishell2.h"

int	countinfinitepipe(char **dest)
{
  int	i;
  int	j;

  i = 0;
  j = 0;
  while (dest[j] != NULL)
    {
      if (dest[j][0] == '|')
	i++;
      j++;
    }
  return (i);
}

char	*pipefeedaccess(char *dest, t_pipe *pipe, char **eve)
{
  if (access(dest, F_OK) == -1)
    return (NULL);
  else
    {
      if ((eve[pipe->l] = malloc(sizeof(**eve) *
			   (my_strlen(pipe->str) + 1))) == NULL)
	return (NULL);
      eve[pipe->l] = my_strcpy(eve[pipe->l], pipe->str);
    }
  pipe->l++;
  return (eve[pipe->l - 1]);
}

char	*pipefeedequal(char **eve, t_pipe *pipe)
{
  if ((eve[pipe->l] = malloc(sizeof(**eve) *
		       (my_strlen(pipe->str) + 1))) == NULL)
    return (NULL);
  eve[pipe->l] = my_strcpy(eve[pipe->l], pipe->str);
  pipe->l++;
  return (eve[pipe->l - 1]);
}

char	**pipeall(char **dest, char **path, char **eve, t_pipe *pipe)
{
  pipe->i = 0;
  if (pipe->k == 0 || dest[pipe->k - 1][0] == '|')
    while (pipe->i < (pipe->j - 1))
      {
	pipe->str = my_strcatslash(path[pipe->i], dest[pipe->k]);
	pipe->i++;
	if (access(pipe->str, F_OK) == 0)
	  pipe->i = pipe->j;
      }
  if (pipe->i == (pipe->j - 1))
    {
      if ((eve[pipe->l] = pipefeedaccess(dest[pipe->k], pipe, eve)) == NULL)
	return (NULL);
      pipe->i++;
    }
  else if (pipe->i == pipe->j)
    if ((eve[pipe->l] = pipefeedequal(eve, pipe)) == NULL)
      return (NULL);
  pipe->k++;
  return (eve);
}
