/*
** chain_to_wordtab.c for chain_to_wordtab in /home/tran_0/rendu/PSU_2013_minishell2
** 
** Made by david tran
** Login   <tran_0@epitech.net>
** 
** Started on  Fri Jan 24 16:40:56 2014 david tran
** Last update Sun Mar  9 20:34:20 2014 david tran
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "minishell2.h"

char	*my_feedstr(char *str, int *i, int *j)
{
  if (*i != 0)
    str[(*j)++] = ' ';
  return (str);
}

char	*feed_epur(char *str, char *buffer, int *i, int *j)
{
  if (buffer[*i] == ';' || buffer[*i] == ' ' || buffer[*i] == '\t')
    {
      if (buffer[*i - 1] != ' ' && buffer[*i] != '\t')
	str[(*j)++] = ' ';
      if (buffer[*i] == ';')
	{
	  str[(*j)++] = buffer[(*i)++];
	  if (buffer[*i] && buffer[*i] != ' ')
	    str[(*j)++] = ' ';
	}
      else
	while (buffer[*i] != '\n' && (buffer[*i] == ' ' || buffer[*i] == '\t'))
	  (*i)++;
    }
  else
    str[(*j)++] = buffer[(*i)++];
  return (str);
}

char	*my_epurstr(char *buffer)
{
  char	*str;
  int	i;
  int	j;

  i = 0;
  j = 0;
  if ((str = malloc(sizeof(*str) * (my_strlen(buffer) + \
				    countsimplevir(buffer)))) == NULL)
    return (NULL);
  while (buffer[i] == ' ')
    i++;
  while (buffer[i] && buffer[i] != '\n')
    str = feed_epur(str, buffer, &i, &j);
  str[j] = 0;
  return (epurpipechevr(str));
}

char		**feedintab(int *j, int *i, char **dest, t_data *other)
{
  while (*j < *i)
    {
      if ((dest[*j] = malloc((my_strlen(other->data)) * sizeof(char))) == NULL)
	return (NULL);
      my_strcpy(dest[(*j)++], other->data);
      other = other->next;
    }
  dest[*j] = NULL;
  return (dest);
}

char		**chain_to_wordtab(t_data *list)
{
  char		**dest;
  int		i;
  int		j;
  t_data	*tmp;
  t_data	*other;

  i = 0;
  j = 0;
  tmp = list->head;
  other = list->head;
  while (tmp != NULL)
    {
      tmp = tmp->next;
      i++;
    }
  if ((dest = malloc((i + 1) * sizeof(*dest))) == NULL)
    return (NULL);
  dest = feedintab(&j, &i, dest, other);
  return (dest);
}
