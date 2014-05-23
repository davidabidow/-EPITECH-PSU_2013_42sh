/*
** echo.c for 42sh in /home/lacour_a/42sh_edition_historique/arthur
**
** Made by arthur lacour
** Login   <lacour_a@epitech.net>
**
** Started on  Wed May 21 11:56:05 2014 arthur lacour
** Last update Fri May 23 17:03:21 2014 arthur lacour
*/

#include <stdlib.h>
#include <string.h>

int	put_env_var(char *str, int *i)
{
  int	j;
  int	save;
  char	*env_var;
  char	*value;

  j = 0;
  save = *i;
  while (str[save] != ' ')
    save++;
  env_var = malloc(sizeof(char) * (save - *i) + 1);
  if (env_var == NULL)
    return (-1);
  while (*i <= save)
    {
      env_var[j] = str[*i];
      j++;
      (*i)++;
    }
  value = getenv(env_var);
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

int	one_str_normal(char *str, char **env)
{
  int	i;

  i = 0;
  while (str[i])
    {
      if (str[i] == '$')
	if (put_env_var(str, &i) == -1)
	  return (-1);
      my_putchar(str[i]);
      ++i;
    }
  return (0);
}

int	put_normal(char **tab, char **env)
{
  int	i;

  i = 0;
  while (tab[i])
    {
      one_str_normal(tab[i], env);
      my_putchar(' ');
      ++i;
    }
  return (0);
}

int	my_echo(char **env, char **tab)
{
  int	ret;
  int	esc;

  ret = check_opt(tab, 1);
  esc = check_opt(tab, 2);
  if (esc == 1)
    {
      if (ret == 1)
	esc_char(tab + 2, env);
      else
	esc_char(tab + 1, env);
    }
  else
    {
      if (ret == 1)
	put_normal(tab + 1, env);
      else
	put_normal(tab, env);
    }
  if (ret == 0)
    write(1, "\n", 1);
}
