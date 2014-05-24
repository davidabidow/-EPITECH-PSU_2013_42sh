/*
** termcap.h for termcap in /home/wallet_v/42sh_termcap
** 
** Made by valentin wallet
** Login   <wallet_v@epitech.net>
** 
** Started on  Wed May  7 19:08:59 2014 valentin wallet
** Last update Sat May 24 03:16:11 2014 valentin wallet
*/

#ifndef TERMCAP_H_
# define TERMCAP_H_

# define UNUSED		__attribute__ ((unused))
# define BUFF_SIZE	1024
# define PROMPT_SIZE	7
# define CTRL_K		11
# define CTRL_Y		25
# define CTRL_L		12
# define BACKSLASH_N	10
# define UP		4283163
# define DOWN		4348699
# undef  tab

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

typedef struct		s_termcap
{
  t_cmd			data;
  char			*str;
  char			*tmp;
  int			buff;
  int			x;
}			t_termcap;

typedef struct		s_history
{
  char			*str;
  struct s_history	*next;
  struct s_history	*previous;
}			t_history;

typedef struct		s_data
{
  int			id;
  char			*(*ptr)(char *str, t_cmd *data, int *x, struct winsize *mysizewin);
}			t_data;

extern	t_data		tab[];

char			*ctrl_k(char *, t_cmd *, int *);
char			*ctrl_y(char *, char *, int *, t_cmd *);
char			*include_in_line(char *, int, int *, t_cmd *);
int			my_putchar2(int);
char			*backslash_n(t_termcap *, t_history **);
char			*start_of_buffer(char *, t_cmd *, int *, struct winsize *);
char			*end_of_buffer(char *, t_cmd *, int *, struct winsize *);
char			*go_left(char *, t_cmd *, int *, struct winsize *);
char			*go_right(char *, t_cmd *, int *, struct winsize *);
char			*my_suppr(char *, t_cmd *, int *, struct winsize *);
char			*my_del(char *, t_cmd *, int *, struct winsize *);
void			my_putstr(char *);
void			my_putchar(char);
int			my_strlen(char *);
char			*my_strcat_int(char *, int);
void			my_tgetstr(t_cmd *);
int			set_term_mode();
void			move_left(t_cmd *, int *, struct winsize *);
void			move_right(t_cmd *, int *, char *, struct winsize *);
t_history		*load_history(t_history *);
char			**my_str_to_wordtab(char *, char *);
t_history		*my_put_in_end_list(t_history * , char *);
t_history		*my_put_in_list(t_history *, char *);
int			put_in_hist(t_history *, char *);
char			*history_down(t_history **, t_termcap *, struct winsize *);
char			*history_up(t_history **, t_termcap *, struct winsize *);
t_history		*go_end_list(t_history *);
void			free_list(t_history *);
char			*my_read(struct winsize *, t_history *, t_termcap *);

#endif /* TERMCAP_H_ */
