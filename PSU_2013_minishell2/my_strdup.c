/*
** my_strdup.c for my_strdup in /home/tran_0/rendu/PSU_2013_minishell2
** 
** Made by david tran
** Login   <tran_0@epitech.net>
** 
** Started on  Thu Jan 23 14:26:43 2014 david tran
** Last update Sun Mar  9 20:02:29 2014 david tran
*/

#include "minishell2.h"

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  while (str[i] != 0)
    {
      i++;
    }
  return (i);
}

char	*my_strcpy(char *dest, char *src)
{
  int	i;

  i = 0;
  while (src[i] != 0)
    {
      dest[i] = src[i];
      i++;
    }
  dest[i] = 0;
  return (dest);
}

char	*my_strdup(char *src)
{
  char	*str2;
  int	b;

  b = my_strlen(src);
  str2 = malloc((b + 1) * sizeof(char));
  my_strcpy(str2, src);
  return (str2);
}

int	my_strenv(char *nb_one, char *nb_two)
{
  int	i;

  i = 0;
  while (nb_two[i] == nb_one[i])
    {
      i++;
      if (nb_two[i] == 0 && nb_one[i] == '=')
	return (1);
    }
  return (0);
}

char	*my_strcat(char *dest, char *src)
{
  int	i;
  int	j;
  char	*str;

  j = 0;
  i = 0;
  if ((str = malloc((my_strlen(dest) + my_strlen(src) + 1) *
		    sizeof(*str))) == NULL)
    return (NULL);
  while (dest[j] != 0)
    str[i++] = dest[j++];
  j = 0;
  while (src[j] != '\0')
    str[i++] = src[j++];
  str[i] = '\0';
  return (str);
}
