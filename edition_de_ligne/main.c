/*
** main.c for main in /home/wallet_v/42sh_termcap
** 
** Made by valentin wallet
** Login   <wallet_v@epitech.net>
** 
** Started on  Fri Apr 25 17:04:02 2014 valentin wallet
** Last update Fri May 23 00:54:16 2014 valentin wallet
*/

#include "termcap.h"

char			*write_normally(char *str, int buff, int *x, t_cmd *data)
{
  if (my_strlen(str) == (*x - PROMPT_SIZE))
    str = my_strcat(str, buff);
  else
    str = include_in_line(str, buff, x, data);
  *x = *x + 1;
  return (str);
}

int			parcours_ptr_func(t_termcap *term, struct winsize *mysizewin, int *count)
{
  int			i;

  i = 0;
  while (tab[i].ptr != NULL)
    {
      if (term->buff == tab[i].id)
	{
	  if ((term->str = tab[i].ptr(term->str, &term->data, &term->x, mysizewin)) == NULL)
	    return (EXIT_FAILURE);
	  (*count)++;
	}
      i++;
    }
}

int			initialize_struct(t_termcap *term)
{
  term->str = NULL;
  term->tmp = NULL;
  term->buff = 0;
  term->x = PROMPT_SIZE;
  if ((term->str = malloc(sizeof(char) * 7)) == NULL)
    return (EXIT_FAILURE);
  memset(term->str, 0, 7);
  return (EXIT_SUCCESS);
}

void			ctrl_l(char *str, t_cmd *data)
{
  tputs(data->clearstr, 1, my_putchar2);
  my_putstr("$> ");
  my_putstr(str);
}

char			*backslash_n(t_termcap *term, t_history **history)
{
  char			*newstr;

  put_in_hist((*history), term->str);
  (*history) = go_end_list((*history));
  write(1, "\n", 1);
  my_putstr("$> ");
  my_putstr(term->str);
  my_putchar('\n');
  my_putstr("$> ");
  term->x = PROMPT_SIZE;
  if ((newstr = malloc(sizeof(char) * 7)) == NULL)
    return (NULL);
  memset(newstr, 0, 7);
  return (newstr);
}


int			my_read(struct winsize *mysizewin, t_history *history, t_termcap *term)
{
  int			count;

  if ((initialize_struct(term)) == 1)
    return (EXIT_FAILURE);
  ioctl(STDOUT_FILENO, TIOCGWINSZ, mysizewin);
  while ((read(0, &term->buff, sizeof(int))) != 0)
    {
      count = 0;
      parcours_ptr_func(term, mysizewin, &count);
      if (term->buff == CTRL_K)
      	term->tmp = ctrl_k(term->str, &term->data, &term->x);
      else if (term->buff == CTRL_Y && term->tmp != NULL)
	term->str = ctrl_y(term->str, term->tmp, &term->x, &term->data);
      else if (term->buff == CTRL_L)
	ctrl_l(term->str, &term->data);
      else if (term->buff == DOWN)
      	term->str = history_down(&history, term, mysizewin);
      else if (term->buff == UP)
      	term->str = history_up(&history, term, mysizewin);
      else if (term->buff == BACKSLASH_N)
	term->str = backslash_n(term, &history);
      else if (count == 0)
	term->str = write_normally(term->str, term->buff, &term->x, &term->data);
      if (term->str == NULL)
	return (EXIT_FAILURE);
      term->buff = 0;
    }
  return (EXIT_SUCCESS);
}

int			main(int ac UNUSED, char **av UNUSED, char **env)
{
  t_termcap		term;
  struct winsize        mysizewin;
  t_history		*history;

  history = NULL;
  if ((set_term_mode(env)) == 1)
    return (EXIT_FAILURE);
  my_tgetstr(&term.data);
  history = load_history(history);
  my_putstr("$> ");
  my_read(&mysizewin, history, &term);
  free_list(history);
  return (EXIT_SUCCESS);
}
