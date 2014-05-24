/*
** my_str_to_wordtab.c for my_str_to_wordtab in /home/lacour_a/rendu/MUL_2013_fdf
**
** Made by arthur lacour
** Login   <lacour_a@epitech.net>
**
** Started on  Thu Dec  5 13:47:29 2013 arthur lacour
** Last update Sat May 24 02:30:16 2014 david tran
*/

#include "42sh.h"
#include "my.h"

int		my_is_sep(char c, char *sep)
{
  int		i;

  i = 0;
  while (sep[i])
    if (sep[i] == c)
      return (1);
    else
      i++;
  return (0);
}

int		nb_words(char *str, char *sep)
{
  int		i;
  int		nb;

  i = 0;
  nb = 0;
  while (str[i])
    {
      if (my_is_sep(str[i], sep) == 1)
	i++;
      else
	{
	  nb++;
	  while (my_is_sep(str[i], sep) == 0 && str[i])
	    i++;
	}
    }
  return (nb);
}

char		*my_strnncpy(char *dest, char *src, int *j, int *i)
{
  int		k;

  k = 0;
  while (*j < *i)
    {
      dest[k] = src[*j];
      k = k + 1;
      *j = *j + 1;
    }
  dest[k] = '\0';
  return (dest);
}

char		**my_str_to_wordtab(char *str, char *sep)
{
  int		i;
  int		j;
  int		l;
  int		word;
  char		**my_tab;

  i = 0;
  j = 0;
  l = 0;
  word = nb_words(str, sep);
  if ((my_tab = malloc(sizeof(char *) * (word + 1))) == NULL)
    return (NULL);
  memset(my_tab, '\0', word * sizeof(char *));
  while (str[i] && word-- > 0)
    {
      while (my_is_sep(str[i], sep) == 1 && str[i])
	{
	  i++;
	  j++;
	}
      while (str[i] && (my_is_sep(str[i], sep) == 0))
	i++;
      my_tab[l] = my_xmalloc(sizeof(char) * (i - j) + 1);
      memset(my_tab[l], '\0', i - j + 1);
      my_strnncpy(my_tab[l++], str, &j, &i);
    }
  my_tab[l] = NULL;
  return (my_tab);
}
