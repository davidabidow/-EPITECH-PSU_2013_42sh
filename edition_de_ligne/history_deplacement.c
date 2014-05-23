/*
** history_deplacement.c for history_deplacement in /home/wallet_v/42sh_edition_historique/arthur
**
** Made by valentin wallet
** Login   <wallet_v@epitech.net>
**
** Started on  Mon May 19 17:54:09 2014 valentin wallet
** Last update Fri May 23 01:11:50 2014 valentin wallet
*/

#include "termcap.h"

void		clean_buffer(t_termcap *term, struct winsize *mysizewin)
{
  int		i;

  i = 0;
  while (term->x > PROMPT_SIZE)
    {
      move_left(&term->data, &term->x, mysizewin);
      i++;
    }
  tputs(term->data.save, 1, my_putchar2);
  while (i > 0)
    {
      write(1, " ", 1);
      i--;
    }
  tputs(term->data.restor, 1, my_putchar2);
}

char		*history_up(t_history **history, t_termcap *term, struct winsize *mysizewin)
{
  t_history     *tmp;

  if (*history)
    {
      tmp = (*history);
      if ((*history)->previous)
        (*history) = (*history)->previous;
      clean_buffer(term, mysizewin);
      my_putstr(tmp->str);
      term->x = term->x + my_strlen(tmp->str);
      return (tmp->str);
    }
  return (term->str);
}

char		*history_down(t_history **history, t_termcap *term, struct winsize *mysizewin)
{
  if (*history)
    {
      if ((*history)->next)
        (*history) = (*history)->next;
      else
        {
	  clean_buffer(term, mysizewin);
	  my_putstr(term->str);
	  term->x = term->x + my_strlen(term->str);
          return ("\0");
        }
      clean_buffer(term, mysizewin);
      my_putstr((*history)->str);
      term->x = term->x + my_strlen((*history)->str);
      return ((*history)->str);
    }
  return (term->str);
}
