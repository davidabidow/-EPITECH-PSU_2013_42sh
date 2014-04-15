/*
** invertchev.c for invertchev in /home/tran_0/rendu/PSU_2013_minishell2
** 
** Made by david tran
** Login   <tran_0@epitech.net>
** 
** Started on  Sun Feb 23 15:00:40 2014 david tran
** Last update Sun Mar  9 18:24:21 2014 david tran
*/

#include "minishell2.h"

int	opennormal(int fd, char *dest)
{
  if (fd == 2 && dest)
    fd = open(dest, O_RDWR | O_CREAT | O_APPEND,
	      S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
  else if (fd == 1 && dest)
    fd = open(dest, O_RDWR | O_CREAT | O_TRUNC,
	      S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
  return (fd);
}

char	*my_realloc(char *str, char *oth)
{
  char	*dest;

  if ((dest = malloc((my_strlen(str) + my_strlen(oth) + 2)
		     * sizeof(char))) == NULL)
    return (NULL);
  dest = my_strcpy(dest, str);
  dest = my_strcat(dest, oth);
  return (dest);
}

char	*readfiledouble(char *dest)
{
  int	readed;
  char	*buffer;
  char	*str;

  str = malloc(1024 * sizeof(*buffer));
  if ((buffer = malloc(1024 * sizeof(*buffer))) == NULL || str == NULL)
    return (NULL);
  str[0] = 0;
  my_putstr("TapTap>");
  while ((readed = read(0, buffer, 1023)) > 0)
    {
      buffer[readed] = 0;
      if (my_strcomma(buffer, dest) == 1)
	return (str);
      str = my_realloc(str, buffer);
      my_putstr("TapTap>");
    }
  return (NULL);
}

void	dodoubleinvert(char *str, char *dest, char **env, char **redir)
{
  char	*src;

  src = readfiledouble(dest);
  makeforkdoubleinvert(str, redir, env, src);
}

int		invertanaly(int fd, char *dest)
{
  if (fd == 3)
    fd = open(dest, O_RDWR);
  return (fd);
}
