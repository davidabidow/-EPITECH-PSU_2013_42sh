/*
** my_str_to_wordtab.c for my_str_to_wordtab in /home/tran_0/rendu/PSU_2013_minishell2
** 
** Made by david tran
** Login   <tran_0@epitech.net>
** 
** Started on  Thu Jan 23 16:07:09 2014 david tran
** Last update Mon Mar  3 18:50:01 2014 david tran
*/

#include "minishell2.h"

int	check_space(char *buffer, int i, int a)
{
  i = 0;
  a = 0;
  if (buffer == NULL)
    exit(1);
  while (buffer[a] != 0)
    {
      if (buffer[a] == ' ' && buffer[a + 1] != ' ')
	i++;
      a++;
    }
  return (i + 1);
}

void	init_val(int *i, int *a, int *b, char *buffer)
{
  *i = check_space(buffer, *i, *a);
  *a = 0;
  *b = 0;
}

void	countword(int *a, char *buffer)
{
  while (buffer[*a] != 0 && buffer[*a] != ' ')
    (*a)++;
}

char	**my_str_towordtab(char *buffer)
{
  char	**dest;
  int	i;
  int	a;
  int	b;
  int	c;

  buffer = my_epurstr(buffer);
  init_val(&i, &a, &b, buffer);
  if ((dest = malloc((i + 1) * sizeof(*dest))) == NULL)
    return (NULL);
  while (b < i)
    {
      c = a;
      countword(&a, buffer);
      if ((dest[b] = malloc((a - c + 1) * sizeof(**dest))) == NULL)
	return (NULL);
      a = c;
      c = 0;
      while (buffer[a] != 0 && buffer[a] != ' ')
	dest[b][c++] = buffer[a++];
      dest[b++][c] = 0;
      a++;
    }
  dest[b] = NULL;
  return (dest);
}
