/*
** catwordtab.c for lib in /home/tran_0/rendu/rendugit/PSU_2013_42sh
** 
** Made by david tran
** Login   <tran_0@epitech.net>
** 
** Started on  Sun May 25 04:01:30 2014 david tran
** Last update Sun May 25 22:27:40 2014 david tran
*/

#include "my.h"

int		cat_feed(t_catwo *cwo, char **src)
{
  while (src[cwo->j])
    {
      if (access(src[cwo->j], R_OK) != -1)
	if (!(cwo->go[cwo->i++] = my_strdup(src[cwo->j])))
	  return (EXIT_FAILURE);
      cwo->j++;
    }
  return (EXIT_SUCCESS);
}

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
  if (cat_feed(&cwo, src) == EXIT_FAILURE)
    return (NULL);
  while (dest[cwo.len])
    if (!(cwo.go[cwo.i++] = my_strdup(dest[cwo.len++])))
      return (NULL);
  cwo.go[cwo.i] = NULL;
  free_wordtab(dest);
  return (cwo.go);
}
