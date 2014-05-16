/*
** deplacement.c for deplacement in /home/wallet_v/42sh_termcap
** 
** Made by valentin wallet
** Login   <wallet_v@epitech.net>
** 
** Started on  Wed May  7 19:15:44 2014 valentin wallet
** Last update Wed May 14 15:01:50 2014 valentin wallet
*/

#include "termcap.h"

int                     my_putchar2(int c)
{
  write(1, &c, 1);
  return (0);
}

void			go_left(t_cmd *data, int *x, struct winsize *mysizewin)
{
  int			k;

  if ((*x % mysizewin->ws_col) == 0)
    {
      tputs(data->curse_up, 1, my_putchar2);
      *x = *x - 1;
      k = 0;
      while (k < mysizewin->ws_col)
	{
	  tputs(data->curse_r, 1, my_putchar2);
	  k++;
	}
    }
  else if (*x > 3)
    {
      *x = *x - 1;
      tputs(data->curse_l, 1, my_putchar2);
    }
}

void			go_right(t_cmd *data, int *x, struct winsize *mysizewin, int i)
{
  if (((*x + 1) % mysizewin->ws_col) == 0)
    {
      write(1, "\n", 1);
      *x = *x + 1;
    }
  else if ((*x - 3) < i)
    {
      *x = *x + 1;
      tputs(data->curse_r, 1, my_putchar2);
    }
}
