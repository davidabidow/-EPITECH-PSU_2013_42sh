/*
** minishell2.h for minishell2 in /home/tran_0/rendu/PSU_2013_minishell2
** 
** Made by david tran
** Login   <tran_0@epitech.net>
** 
** Started on  Thu Jan 23 13:32:34 2014 david tran
** Last update Mon May  5 21:55:01 2014 david tran
*/

#ifndef _MINISHELL_H_
# define _MINISHELL_H_

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <signal.h>
# include <sys/wait.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

typedef struct	s_data
{
  char		*data;
  struct s_data	*next;
  struct s_data	*prev;
  struct s_data	*head;
  struct s_data	*end;
}		t_data;

typedef struct	s_redi
{
  char		**redir;
  int		fd;
  int		i;
}		t_redi;

typedef struct	s_pipe
{
  int		i;
  int		j;
  int		k;
  int		l;
  char		*str;
}		t_pipe;

char		*my_strdup(char *);
char		*my_strcpy(char *, char *);
int		my_strlen(char *);
void		my_putstr(char *);
void		put_in_chainlist(t_data *, char *);
char		**my_str_towordtab(char *);
int		my_strcomma(char *, char *);
void		my_affchain(t_data *);
void		makefork(char *, char **, char **, int );
char		**my_path_towordtab(char *);
char		*my_searchinchain(t_data *, char *);
char		**chain_to_wordtab(t_data *);
int		my_strenv(char *, char *);
void		testexec(char *, char **, t_data *);
void		init_val(int *, int *, int *, char *);
char		*my_strcatslash(char *, char *);
int		my_strstrlen(char **);
void		supplist(t_data *, char *);
char		*searchvar(char *);
int		my_countchain(t_data );
void		setinlist(t_data *, char *);
void		changedirect(t_data *, char *);
char		*analizeall(char *, char *, int );
char		*analizefdeb(char *, char *);
char		*cutbuffer(char *);
char		*my_strcat(char *, char *);
char		*recupvar(t_data *, char *);
void		goinghome(t_data *);
void		dirminus(t_data *);
void		freetabtab(char **);
int		countpirpir(char **);
int		countpvir(char **, int );
char		**my_tab_to_wordtab(char **, int , int );
char		*my_epurstr(char *);
int		countsimplevir(char *);
char		*epurpipechevr(char *);
int		countpipe(char *);
int		countredir(char *);
int		whenredirect(char **);
int		countchev(char *);
int		searchchev(char **);
void		checkexecve(char *, char **, char **);
int		opennormal(int , char *);
char		**returnline_to_tab(char *);
void		init_returnline(int *, int *, int *, char *);
int		countreturnline(char *);
void		dosimpleinvert(char **, char **, char *, char **);
char		**charst_in_tab(char **, char *);
int		invertanaly(int , char *);
void		makeforkinvert(char *, char **, char **, int );
char		*readfiledouble(char *);
char		*my_realloc(char *, char *);
void		dodoubleinvert(char *, char *, char **, char **);
void		makeforkdoubleinvert(char *, char **, char **, char *);
int		countinfinitepipe(char **);
void		feedredirexec(char *, char **, char **, t_redi );
int		pipeplace(char **, int );
int		pipeaccess(char **, char **, char **);
void		infinitepipe(char **, char **, char **);
char		*pipefeedaccess(char *, t_pipe *, char **);
char		*pipefeedequal(char **, t_pipe *);
char		**pipeall(char **, char **, char **, t_pipe *);
void		freelist(t_data *);
void		feedchild(t_redi , char **, char **, int *);
void		feeddad(t_redi *, int *);
void		initinfiniteloop(int *, int *);
void		sigsevcatch();

#endif /* !_MINISHELL_H_ */
