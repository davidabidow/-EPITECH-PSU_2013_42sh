/*
** epur_str.c for lib in /home/tran_0/rendu/rendugit/PSU_2013_42sh/src
** 
** Made by david tran
** Login   <tran_0@epitech.net>
** 
** Started on  Tue May  6 15:53:46 2014 david tran
** Last update Sat May 24 04:58:19 2014 valentin wallet
*/

#include "my.h"

void		feed_epur(char *dest, char *str, int *i, int *j)
{
  dest[(*j)++] = ' ';
  dest[(*j)++] = str[(*i)++];
}

void            epur_tab(char *str)
{
  int           i;

  i = 0;
  while (str[i] != '\0')
    {
      if (str[i] == '\t')
        str[i] = ' ';
      i++;
    }
}

char		*epur_space(char *str)
{
  char          *dest;
  int           i;
  int           j;

  i = 0;
  j = 0;
  epur_tab(str);
  if ((dest = malloc(sizeof(char) * (my_strlen(str) + 1))) == NULL)
    return (NULL);
  while (str[i] == ' ')
    i++;
  while (str[i] != '\0')
    {
      while (str[i] != ' ' && str[i] != '\0')
        dest[j++] = str[i++];
      while (str[i] == ' ')
        i++;
      if (str[i] != '\0')
        dest[j++] = ' ';
    }
  dest[j] = '\0';
  return (dest);
}
