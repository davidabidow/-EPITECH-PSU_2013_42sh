/*
** my_path_towordtab.c for my_path_towordtab in /home/tran_0/rendu/PSU_2013_minishell2
** 
** Made by david tran
** Login   <tran_0@epitech.net>
** 
** Started on  Fri Jan 24 15:56:29 2014 david tran
** Last update Mon Mar  3 18:45:09 2014 david tran
*/

#include "minishell2.h"

int	check_point(char *buffer, int i, int a)
{
  i = 0;
  a = 0;
  while (buffer[a] != 0)
    {
      if (buffer[a] == ':' || buffer[a] == 0)
	i++;
      a++;
    }
  return (i);
}

char	*cutbuffer(char *buffer)
{
  char	*str;
  int	i;
  int	j;

  i = 0;
  j = 0;
  while (buffer[j] != 0)
    j++;
  while (buffer[i] != '=')
    i++;
  if ((str = malloc((j - i + 1) * sizeof(*str))) == NULL)
    return (NULL);
  j = 0;
  i++;
  while (buffer[i] != 0)
    str[j++] = buffer[i++];
  str[j] = 0;
  return (str);
}

char	**my_path_indtab(char **dest, int i, char *buffer, int c)
{
  int	a;
  int	b;

  a = 0;
  b = 0;
  while (b < i)
    {
      c = a;
      while (buffer[a] != ':' && buffer[a] != 0)
	a++;
      if (((dest[b] = malloc((a - c + 2) * sizeof(**dest)))) == NULL)
	return (NULL);
      a = c;
      c = 0;
      while (buffer[a] != ':' && buffer[a] != 0)
	dest[b][c++] = buffer[a++];
      dest[b++][c] = 0;
      a++;
    }
  return (dest);
}

char	**my_path_towordtab(char *buffer)
{
  char	**dest;
  int	i;
  int	a;
  int	c;
  char	*str;

  init_val(&i, &a, &c, buffer);
  str = cutbuffer(buffer);
  i = check_point(str, i, a);
  if ((dest = malloc((i + 2) * sizeof(*dest))) == NULL && str == NULL)
    return (NULL);
  dest = my_path_indtab(dest, i, str, c);
  dest[i] = NULL;
  return (dest);
}
