/*
** catwordtab.c for lib in /home/tran_0/rendu/rendugit/PSU_2013_42sh
** 
** Made by david tran
** Login   <tran_0@epitech.net>
** 
** Started on  Sun May 25 04:01:30 2014 david tran
** Last update Sun May 25 21:44:22 2014 david tran
*/

#include "my.h"

char		**catwordtab(char **dest, char **src, int x)
{
  t_catwo	cwo;

  cwo.len = my_strstrlen(dest);
  cwo.j = 0;
  cwo.i = 0;
  if (!(cwo.go = my_taballoc((cwo.len + my_strstrlen(src) + 2)
			     * sizeof(char *))))
    return (NULL);
  while (cwo.i < x)
    {
      if (!(cwo.go[cwo.i] = my_strdup(dest[cwo.i])))
	return (NULL);
      cwo.i++;
    }
  cwo.len = cwo.i + 1;
  while (src[cwo.j])
    if (!(cwo.go[cwo.i++] = my_strdup(src[cwo.j++])))
      return (NULL);
  while (dest[cwo.len])
    if (!(cwo.go[cwo.i++] = my_strdup(dest[cwo.len++])))
      return (NULL);
  cwo.go[cwo.i] = NULL;
  free_wordtab(dest);
  return (cwo.go);
}
