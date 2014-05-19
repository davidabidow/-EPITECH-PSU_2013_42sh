/*
** history_deplacement.c for history_deplacement in /home/wallet_v/42sh_edition_historique/arthur
** 
** Made by valentin wallet
** Login   <wallet_v@epitech.net>
** 
** Started on  Mon May 19 17:54:09 2014 valentin wallet
** Last update Mon May 19 19:58:42 2014 valentin wallet
*/

#include "termcap.h"

void		clean_buffer(t_cmd *data, int *x, struct winsize *mysizewin)
{
  while (*x > 3)
    {
      move_left(data, x, mysizewin);
      write(1, " ", 1);
      move_left(data, x, mysizewin);
    }
}

char		*history_up(t_history **history, char *str, t_cmd *data, int *x, struct winsize *mysizewin)
{
  if (*history)
    {
      if ((*history)->previous)
	*history = (*history)->previous;
      my_putstr((*history)->str);
      return ((*history)->str);
    }
  return (str);
}

char		*history_down(t_history **history, char *str, t_cmd *data, int *x, struct winsize *mysizewin)
{
  if (*history)
    {
      if ((*history)->next)
	*history = (*history)->next;
      my_putstr((*history)->str);
      return ((*history)->str);
    }
  return (str);
}
