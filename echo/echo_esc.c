/*
** echo_print.c for 42sh in /home/lacour_a/rendu
**
** Made by arthur lacour
** Login   <lacour_a@epitech.net>
**
** Started on  Fri May 23 17:00:53 2014 arthur lacour
** Last update Sat May 24 07:32:52 2014 david tran
*/

#include "42sh.h"
#include "my.h"

int	put_esc_char(char *str, int *i)
{
  char	esc;

  esc = '\\';
  (*i)++;
  if (str[*i] == 'a')
    esc = '\a';
  else if (str[*i] == 'b')
    esc = '\b';
  else if (str[*i] == 't')
    esc = '\t';
  else if (str[*i] == 'n')
    esc = '\n';
  else if (str[*i] == 'v')
    esc = '\v';
  else if (str[*i] == 'f')
    esc = '\f';
  else if (str[*i] == 'r')
    esc = '\r';
  my_putchar(esc);
  (*i)++;
  return (0);
}

int	put_one_esc(char *str, t_env **list)
{
  int	i;

  i = 0;
  while (str[i])
    {
      if (str[i] == '$')
        if (put_env_var(str, &i, list) == -1)
          return (-1);
      if (str[i] == '\\')
        put_esc_char(str, &i);
      my_putchar(str[i]);
      if (str[i])
        ++i;
    }
  return (0);
}

void	esc_char(char **tab, t_env **list)
{
  int	i;

  i = 0;
  while (tab[i])
    {
      put_one_esc(tab[i], list);
      my_putchar(' ');
      ++i;
    }
}
