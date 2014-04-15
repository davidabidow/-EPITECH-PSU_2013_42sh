/*
** returnline_to_tab.c for returnline_to_tab in /home/tran_0/rendu/PSU_2013_minishell2
** 
** Made by david tran
** Login   <tran_0@epitech.net>
** 
** Started on  Mon Feb 24 12:23:26 2014 david tran
** Last update Sun Mar  9 17:49:03 2014 david tran
*/

#include "minishell2.h"

int	countreturnline(char *str)
{
  int	i;
  int	j;

  i = 0;
  j = 0;
  while (str[i])
    {
      if (str[i] == '\n')
	j++;
      i++;
    }
  return (j + 1);
}

void	init_returnline(int *i, int *a, int *b, char *buffer)
{
  *i = countreturnline(buffer);
  *a = 0;
  *b = 0;
}

char   	**returnline_to_tab(char *buffer)
{
  int	i;
  char	**dest;
  int	a;
  int	b;
  int	c;

  init_returnline(&i, &a, &b, buffer);
  if ((dest = malloc((i + 1) * sizeof(*dest))) == NULL)
    return (NULL);
  while (b < i)
    {
      c = a;
      while (buffer[a] && buffer[a] != '\n')
	a++;
      if ((dest[b] = malloc((a - c + 1) * sizeof(**dest))) == NULL)
	return (NULL);
      a = c;
      c = 0;
      while (buffer[a] && buffer[a] != '\n')
	dest[b][c++] = buffer[a++];
      dest[b++][c] = 0;
      a++;
    }
  dest[b] = NULL;
  return (dest);
}

void	dosimpleinvert(char **src, char **redir, char *str, char **env)
{
  int	i;
  char	**dest;

  i = 0;
  while (src[i])
    {
      dest = charst_in_tab(redir, src[i]);
      makefork(str, dest, env, 1);
      i++;
      freetabtab(dest);
    }
}

char	**charst_in_tab(char **src, char *str)
{
  int	i;
  int	j;
  char	**dest;

  i = my_strstrlen(src);
  j = 0;
  if ((dest = malloc(sizeof(*dest) * (i + 2))) == NULL)
    return (NULL);
  while (src[j] || j < i)
    {
      if ((dest[j] = malloc((my_strlen(src[j]) + 1) * sizeof(**dest))) == NULL)
	return (NULL);
      my_strcpy(dest[j], src[j]);
      j++;
    }
  if ((dest[j] = malloc((my_strlen(str) + 1) * sizeof(**dest))) == NULL)
    return (NULL);
  my_strcpy(dest[j], str);
  j++;
  dest[j] = NULL;
  return (dest);
}
