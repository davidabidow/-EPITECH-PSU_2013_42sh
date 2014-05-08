/*
** infinite_loop.c for 42sh in /home/tran_0/rendu/rendugit/PSU_2013_42sh
** 
** Made by david tran
** Login   <tran_0@epitech.net>
** 
** Started on  Thu May  8 18:34:21 2014 david tran
** Last update Fri May  9 01:25:11 2014 david tran
*/

#include "42sh.h"
#include "my.h"

char		*transform_chain(char *str)
{
  if (!(str = epur_space(str)))
    return (NULL);
  else if (!(str = separate_char(str, ";")) ||
	   !(str = separate_char(str, "<")) ||
	   !(str = separate_char(str, ">")) ||
	   !(str = separate_char(str, "&")) ||
	   !(str = separate_char(str, "|")))
    return (NULL);
  return (str);
}

void		initloop(int *min, int *max)
{
  *min = 0;
  *max = 0;
  write(2, "$42sh> ", 7);
}

int		countpvir(char **src, int max)
{
  max++;
  while (src[max])
    {
      if (src[max][0] == ';')
	return (max);
      max += 1;
    }
  return (max);
}

void		infiniteloop(t_env *list)
{
  char		*buffer;
  char		**dest;
  int		min;
  int		max;
  char		**new;

  while (42)
    {
      initloop(&min, &max);
      if ((buffer = makeread(list)) == NULL)
	return ;
      if (!(buffer = transform_chain(buffer)))
	return ;
      if (!(dest = wordtab(buffer, " ")))
	return ;
      while (max != my_strstrlen(dest))
	{
	  max = countpvir(dest, max);
	  if (!(new = tab_wordtab(dest, min, max)))
	    return ;
	  min = max + 1;
	}
      free_wordtab(dest);
    }
}
