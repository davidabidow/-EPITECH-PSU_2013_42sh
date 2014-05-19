/*
** supp_delete.c for supp_delete in /home/wallet_v/42sh_edition_historique
** 
** Made by valentin wallet
** Login   <wallet_v@epitech.net>
** 
** Started on  Mon May 19 15:09:38 2014 valentin wallet
** Last update Mon May 19 16:02:00 2014 valentin wallet
*/

#include "termcap.h"

char			*my_del(char *str, t_cmd *data, int *x, struct winsize *mysizewin)
{
  char			*tmp;
  char			*newstr;
  char			*final;
  int			k;
  int			j;
  int			n;

  k = *x - 3;
  j = 0;
  n = 0;
  if (my_strlen(str) == 0 || *x == 3)
    return (str);
  newstr = malloc(sizeof(char) * my_strlen(str));
  while (str[k] != '\0')
    newstr[j++] = str[k++];      
  newstr[j] = '\0';
  tmp = malloc(sizeof(char) * (my_strlen(str)));
  while (n != (*x - 4))
    {
      tmp[n] = str[n];
      n++;
    }
  tmp[n] = '\0';
  move_left(data, x, mysizewin);
  tputs(data->save, 1, my_putchar2);
  my_putstr(newstr);
  write(1, " ", 1);
  tputs(data->restor, 1, my_putchar2);
  final = strcat(tmp, newstr);
  return (final);
}

char			*my_suppr(char *str, t_cmd *data, int *x, struct winsize *mysizewin UNUSED)
{
  char			*final;
  char			*tmp;
  char			*newstr;
  int			k;
  int			j;
  int			m;

  k = *x - 2;
  j = 0;
  newstr = malloc(sizeof(char) * my_strlen(str));
  while (str[k] != '\0')
      newstr[j++] = str[k++];
  newstr[j] = '\0';
  tputs(data->save, 1, my_putchar2);
  my_putstr(newstr);
  write(1, " ", 1);
  tputs(data->restor, 1, my_putchar2);
  tmp = malloc(sizeof(char) * my_strlen(str));
  m = 0;
  while (m != (*x - 3))
    {
      tmp[m] = str[m];
      m++;
    }
  tmp[m] = '\0';
  final = strcat(tmp, newstr);
  free(str);
  return (final);
}
