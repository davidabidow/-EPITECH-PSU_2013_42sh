/*
** termcap.h for termcap in /home/wallet_v/42sh_termcap
** 
** Made by valentin wallet
** Login   <wallet_v@epitech.net>
** 
** Started on  Wed May  7 19:08:59 2014 valentin wallet
<<<<<<< HEAD
** Last update Sun May 25 21:49:55 2014 david tran
=======
** Last update Sun May 25 21:49:35 2014 valentin wallet
>>>>>>> bdb91a85c333d4e5b8e3c1b97a8bf9d20678aa29
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

typedef struct		s_data
{
  int			id;
  char			*(*ptr)(char *str, t_cmd *data, int *x,
				struct winsize *mysizewin);
}			t_data;

extern	t_data		tab[];

void			ctrl_l(char *, t_cmd *);
char			*ctrl_k(char *, t_cmd *, int *);
char			*ctrl_y(char *, char *, int *, t_cmd *);
char			*include_in_line(char *, int, int *, t_cmd *);
int			my_putchar2(int);
char			*backslash_n(t_termcap *, t_history **);
char			*start_of_buffer(char *, t_cmd *, int *,
					 struct winsize *);
char			*end_of_buffer(char *, t_cmd *, int *,
				       struct winsize *);
char			*go_left(char *, t_cmd *, int *, struct winsize *);
char			*go_right(char *, t_cmd *, int *, struct winsize *);
char			*my_suppr(char *, t_cmd *, int *, struct winsize *);
char			*my_del(char *, t_cmd *, int *, struct winsize *);
char			*my_strcat_int(char *, int);
void			my_tgetstr(t_cmd *);
int			set_term_mode(struct termios *, t_env *);
void			move_left(t_cmd *, int *, struct winsize *);
void			move_right(t_cmd *, int *, char *, struct winsize *);
t_history		*load_history(t_history *);
char			**my_str_to_wordtab(char *, char *);
t_history		*my_put_in_end_list(t_history * , char *);
t_history		*my_put_in_list(t_history *, char *);
int			put_in_hist(t_history *, char *);
char			*history_down(t_history **, t_termcap *,
				      struct winsize *);
char			*history_up(t_history **, t_termcap *,
				    struct winsize *);
t_history		*go_end_list(t_history *);
void			free_list(t_history *);
char			*my_read(struct winsize *, t_history **, t_termcap *);
char			**init_buffer(struct winsize *, t_loop *,
				      struct termios *, t_env *);
int			parcours_ptr_func(t_termcap *, struct winsize *, int *);

#endif /* TERMCAP_H_ */
