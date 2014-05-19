/*
** double_invert.c for 42sh in /home/tran_0/rendu/rendugit/PSU_2013_42sh/src/redir
** 
** Made by david tran
** Login   <tran_0@epitech.net>
** 
** Started on  Thu May 15 18:21:02 2014 david tran
** Last update Mon May 19 02:39:38 2014 david tran
*/

#include "42sh.h"
#include "my.h"

char		*double_invert(char *end)
{
  int		readed;
  char		buffer[BUFF_SIZE + 1];
  char		*str;

  if (!(str = malloc(sizeof(char))))
    return (NULL);
  str[0] = 0;
  my_putstr("\tTapTap>");
  while ((readed = read(0, buffer, 1023)) > 0)
    {
      buffer[readed] = 0;
      if (my_strncmp(buffer, end, my_strlen(end)) == 0)
	return (str);
      if (!(str = my_realloc(str, my_strlen(str) + readed + 1)))
	return (NULL);
      str = my_strcat(str, buffer);
      my_putstr("\tTapTap>");
    }
  return (NULL);
}
