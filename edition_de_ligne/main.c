/*
** main.c for main in /home/wallet_v/42sh_termcap
** 
** Made by valentin wallet
** Login   <wallet_v@epitech.net>
** 
** Started on  Fri Apr 25 17:04:02 2014 valentin wallet
** Last update Fri May 16 14:46:59 2014 valentin wallet
*/

#include "termcap.h"

void		my_tgetstr(t_cmd *data)
{
  data->curse = tgetstr("vi", NULL);
  data->cursef = tgetstr("ve", NULL);
  data->underlines = tgetstr("us", NULL);
  data->underlinef = tgetstr("ue", NULL);
  data->gotostr = tgetstr("cm", NULL);
  data->clearstr = tgetstr("cl", NULL);
  data->standstr = tgetstr("so", NULL);
  data->stendstr = tgetstr("se", NULL);
  data->curse_r = tgetstr("nd", NULL);
  data->curse_l = tgetstr("le", NULL);
  data->curse_up = tgetstr("up", NULL);
  data->save = tgetstr("sc", NULL);
  data->restor = tgetstr("rc", NULL);
  data->suppline = tgetstr("cd", NULL);
}

void			backslash_n(int *x, int *i, char *str)
{
  write(1, "\n", 1);
  my_putstr("$> ");
  my_putstr(str);
  my_putchar('\n');
  my_putstr("$> ");
  *x = 3;
  *i = 0;
  free(str);
}

int                     my_putchar3(int c)
{
  write(1, &c, 1);
  return (0);
}

void			my_memset(char *str, int octet, int size)
{
  int			i;
  
  i = 0;
  while (i < size)
    {
      str[i] = octet;
      i++;
    }
}

char			*my_del(int *x, int *i, t_cmd *data, char *str)
{
  char			*tmp;
  char			*newstr;
  char			*final;
  int			k;
  int			j;
  int			n;

  k = *x - 3;
  j = 0;
  if (my_strlen(str) == 0 || *x == 3)
    return (str);
  newstr = malloc(sizeof(char) * my_strlen(str));
  while (str[k] != '\0')
    newstr[j++] = str[k++];      
  newstr[j] = '\0';
  tputs(data->curse_l, 1, my_putchar2);
  my_putstr(newstr);
  write(1, " ", 1);
  tputs(data->curse_l, 1, my_putchar2);
  while (j > 0)
    {
      tputs(data->curse_l, 1, my_putchar2);
      j--;
    }
  tmp = malloc(sizeof(char) * (my_strlen(str)));
  n = 0;
  while (n != (*x - 4))
    tmp[n] = str[n++];
  tmp[n] = '\0';
  final = strcat(tmp, newstr);
  *i = *i - 1;
  *x = *x - 1;
  return (final);
}

char			*my_suppr(int *x, int *i, t_cmd *data, char *str)
{
  char			*final;
  char			*tmp;
  char			*newstr;
  int			k;
  int			j;
  int			m;

  k = *x - 2;
  j = 0;
  newstr = malloc(sizeof(char) * my_strlen(str));
  while (str[k] != '\0')
      newstr[j++] = str[k++];
  newstr[j] = '\0';
  tputs(data->suppline, 1, my_putchar2);
  my_putstr(newstr);
  write(1, " ", 1);
  tputs(data->curse_l, 1, my_putchar2);
  while (j > 0)
    {
      tputs(data->curse_l, 1, my_putchar2);
      j--;
    }
  tmp = malloc(sizeof(char) * my_strlen(str));
  m = 0;
  while (m != (*x - 3))
    tmp[m] = str[m++];
  tmp[m] = '\0';
  final = strcat(tmp, newstr);
  *i = *i - 1;
  free(str);
  return (final);
}

void			start_of_buffer(int *x, t_cmd *data)
{
  while (*x > 3)
    {
      tputs(data->curse_l, 1, my_putchar2);
      *x = *x - 1;
    }
}

void			end_of_buffer(int *x, int *i, t_cmd *data)
{
  int			k;

  k = *x - 3;
  while (k < *i)
    {
      tputs(data->curse_r, 1, my_putchar2);
      k++;
      *x = *x + 1;
    }
}

char			*ctrl_k(int *x, int *i, char *str, t_cmd *data)
{
  char			*buffer;
  char			*newstr;
  int			k;
  int			j;

  k = *x - 3;
  j = 0;
  if ((*x - 3) == *i)
    return (NULL);
  buffer = malloc(sizeof(char) * (my_strlen(str) + 1));
  while (str[k] != '\0')
    buffer[j++] = str[k++];
  str[(*x) - 3] = '\0';
}

void			my_read(t_cmd *data, struct winsize *mysizewin)
{
  int			x;
  int			i;
  char			*str;
  char			buff[11];
  char			*tmp;
  int			readed;
  
  str = NULL;
  tmp = NULL;
  i = 0;
  x = 3;
  str = malloc(sizeof(char) * 7);
  memset(str, 0, 7);
  while ((readed = read(0, buff, 10)) != 0)
    {
      ioctl(STDOUT_FILENO, TIOCGWINSZ, mysizewin);
      buff[readed] = '\0';
      //printf("%d-%d-%d-%d-%d-%d\n", buff[0], buff[1], buff[2], buff[3], buff[4], buff[5]);
      if (LEFT)
	go_left(data, &x, mysizewin);
      else if (RIGHT)
	go_right(data, &x, mysizewin, i);
      else if (BACKSLASH_N)
	backslash_n(&x, &i, str);
      else if (buff[0] == 127)
	str = my_del(&x, &i, data, str);
      else if (buff[0] == 27)
	str = my_suppr(&x, &i, data, str);
      else if ((buff[0] == 1) || ((buff[0] == 27) && (buff[1] == 79) && (buff[2] == 72)))
	start_of_buffer(&x, data);
      else if (buff[0] == 5)
	end_of_buffer(&x, &i, data);
      else if (buff[0] == 11)
	ctrl_k(&x, &i, str, data);
      else
	{
	  if (i == (x - 3))
	    str = home_strcat(str, buff, &i, &x, data);
	  else
	    str = include_in_line(str, buff, &i, &x, data);
	  x = x + 1;
	}
    }
}

int			main(int ac, char **av, char **env)
{
  int			i;
  int			readed;
  t_cmd			data;
  int			x;
  struct winsize        mysizewin;

  set_term_mode();
  my_tgetstr(&data);
  my_putstr("$> ");
  my_read(&data, &mysizewin);
}
