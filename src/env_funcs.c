/*
** env_funcs.c for 42sh in /home/tran_0/rendu/rendugit/PSU_2013_42sh/src
** 
** Made by david tran
** Login   <tran_0@epitech.net>
** 
** Started on  Mon May 12 16:47:07 2014 david tran
** Last update Mon May 19 03:29:42 2014 david tran
*/

#include "42sh.h"
#include "my.h"

int	my_strenv(char *nb1, char *nb2)
{
  int	i;

  i = 0;
  while (nb1 && nb2 && nb1[i] == nb2[i])
    {
      i++;
      if (nb2[i] == 0 && nb2[i] == '=')
	return (EXIT_SUCCESS);
    }
  return (EXIT_FAILURE);
}

char	*searchvar(char *str)
{
  int	i;
  int	j;
  char	*dest;

  i = 0;
  j = 0;
  if (!str)
    return (NULL);
  while (str[i] != '=')
    {
      if (!str[i++])
	return (NULL);
    }
  if (!(dest = malloc((i + 1) * sizeof(*dest))))
    return (NULL);
  while (j < i)
    {
      dest[j] = str[j];
      j++;
    }
  dest[j] = 0;
  return (dest);
}

int		my_countchain(t_env *list)
{
  t_env		*tmp;
  int		i;

  i = 0;
  tmp = list->head;
  while (tmp)
    {
      i++;
      tmp = tmp->next;
    }
  return (i);
}

char		*recupvar(t_env *list, char *str)
{
  t_env		*tmp;

  tmp = list->head;
  while (tmp != NULL)
    {
      if (my_strenv(tmp->data, str))
	return (cutbuffer(tmp->data));
      tmp = tmp->next;
    }
  return (NULL);
}

char		*cutbuffer(char *buffer)
{
  char		*str;
  int		i;
  int		j;

  i = 0;
  j = my_strlen(buffer);
  while (buffer[i] && buffer[i] != '=')
    i++;
  return (my_strdup(&buffer[++i]));
}
