/*
** echo.c for 42sh in /home/lacour_a/42sh_edition_historique/arthur
**
** Made by arthur lacour
** Login   <lacour_a@epitech.net>
**
** Started on  Wed May 21 11:56:05 2014 arthur lacour
** Last update Sat May 24 17:04:20 2014 david tran
*/

#include "42sh.h"
#include "my.h"

int	put_env_var(char *str, int *i, t_env *list)
{
  int	j;
  int	save;
  char	*env_var;
  char	*value;

  j = 0;
  save = *i;
  while (str[save] != ' ')
    save++;
  env_var = my_xmalloc(sizeof(char) * (save - *i) + 1);
  if (env_var == NULL)
    return (-1);
  while (*i <= save)
    {
      env_var[j] = str[*i];
      j++;
      (*i)++;
    }
  value = recupvar(list, env_var);
  if (value != NULL)
    my_putstr(value);
  return (0);
}

int	check_opt(char **tab, char id)
{
  int	i;
  int	flag;

  i = 0;
  flag = 0;
  while (tab[i] && i < 2)
    {
      if (id == 1)
	if (strcmp(tab[i], "-n") == 0)
	  flag = 1;
      if (id == 2)
	if (strcmp(tab[i], "-e") == 0)
	  flag = 1;
      ++i;
    }
  return (flag);
}

int	one_str_normal(char *str, t_env *list)
{
  int	i;

  i = 0;
  while (str[i])
    {
      if (str[i] == '$')
	if (put_env_var(str, &i, list) == -1)
	  return (-1);
      my_putchar(str[i]);
      ++i;
    }
  return (0);
}

int	put_normal(char **tab, t_env *list)
{
  int	i;

  i = 0;
  while (tab[i])
    {
      one_str_normal(tab[i], list);
      my_putchar(' ');
      ++i;
    }
  return (0);
}

int	my_echo(t_env *list, char **tab)
{
  int	ret;
  int	esc;

  ret = check_opt(tab, 1);
  esc = check_opt(tab, 2);
  if (esc == 1)
    {
      if (ret == 1)
	esc_char(tab + 2, list);
      else
	esc_char(tab + 1, list);
    }
  else
    {
      if (ret == 1)
	put_normal(tab + 1, list);
      else
	put_normal(tab, list);
    }
  if (ret == 0)
    write(1, "\n", 1);
  return (EXIT_SUCCESS);
}
