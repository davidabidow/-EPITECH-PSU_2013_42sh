/*
** set_term_mode.c for set_term_mode in /home/wallet_v/42sh_termcap
** 
** Made by valentin wallet
** Login   <wallet_v@epitech.net>
** 
** Started on  Wed May  7 19:18:28 2014 valentin wallet
** Last update Sun May 25 18:14:48 2014 valentin wallet
*/

#include "42sh.h"
#include "my.h"

char			*recup_name(char *str)
{
  int			i;

  i = 0;
  while (str[i] != '=')
    i++;
  i = i + 1;
  return (&str[i]);
}

char			*my_getenv(char **env, char *str)
{
  int			i;

  i = 0;
  if (env == NULL)
    return (NULL);
  while (env[i] != NULL)
    {
      if (strncmp(env[i], str, my_strlen(str)) == 0)
	return (recup_name(env[i]));
      i++;
    }
  return (NULL);
}

int                     echo_mode(struct termios *t)
{
  t->c_lflag &= ~ECHO;
  if ((tcsetattr(0, TCSANOW, t)) == -1)
    {
      my_putstr("tcsetattr error\n");
      return (EXIT_FAILURE);
    }
  return (EXIT_SUCCESS);
}

int			echo_mode2(struct termios *t)
{
  t->c_lflag = ICANON;
  t->c_lflag = ECHO;
  if ((tcsetattr(0, TCSANOW, t)) == -1)
    {
      my_putstr("tcsetattr error\n");
      return (EXIT_FAILURE);
    }
  return (EXIT_SUCCESS);
}

int                     raw_mode(struct termios *t)
{
  t->c_lflag &= ~ICANON;
  t->c_cc[VMIN] = 1;
  t->c_cc[VTIME] = 0;
  if ((tcsetattr(0, TCSANOW, t)) == -1)
    {
      my_putstr("tcsetattr error\n");
      return (EXIT_FAILURE);
    }
  return (EXIT_SUCCESS);
}

int			set_term_mode(struct termios *t, t_env *list)
{
  if ((tcgetattr(0, t)) == -1)
    {
      my_putstr("tcgetattr error\n");
      return (EXIT_FAILURE);
    }
  if ((echo_mode(t)) == 1)
    return (EXIT_FAILURE);
  if ((raw_mode(t)) == 1)
    return (EXIT_FAILURE);
  return (EXIT_SUCCESS);
}
