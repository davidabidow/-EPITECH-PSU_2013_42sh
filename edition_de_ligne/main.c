/*
** main.c for main in /home/wallet_v/42sh_termcap
** 
** Made by valentin wallet
** Login   <wallet_v@epitech.net>
** 
** Started on  Fri Apr 25 17:04:02 2014 valentin wallet
** Last update Sun May 25 21:49:36 2014 valentin wallet
*/

#include "42sh.h"
#include "my.h"

char			*write_normally(char *str, int buff, int *x,
					t_cmd *data)
{
  if (my_strlen(str) == (*x - PROMPT_SIZE))
    str = my_strcat_int(str, buff);
  else
    str = include_in_line(str, buff, x, data);
  *x = *x + 1;
  return (str);
}

int			initialize_struct(t_termcap *term)
{
  term->str = NULL;
  term->buff = 0;
  term->x = PROMPT_SIZE;
  if ((term->str = malloc(sizeof(char) * 7)) == NULL)
    return (EXIT_FAILURE);
  memset(term->str, 0, 7);
  return (EXIT_SUCCESS);
}

char			*backslash_n(t_termcap *term, t_history **history)
{
  put_in_hist((*history), term->str);
  (*history) = go_end_list((*history));
  write(1, "\n", 1);
  term->x = PROMPT_SIZE;
  return (term->str);
}

void			edition(t_termcap *term, t_history **history,
				struct winsize *mysizewin, int count)
{
  if (term->buff == CTRL_K)
    term->tmp = ctrl_k(term->str, &term->data, &term->x);
  else if (term->buff == CTRL_Y)
    {
      if (term->tmp != NULL)
	term->str = ctrl_y(term->str, term->tmp, &term->x, &term->data);
    }
  else if (term->buff == CTRL_L)
    ctrl_l(term->str, &term->data);
  else if (term->buff == DOWN)
    term->str = history_down(history, term, mysizewin);
  else if (term->buff == UP)
    term->str = history_up(history, term, mysizewin);
  else if (count == 0)
    term->str = write_normally(term->str, term->buff, &term->x, &term->data);
}

char			*my_read(struct winsize *mysizewin,
				 t_history **history, t_termcap *term)
{
  int			count;

  if ((initialize_struct(term)) == 1)
    return (NULL);
  ioctl(STDOUT_FILENO, TIOCGWINSZ, mysizewin);
  while ((read(0, &term->buff, sizeof(int))) != 0)
    {
      count = 0;
      parcours_ptr_func(term, mysizewin, &count);
      if (term->buff == 4)
	return (NULL);
      else if (term->str == NULL)
	return (NULL);
      else if (term->buff == BACKSLASH_N)
	{
	  term->str = backslash_n(term, history);
	  return (term->str);
	}
      else
	edition(term, history, mysizewin, count);
      term->buff = 0;
    }
  return (NULL);
}
