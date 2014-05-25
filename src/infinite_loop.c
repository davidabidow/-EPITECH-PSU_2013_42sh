/*
** infinite_loop.c for 42sh in /home/tran_0/rendu/rendugit/PSU_2013_42sh
** 
** Made by david tran
** Login   <tran_0@epitech.net>
** 
** Started on  Thu May  8 18:34:21 2014 david tran
** Last update Sun May 25 18:25:30 2014 valentin wallet
*/

#include "42sh.h"
#include "my.h"
#include "termcap.h"

char		*transform_chain(char *str)
{
  if (!(str = epur_space(str)))
    return (NULL);
  else if (!(str = separate_char(str, ";")) ||
  	   !(str = separate_char(str, "<")) ||
  	   !(str = separate_char(str, ">")) ||
  	   !(str = separate_char(str, "&")) ||
  	   !(str = separate_char(str, "|")))
    return (NULL);
  return (str);
}

void		initloop(int *min, int *max)
{
  *min = 0;
  *max = 0;
  write(2, "$42sh> ", 7);
}

int		countpvir(char **src, int max)
{
  max++;
  while (src[max])
    {
      if (src[max][0] == ';')
	return (max);
      max += 1;
    }
  return (max);
}

char		**init_buffer(struct winsize *mysizewin, t_loop *loop,
			      struct termios *t, t_env *list)
{
  char		*buffer;
  char		**dest;

  if ((set_term_mode(t, list)) == 1)
    return (NULL);
  if ((buffer = my_read(mysizewin, &loop->history, &loop->term, t)) == NULL)
    return (NULL);
  if (!(buffer = transform_chain(buffer)))
    return (NULL);
  if (!(dest = wordtab(buffer, " ")))
    return (NULL);
  return (dest);
}

void			infiniteloop(t_env *list)
{
  t_loop		loop;
  char			*str;

  loop.history = NULL;
  loop.term.tmp = NULL;
  str = recupvar(list, "TERM");
  tgetent(NULL, str);
  if ((tcgetattr(0, &loop.tsave)) == -1)
    return ;
  my_tgetstr(&loop.term.data);
  loop.history = load_history(loop.history);
  while (42)
    if (infinite_loop_feed(&loop, list) == -1)
      return ;
}
