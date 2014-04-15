/*
** my_tab_to_wordtab.c for my_tab_to_wordtab in /home/tran_0/rendu/PSU_2013_minishell2
** 
** Made by david tran
** Login   <tran_0@epitech.net>
** 
** Started on  Sun Feb 16 06:20:32 2014 david tran
** Last update Sun Mar  9 20:50:33 2014 david tran
*/

#include "minishell2.h"

int	searchchev(char **str)
{
  int	i;

  i = 0;
  while (str[i] != NULL)
    {
      if (str[i][0] == '<' || str[i][0] == '>')
	return (1);
      i++;
    }
  return (0);
}

int	countchev(char *src)
{
  int	i;

  if (src[0] == '>')
    {
      i = 1;
      if (src[1] == '>')
	i = 2;
    }
  else if (src[0] == '<')
    {
      i = 3;
      if (src[1] == '<')
	i = 4;
    }
  else
    i = 0;
  return (i);
}

int	countsimplevir(char *src)
{
  int	i;
  int	j;

  i = 0;
  j = 0;
  while (src[i] != 0)
    {
      if (src[i] != ';')
	j++;
      i++;
    }
  return (j + j * 3);
}

void	freetabtab(char **src)
{
  char	*dest;
  int	i;

  i = 0;
  while (src[i])
    {
      dest = src[i++];
      free(dest);
    }
  free(src);
}

char	**my_tab_to_wordtab(char **src, int min, int max)
{
  char	**dest;
  int	i;

  i = 0;
  if ((dest = malloc(sizeof(*dest) * (max - min + 1))) == NULL)
    return (NULL);
  while (src[min] && min < max)
    {
      if ((dest[i] = malloc(sizeof(**dest) *
			    (my_strlen(src[min]) + 1))) == NULL)
	return (NULL);
      my_strcpy(dest[i], src[min]);
      i++;
      min++;
    }
  dest[i] = NULL;
  return (dest);
}
