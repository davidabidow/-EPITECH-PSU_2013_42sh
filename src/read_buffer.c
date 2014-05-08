/*
** read_buffer.c for 42sh in /home/tran_0/rendu/rendugit/PSU_2013_42sh
** 
** Made by david tran
** Login   <tran_0@epitech.net>
** 
** Started on  Thu May  8 18:36:45 2014 david tran
** Last update Fri May  9 01:16:22 2014 david tran
*/

#include "42sh.h"
#include "my.h"

char	*makeread(t_env *list)
{
  char	buffer[1024];
  int	readed;
  int	i;

  while ((readed = read(0, buffer, 1023)) > 0)
    {
      buffer[readed] = 0;
      i = 0;
      while (buffer[i] != 0)
	{
	  if (buffer[i] == '\n')
	    return (my_strdup(buffer));
	  i++;
	}
    }
  return (NULL);
}
