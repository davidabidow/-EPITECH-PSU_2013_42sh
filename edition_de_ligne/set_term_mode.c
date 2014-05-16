/*
** set_term_mode.c for set_term_mode in /home/wallet_v/42sh_termcap
** 
** Made by valentin wallet
** Login   <wallet_v@epitech.net>
** 
** Started on  Wed May  7 19:18:28 2014 valentin wallet
** Last update Wed May  7 19:41:36 2014 valentin wallet
*/

#include "termcap.h"

int                     echo_mode(struct termios *t)
{
  t->c_lflag &= ~ECHO;
  if ((tcsetattr(0, TCSANOW, t)) == -1)
    {
      my_putstr("tcsetattr error\n");
      return (1);
    }
}

int			echo_mode2(struct termios *t)
{
  t->c_lflag = ICANON;
  t->c_lflag = ECHO;
  if ((tcsetattr(0, TCSANOW, t)) == -1)
    {
      my_putstr("tcsetattr error\n");
      return (1);
    }
}

int                     raw_mode(struct termios *t)
{
  t->c_lflag &= ~ICANON;
  t->c_cc[VMIN] = 1;
  t->c_cc[VTIME] = 0;
  if ((tcsetattr(0, TCSANOW, t)) == -1)
    {
      my_putstr("tcsetattr error\n");
      return (1);
    }
}

int			set_term_mode()
{
  struct termios	t;

  tgetent(NULL, "xterm");
  if ((tcgetattr(0, &t)) == -1)
    {
      my_putstr("tcgetattr error\n");
      return (EXIT_FAILURE);
    }
  if ((echo_mode(&t)) == 1)
    return (EXIT_FAILURE);
  if ((raw_mode(&t)) == 1)
    return (EXIT_FAILURE);
  return (EXIT_SUCCESS);
}
