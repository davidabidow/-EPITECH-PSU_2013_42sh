/*
** termcap.h for termcap in /home/wallet_v/42sh_termcap
** 
** Made by valentin wallet
** Login   <wallet_v@epitech.net>
** 
** Started on  Wed May  7 19:08:59 2014 valentin wallet
** Last update Thu May 15 08:28:20 2014 valentin wallet
*/

#ifndef TERMCAP_H_
# define TERMCAP_H_

# include <stdio.h>
# include <string.h>
# include <signal.h>
# include <termcap.h>
# include <sys/ioctl.h>
# include <unistd.h>
# include <stdlib.h>

# define LEFT		(buff[0] == 27 && buff[1] == 91 && buff[2] == 68)
# define RIGHT		((buff[0] == 27) && (buff[1] == 91) && (buff[2] == 67))
# define BACKSLASH_N	(buff[0] == '\n')

typedef struct		s_cmd
{
  char			*save;
  char			*restor;
  char			*curse_r;
  char			*curse_l;
  char			*curse_up;
  char			*curse;
  char			*cursef;
  char			*clearstr;
  char			*gotostr;
  char			*standstr;
  char			*stendstr;
  char			*underlines;
  char			*underlinef;
  char			*suppline;
}			t_cmd;

char			*home_strcat(char *, char *, int *, int *, t_cmd *);
char			*include_in_line(char *, char *, int *, int *, t_cmd *);
int			my_putchar2(int);

#endif /* TERMCAP_H_ */
