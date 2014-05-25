/*
** start_end_buffer.c for start_end_buffer in /home/wallet_v/42sh_edition_historique
** 
** Made by valentin wallet
** Login   <wallet_v@epitech.net>
** 
** Started on  Mon May 19 15:12:22 2014 valentin wallet
** Last update Sun May 25 21:50:31 2014 valentin wallet
*/

#include "42sh.h"
#include "my.h"

char			*start_of_buffer(char *str, t_cmd *data,
					 int *x, struct winsize *mysizewin)
{
  while (*x > PROMPT_SIZE)
    move_left(data, x, mysizewin);
  return (str);
}

char			*end_of_buffer(char *str, t_cmd *data,
				       int *x, struct winsize *mysizewin)
{
  int			k;

  k = *x - PROMPT_SIZE;
  while (k < my_strlen(str))
    {
      move_right(data, x, str, mysizewin);
      k++;
    }
  return (str);
}
