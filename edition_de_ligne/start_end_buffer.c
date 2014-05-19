/*
** start_end_buffer.c for start_end_buffer in /home/wallet_v/42sh_edition_historique
** 
** Made by valentin wallet
** Login   <wallet_v@epitech.net>
** 
** Started on  Mon May 19 15:12:22 2014 valentin wallet
** Last update Mon May 19 16:24:44 2014 valentin wallet
*/

#include "termcap.h"

char			*start_of_buffer(char *str, t_cmd *data, int *x, struct winsize *mysizewin)
{
  while (*x > 3)
    move_left(data, x, mysizewin);
  return (str);
}

char			*end_of_buffer(char *str, t_cmd *data, int *x, struct winsize *mysizewin)
{
  int			k;

  k = *x - 3;
  while (k < my_strlen(str))
    {
      move_right(data, x, str, mysizewin);
      k++;
    }
  return (str);
}
