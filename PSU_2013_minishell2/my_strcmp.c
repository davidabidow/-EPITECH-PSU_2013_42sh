/*
** my_strcmp.c for my_strcmp in /home/tran_0/rendu/PSU_2013_minishell2
** 
** Made by david tran
** Login   <tran_0@epitech.net>
** 
** Started on  Thu Jan 23 16:57:41 2014 david tran
** Last update Sun Mar  9 20:03:26 2014 david tran
*/

#include "minishell2.h"

int	my_strcomma(char *nb_one, char *nb_two)
{
  int	i;

  i = 0;
  while (nb_two[i] == nb_one[i])
    {
      i++;
      if (nb_two[i] == '\0')
	return (1);
    }
  return (0);
}

int		my_countchain(t_data list)
{
  t_data	*tmp;
  int		i;

  i = 0;
  tmp = list.head;
  while (tmp != NULL)
    {
      i++;
      tmp = tmp->next;
    }
  return (i);
}

void	initinfiniteloop(int *min, int *max)
{
  *min = 0;
  *max = 0;
  write(2, "$mysh> ", 7);
}

int	countpvir(char **src, int max)
{
  max++;
  while (src[max])
    {
      if (src[max][0] == ';')
	return (max);
      max++;
    }
  return (max);
}
