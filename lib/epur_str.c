/*
** epur_str.c for lib in /home/tran_0/rendu/rendugit/PSU_2013_42sh/src
** 
** Made by david tran
** Login   <tran_0@epitech.net>
** 
** Started on  Tue May  6 15:53:46 2014 david tran
** Last update Tue May 20 23:49:30 2014 david tran
*/

#include "my.h"

void	feed_epur(char *dest, char *str, int *i, int *j)
{
  dest[(*j)++] = ' ';
  dest[(*j)++] = str[(*i)++];
}

char	*epur_space(char *str)
{
  char	*dest;
  int	i;
  int	j;
  char	flag;

  i = 0;
  j = 0;
  flag = 0;
  if (!(dest = my_xmalloc(sizeof(char) * (my_strlen(str) + 1))))
    return (NULL);
  while (str[i])
    {
      if (str[i] && (str[i] == ' ' || str[i] == '\t'))
	i++;
      else if (i != 0 && (str[i - 1] == ' ' || str[i - 1] == '\t')
	       && str[i] != ' ' && str[i] != '\t' && flag != 0)
	feed_epur(dest, str, &i, &j);
      else
	{
	  dest[j++] = str[i++];
	  flag = 1;
	}
    }
  dest[i] = 0;
  return (dest);
}
