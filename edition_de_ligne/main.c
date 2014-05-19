/*
** main.c for main in /home/wallet_v/42sh_termcap
** 
** Made by valentin wallet
** Login   <wallet_v@epitech.net>
** 
** Started on  Fri Apr 25 17:04:02 2014 valentin wallet
** Last update Mon May 19 21:30:32 2014 valentin wallet
*/

#include "termcap.h"


char			*backslash_n(char *str, t_cmd *data UNUSED, int *x, struct winsize *mysizewin UNUSED)
{
  write(1, "\n", 1);
  my_putstr("$> ");
  my_putstr(str);
  my_putchar('\n');
  my_putstr("$> ");
  *x = 3;
  free(str);
  return (str);
}

void			my_read(t_cmd *data, struct winsize *mysizewin, t_history *history)
{
  int			count;
  int			x;
  int			i;
  char			*str;
  int			buff;
  char			*tmp;
  int			readed;
  
  str = NULL;
  tmp = NULL;
  x = 3;
  str = malloc(sizeof(char) * 7);
  memset(str, 0, 7);
  buff = 0;
  while ((readed = read(0, &buff, 10)) != 0)
    {
      count = 0;
      ioctl(STDOUT_FILENO, TIOCGWINSZ, mysizewin);
      i = 0;
      while (tab[i].ptr != NULL)
	{
	  if (buff == tab[i].id)
	    {
	      str = tab[i].ptr(str, data, &x, mysizewin);
	      count++;
	    }
	  i++;
	}
      if (buff == 11)
      	tmp = ctrl_k(str, data, &x, mysizewin);
      else if (buff == 25)
      	{
      	  if (tmp != NULL)
      	    str = ctrl_y(str, tmp, &i, &x, data);
      	  x = x + my_strlen(tmp);
      	}
      /* else if (buff == 4348699) */
      /* 	str = history_down(&history, str, data, &x, mysizewin); */
      /* else if (buff == 4283163) */
      /* 	str = history_up(&history, str, data , &x, mysizewin); */
      else if (count == 0)
	{
	  if (my_strlen(str) == (x - 3))
	    str = my_strcat(str, buff);
	  else
	    str = include_in_line(str, buff, &x, data);
	  x = x + 1;
	}
      buff = 0;
    }
}

int			main(int ac UNUSED, char **av UNUSED, char **env)
{
  t_cmd			data;
  struct winsize        mysizewin;
  t_history		*history;

  history = NULL;
  set_term_mode();
  my_tgetstr(&data);
  history = load_history(history);
  my_putstr("$> ");
  my_read(&data, &mysizewin, history);
  free_list(history);
  return (EXIT_SUCCESS);
}
