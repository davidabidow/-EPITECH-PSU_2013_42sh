/*
** separate_char.c for lib in /home/tran_0/rendu/rendugit/PSU_2013_42sh/src
** 
** Made by david tran
** Login   <tran_0@epitech.net>
** 
** Started on  Tue May  6 16:18:44 2014 david tran
** Last update Wed May  7 15:36:39 2014 david tran
*/

#include "my.h"

int	count_separ(char *str, char *src)
{
  int	i;
  int	j;
  int	count;

  i = my_strlen(src);
  j = 0;
  count = 0;
  while (str[j])
    {
      if (my_strncmp(&str[j], src, i) == 0)
	{
	  while (str[j] && j < i)
	    j++;
	  count += 1;
	}
      j++;
    }
  return (count + 1);
}

char	*separate_char(char *src, char *str)
{
  int	i;
  int	j;
  int	k;
  char	*dest;

  i = 0;
  if ((dest = malloc(my_strlen(src) + count_separ(src, str) * 2 + 1)) == NULL)
    return (NULL);
  j = 0;
  while (src[i])
    {
      if (my_strncmp(&src[i], str, my_strlen(str)) == 0)
	{
	  k = -1;
	  if (src[i - 1] && src[i - 1] != ' ')
	    dest[j++] = ' ';
	  while (str[++k])
	    dest[j++] = src[i++];
	  if (src[i + 1] && src[i + 1] != ' ')
	    dest[j++] = ' ';
	}
      else
	dest[j++] = src[i++];
    }
  return (dest);
}
