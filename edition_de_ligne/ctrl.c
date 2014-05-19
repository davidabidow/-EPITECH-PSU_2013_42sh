/*
** ctrl.c for ctrl in /home/wallet_v/42sh_edition_historique
** 
** Made by valentin wallet
** Login   <wallet_v@epitech.net>
** 
** Started on  Mon May 19 15:07:30 2014 valentin wallet
** Last update Mon May 19 16:12:32 2014 valentin wallet
*/

#include "termcap.h"

char			*ctrl_y(char *dest, char *src, int *i, int *x, t_cmd *data)
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
    {
      debut[j] = dest[j];
      j++;
    }
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

char			*ctrl_k(char *str, t_cmd *data, int *x, struct winsize *mysizewin)
{
  char			*buffer;
  int			k;
  int			j;

  k = *x - 3;
  j = 0;
  if ((*x - 3) == my_strlen(str))
    return (NULL);
  buffer = malloc(sizeof(char) * (my_strlen(str) + 1));
  tputs(data->save, 1, my_putchar2);
  while (str[k] != '\0')
    {
      buffer[j++] = str[k++];
      write(1, " ", 1);
    }
  buffer[j] = '\0';
  tputs(data->restor, 1, my_putchar2);
  str[(*x) - 3] = '\0';
  return (buffer);
}
