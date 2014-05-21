/*
** supp_delete.c for supp_delete in /home/wallet_v/42sh_edition_historique
** 
** Made by valentin wallet
** Login   <wallet_v@epitech.net>
** 
** Started on  Mon May 19 15:09:38 2014 valentin wallet
** Last update Tue May 20 11:45:42 2014 valentin wallet
*/

#include "termcap.h"

char			*my_del(char *str, t_cmd *data, int *x, struct winsize *mysizewin)
{
  char			*tmp;
  char			*newstr;
  char			*final;
  int			n;

  n = 0;
  if ((my_strlen(str) == 0) || (*x == PROMPT_SIZE))
    return (str);
  newstr = malloc(sizeof(char) * my_strlen(str));
  my_strcpy(&str[(*x) - PROMPT_SIZE], newstr);
  tmp = malloc(sizeof(char) * (my_strlen(str)));
  while (n != (*x - (PROMPT_SIZE + 1)))
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
  free(str);
  return (final);
}

char			*my_suppr(char *str, t_cmd *data, int *x, struct winsize *mysizewin UNUSED)
{
  char			*final;
  char			*tmp;
  char			*newstr;
  int			m;

  if ((*x - PROMPT_SIZE) == my_strlen(str))
    return (str);
  newstr = malloc(sizeof(char) * my_strlen(str));
  my_strcpy(&str[(*x) - (PROMPT_SIZE - 1)], newstr);
  tputs(data->save, 1, my_putchar2);
  my_putstr(newstr);
  write(1, " ", 1);
  tputs(data->restor, 1, my_putchar2);
  tmp = malloc(sizeof(char) * my_strlen(str));
  m = 0;
  while (m != (*x - (PROMPT_SIZE)))
    {
      tmp[m] = str[m];
      m++;
    }
  tmp[m] = '\0';
  final = strcat(tmp, newstr);
  free(str);
  return (final);
}
