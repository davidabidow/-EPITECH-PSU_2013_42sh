/*
** string.c for string in /home/wallet_v/42sh_termcap
** 
** Made by valentin wallet
** Login   <wallet_v@epitech.net>
** 
** Started on  Wed May  7 19:16:48 2014 valentin wallet
** Last update Sat May 24 03:20:42 2014 valentin wallet
*/

#include "42sh.h"
#include "my.h"

char			*my_strcat_int(char *src, int dest)
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
  strcpy(end, &dest[(*x - PROMPT_SIZE)]);
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
