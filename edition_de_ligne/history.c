/*
** history.c for 42sh in /home/lacour_a/Dropbox/42sh/lacour_a
**
** Made by arthur lacour
** Login   <lacour_a@epitech.net>
**
** Started on  Wed May  7 11:55:17 2014 arthur lacour
** Last update Thu May 22 22:01:43 2014 valentin wallet
*/

#include "termcap.h"

char		**read_history(int fd)
{
  int		ret;
  char		**my_tab;
  char		*str;
  char		buff[BUFF_SIZE];

  str = malloc(sizeof(char) * BUFF_SIZE);
  if (str == NULL)
    return (NULL);
  memset(str, '\0', BUFF_SIZE - 1);
  while ((ret = read(fd, buff, BUFF_SIZE - 1)) > 0)
    {
      buff[ret] = '\0';
      str = realloc(str, my_strlen(str) + my_strlen(buff) + 1);
      str = strcat(str, buff);
    }
  my_tab = my_str_to_wordtab(str, "\n");
  free(str);
  return (my_tab);
}

void		free_tab(char **my_tab)
{
  int		i;

  i = 0;
  while (my_tab[i])
    {
      free(my_tab[i]);
      ++i;
    }
  free(my_tab);
}

t_history	*put_hist_in_list(t_history *history, char **my_tab)
{
  int		i;

  i = 0;
  if (my_tab == NULL)
    return (history);
  while (my_tab[i])
    {
      history = my_put_in_end_list(history, strdup(my_tab[i]));
      ++i;
    }
  if (history)
    while (history->previous != NULL)
      history = history->previous;
  return (history);
}

t_history	*load_history(t_history *history)
{
  int		fd;
  char		**my_tab;

  if ((fd = open(".42sh_history", O_CREAT | O_RDWR,
	    0600)) == -1)
    return (history);
  if ((my_tab = read_history(fd)) == NULL)
    return (history);
  history = put_hist_in_list(history, my_tab);
  close(fd);
  free_tab(my_tab);
  history = go_end_list(history);
  return (history);
}

int		put_in_hist(t_history *history, char *str)
{
  int		fd;

  fd = open(".42sh_history", O_APPEND | O_CREAT | O_RDWR,
	    0600);
  if (fd == -1)
    return (-1);
  history = my_put_in_end_list(history, str);
  write(fd, str, my_strlen(str));
  write(fd, "\n", 1);
  close(fd);
  return (0);
}
