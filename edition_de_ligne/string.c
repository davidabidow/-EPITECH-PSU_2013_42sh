/*
** string.c for string in /home/wallet_v/42sh_termcap
** 
** Made by valentin wallet
** Login   <wallet_v@epitech.net>
** 
** Started on  Wed May  7 19:16:48 2014 valentin wallet
** Last update Thu May 22 22:07:58 2014 valentin wallet
*/

#include "termcap.h"

char			*my_strcpy(char *src, char *dest)
{
  int			i;

  i = 0;
  while (src[i] != '\0')
    {
      dest[i] = src[i];
      i++;
    }
  dest[i] = '\0';
  return (dest);
}

void			my_putchar(char c)
{
  write(1, &c, 1);
}

int			my_strlen(char *str)
{
  int			i;

  i = 0;
  while (str[i] != '\0')
    i++;
  return (i);
}

void			my_putstr(char *str)
{
  int			i;

  i = 0;
  while (str[i] != '\0')
    my_putchar(str[i++]);
}

char			*my_strcat(char *src, int dest)
{
  int			i;
  char			*final;

  i = 0;
  final = malloc(sizeof(char) * (my_strlen(src) + 2));
  while (src[i] != '\0')
    {
      final[i] = src[i];
      i++;
    }
  final[i++] = dest;
  final[i] = '\0';
  my_putchar(dest);
  return (final);
}

char			*include_in_line(char *dest, int src, int *x, t_cmd *data)
{
  int			j;
  char			*end;
  char			*debut;
  char			*final;

  j = 0;
  end = malloc(sizeof(char) * (my_strlen(dest) + 1));
  debut = malloc(sizeof(char) * (my_strlen(dest) + 2));
  if (end == NULL || debut == NULL)
    return (NULL);
  my_strcpy(&dest[(*x - PROMPT_SIZE)], end);
  my_putchar(src);
  tputs(data->save, 1, my_putchar2);
  my_putstr(end);
  tputs(data->restor, 1, my_putchar2);
  while (j != (*x - PROMPT_SIZE))
    {
      debut[j] = dest[j];
      j++;
    }
  debut[j++] = src;
  debut[j] = '\0';
  final = strcat(debut, end);
  free(dest);
  return (final);
}
