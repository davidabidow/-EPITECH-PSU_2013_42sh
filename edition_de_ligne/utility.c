/*
** utility.c for utility in /home/wallet_v/42sh_edition_historique
** 
** Made by valentin wallet
** Login   <wallet_v@epitech.net>
** 
** Started on  Mon May 19 15:16:32 2014 valentin wallet
** Last update Fri May 23 23:48:31 2014 valentin wallet
*/

#include "42sh.h"

void		my_tgetstr(t_cmd *data)
{
  data->curse = tgetstr("vi", NULL);
  data->cursef = tgetstr("ve", NULL);
  data->underlines = tgetstr("us", NULL);
  data->underlinef = tgetstr("ue", NULL);
  data->gotostr = tgetstr("cm", NULL);
  data->clearstr = tgetstr("cl", NULL);
  data->standstr = tgetstr("so", NULL);
  data->stendstr = tgetstr("se", NULL);
  data->curse_r = tgetstr("nd", NULL);
  data->curse_l = tgetstr("le", NULL);
  data->curse_up = tgetstr("up", NULL);
  data->save = tgetstr("sc", NULL);
  data->restor = tgetstr("rc", NULL);
  data->suppline = tgetstr("cd", NULL);
}

int                     my_putchar2(int c)
{
  write(1, &c, 1);
  return (0);
}

void			my_memset(char *str, int octet, int size)
{
  int			i;

  i = 0;
  while (i < size)
    {
      str[i] = octet;
      i++;
    }
}
