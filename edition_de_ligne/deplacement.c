/*
** deplacement.c for deplacement in /home/wallet_v/42sh_termcap
** 
** Made by valentin wallet
** Login   <wallet_v@epitech.net>
** 
** Started on  Wed May  7 19:15:44 2014 valentin wallet
** Last update Mon May 19 16:23:39 2014 valentin wallet
*/

#include "termcap.h"

void			move_left(t_cmd *data, int *x, struct winsize *mysizewin)
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

void			move_right(t_cmd *data, int *x, char *str, struct winsize *mysizewin)
{
  if (((*x + 1) % mysizewin->ws_col) == 0)
    {
      write(1, "\n", 1);
      *x = *x + 1;
    }
  else if ((*x - 3) < (my_strlen(str)))
    {
      *x = *x + 1;
      tputs(data->curse_r, 1, my_putchar2);
    }
}
char			*go_left(char *str, t_cmd *data, int *x, struct winsize *mysizewin)
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
  return (str);
}

char			*go_right(char *str, t_cmd *data, int *x, struct winsize *mysizewin)
{
  if (((*x + 1) % mysizewin->ws_col) == 0)
    {
      write(1, "\n", 1);
      *x = *x + 1;
    }
  else if ((*x - 3) < (my_strlen(str)))
    {
      *x = *x + 1;
      tputs(data->curse_r, 1, my_putchar2);
    }
  return (str);
}
