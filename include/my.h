/*
** my.h for 42sh in /home/tran_0/rendu/rendugit/PSU_2013_42sh/src
** 
** Made by david tran
** Login   <tran_0@epitech.net>
** 
** Started on  Tue May  6 14:49:41 2014 david tran
** Last update Tue May  6 16:19:14 2014 david tran
*/

#ifndef __MY_H__
# define __MY_H__

void	my_putchar(char );
void	my_putstr(char *);
char	*my_strdup(char *);
int	my_strlen(char *);
int	my_get_nbr(char *);
char	*my_strcat(char *, char *);
char	*my_strncat(char *, char *, int);
char	*my_strcpy(char *, char *);
char	*my_strncpy(char *, char *, int);
int	my_strcmp(char *, char *);
int	my_strncmp(char *, char *, int);
char	*epur_space(char *);
int	count_separate(char *, char);

#endif /* !__MY_H__ */
