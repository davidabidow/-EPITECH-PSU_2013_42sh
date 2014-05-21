/*
** main.c for main in /home/wallet_v/42sh_termcap
** 
** Made by valentin wallet
** Login   <wallet_v@epitech.net>
** 
** Started on  Fri Apr 25 17:04:02 2014 valentin wallet
** Last update Wed May 21 19:22:29 2014 valentin wallet
*/

#include "termcap.h"

char			*backslash_n(char *str, t_cmd *data UNUSED, int *x, struct winsize *mysizewin UNUSED)
{
  char			*newstr;

  write(1, "\n", 1);
  my_putstr("$> ");
  my_putstr(str);
  my_putchar('\n');
  my_putstr("$> ");
  *x = PROMPT_SIZE;
  newstr = malloc(sizeof(char) * 7);
  memset(newstr, 0, 7);
  return (newstr);
}

char			*write_normally(char *str, int buff, int *x, t_cmd *data)
{
  if (my_strlen(str) == (*x - PROMPT_SIZE))
    str = my_strcat(str, buff);
  else
    str = include_in_line(str, buff, x, data);
  *x = *x + 1;
  return (str);
}

void			parcours_ptr_func(t_termcap *term, struct winsize *mysizewin, int *count)
{
  int			i;

  i = 0;
  while (tab[i].ptr != NULL)
    {
      if (term->buff == tab[i].id)
	{
	  term->str = tab[i].ptr(term->str, &term->data, &term->x, mysizewin);
	  (*count)++;
	}
      i++;
    }
}

void			initialize_struct(t_termcap *term)
{
  term->str = NULL;
  term->tmp = NULL;
  term->buff = 0;
  term->x = PROMPT_SIZE;
  term->str = malloc(sizeof(char) * 7);
  memset(term->str, 0, 7);
}

void			ctrl_l(char *str, t_cmd *data)
{
  tputs(data->clearstr, 1, my_putchar2);
  my_putstr("$> ");
  my_putstr(str);
}

void			my_read(struct winsize *mysizewin, t_history *history, t_termcap *term)
{
  int			count;

  initialize_struct(term);
  ioctl(STDOUT_FILENO, TIOCGWINSZ, mysizewin);
  while ((read(0, &term->buff, sizeof(int))) != 0)
    {
      count = 0;
      parcours_ptr_func(term, mysizewin, &count);
      if (term->buff == CTRL_K)
      	term->tmp = ctrl_k(term->str, &term->data, &term->x, mysizewin);
      else if (term->buff == CTRL_Y && term->tmp != NULL)
	term->str = ctrl_y(term->str, term->tmp, &term->x, &term->data);
      else if (term->buff == CTRL_L)
	ctrl_l(term->str, &term->data);
      else if (term->buff == DOWN)
      	term->str = history_down(&history, term->str, &term->data, &term->x, mysizewin);
      else if (term->buff == UP)
      	term->str = history_up(&history, term->str, &term->data , &term->x, mysizewin);
      else if (term->buff == BACKSLASH_N)
	{
	  put_in_hist(history, term->str);
	  history = go_end_list(history);
	  term->str = backslash_n(term->str, &term->data, &term->x, mysizewin);
	}
      else if (count == 0)
	term->str = write_normally(term->str, term->buff, &term->x, &term->data);
      term->buff = 0;
    }
}

int			main(int ac UNUSED, char **av UNUSED, char **env)
{
  t_termcap		term;
  struct winsize        mysizewin;
  t_history		*history;

  history = NULL;
  if (set_term_mode(env) == 1)
    return (EXIT_FAILURE);
  my_tgetstr(&term.data);
  history = load_history(history);
  my_putstr("$> ");
  my_read(&mysizewin, history, &term);
  free_list(history);
  return (EXIT_SUCCESS);
}
