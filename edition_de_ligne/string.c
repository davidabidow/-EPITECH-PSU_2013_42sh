/*
** string.c for string in /home/wallet_v/42sh_termcap
** 
** Made by valentin wallet
** Login   <wallet_v@epitech.net>
** 
** Started on  Wed May  7 19:16:48 2014 valentin wallet
** Last update Thu May 15 08:55:14 2014 valentin wallet
*/

#include "termcap.h"

void			my_putchar(char c)
{
  write(1, &c, 1);
}

void			my_putstr(char *str)
{
  int			i;
  
  i = 0;
  while (str[i] != '\0')
    my_putchar(str[i++]);
}

char                    *home_strcat(char *dest, char *src, int *i, int *x, t_cmd *data)
{
  int                   j;
  char                  *final;

  final = malloc(sizeof(char) * ((*i) + my_strlen(src) + 2));
  j = 0;
  if (dest != NULL)
    {
      while (dest[j] != '\0')
        final[j] = dest[j++];
    }
  j = 0;
  while (src[j] != '\0')
    final[(*i)++] = src[j++];
  final[(*i)] = '\0';
  my_putstr(src);
  return (final);
}

char			*include_in_line(char *dest, char *src, int *i, int *x, t_cmd *data)
{
  int			k;
  int			j;
  int			m;
  char			*end;
  char			*debut;
  char			*final;

  k = *x - 3;
  j = 0;
  end = malloc(sizeof(char) * (my_strlen(dest) + 1));
  debut = malloc(sizeof(char) * (my_strlen(dest) + my_strlen(src) + 1));
  while (dest[k] != '\0')
    end[j++] = dest[k++];
  end[j] = '\0';
  my_putstr(src);
  my_putstr(end);
  while (j > 0)
    {
      tputs(data->curse_l, 1, my_putchar2);
      j--;
    }
  while (j != (*x - 3))
    debut[j] = dest[j++];
  m = 0;
  while (src[m] != '\0')
    {
      debut[j++] = src[m++];
      *i = *i + 1;
    }
  debut[j] = '\0';
  final = strcat(debut, end);
  return (final);
}

int			my_strlen(char *str)
{
  int			i;
  
  i = 0;
  while (str[i] != '\0')
    i++;
  return (i);
}
