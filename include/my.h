/*
** my.h for 42sh in /home/tran_0/rendu/rendugit/PSU_2013_42sh/src
** 
** Made by david tran
** Login   <tran_0@epitech.net>
** 
** Started on  Tue May  6 14:49:41 2014 david tran
** Last update Tue May 20 23:51:45 2014 david tran
*/

#ifndef MY_H__
# define MY_H__

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void	my_putchar(char );
void	my_putstr(char *);
void	my_puterr(char *);
char	*my_xmalloc(int);
char	**my_taballoc(int);
char	*my_strdup(char *);
char	*my_strndup(char *, int);
int	my_strlen(char *);
int	my_strstrlen(char **);
int	my_get_nbr(char *);
char	*my_strcat(char *, char *);
char	*my_strncat(char *, char *, int);
char	*my_strcatslash(char *, char *);
char	*my_strcpy(char *, char *);
char	*my_strncpy(char *, char *, int);
int	my_strcmp(char *, char *);
int	my_strncmp(char *, char *, int);
char	*epur_space(char *);
int	count_separ(char *, char *);
char	*separate_char(char *, char *);
char	**wordtab(char *, char *);
void	my_put_nbr(int);
char	**tab_wordtab(char **, int, int);
void	free_wordtab(char **);
int	my_isnumb(char *);
char	**wordtab_realloc(char **, int);
char	*my_realloc(char *, int);
char	**wordtabcpy(char **, char **);
char	**wordtabcat(char **, char *);
char	**wordtabdup(char **);

#endif /* !MY_H__ */
