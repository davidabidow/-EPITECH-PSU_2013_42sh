/*
** main.c for 42sh in /home/tran_0/rendu/rendugit/PSU_2013_42sh/src
** 
** Made by david tran
** Login   <tran_0@epitech.net>
** 
** Started on  Mon May  5 18:48:27 2014 david tran
** Last update Sun May 25 08:36:39 2014 david tran
*/

#include "42sh.h"
#include "my.h"

int		infinite_loop_feed(t_loop *loop, t_env *list)
{
  initloop(&loop->min, &loop->max);
  if (!(loop->dest = init_buffer(&loop->mysizewin,
				 loop, &loop->t, list)))
    {
      tcsetattr(0, TCSANOW, &loop->tsave);
      return (-1);
    }
  tcsetattr(0, TCSANOW, &loop->tsave);
  while (loop->max != my_strstrlen(loop->dest))
    {
      loop->max = countpvir(loop->dest, loop->max);
      if (!(loop->new = tab_wordtab(loop->dest, loop->min, loop->max)))
	return (-1);
      if ((loop->tmp = exit_or_nothing(loop->new[0], loop->new[1])) == -1)
	return (-1);
      else if (loop->tmp == EXIT_FAILURE)
	{
	  if (parsing_exec(loop->new, list) == -1)
	    return (-1);
	}
      loop->min = loop->max + 1;
      free_wordtab(loop->new);
    }
  free_wordtab(loop->dest);
  return (EXIT_SUCCESS);
}

int		main(int ac __attribute__((unused)), char **av
		     __attribute__((unused)), char **env)
{
  t_env		*list;

  woexit = EXIT_SUCCESS;
  if ((list = malloc(sizeof(*list))) == NULL)
    return (EXIT_FAILURE);
  list->head = NULL;
  list->end = NULL;
  list->head = NULL;
  signal(SIGINT, dontquit);
  if (init_list(list, env) == EXIT_FAILURE)
    return (EXIT_FAILURE);
  infiniteloop(list);
  if (list && list->head)
    free_env_list(list);
  return (woexit);
}
