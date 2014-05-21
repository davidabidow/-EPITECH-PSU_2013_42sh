/*
** read_buffer.c for 42sh in /home/tran_0/rendu/rendugit/PSU_2013_42sh
** 
** Made by david tran
** Login   <tran_0@epitech.net>
** 
** Started on  Thu May  8 18:36:45 2014 david tran
** Last update Wed May 21 00:01:00 2014 david tran
*/

#include "42sh.h"
#include "my.h"

char	*makeread()
{
  char	*buffer;
  int	readed;
  int	i;

  if (!(buffer = my_xmalloc(sizeof(char) * 1024)))
    return (NULL);
  while ((readed = read(0, buffer, 1023)) > 0)
    {
      buffer[readed] = 0;
      i = 0;
      while (buffer[i] != 0)
	{
	  if (buffer[i] == '\n')
	    {
	      buffer[i] = 0;
	      return (my_strdup(buffer));
	    }
	  i++;
	}
    }
  return (NULL);
}
