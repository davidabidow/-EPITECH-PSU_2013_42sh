/*
** my_getnbr.c<2> for lib in /home/tran_0/rendu/rendugit/PSU_2013_42sh/src
** 
** Made by david tran
** Login   <tran_0@epitech.net>
** 
** Started on  Tue May  6 14:55:07 2014 david tran
** Last update Tue May  6 15:17:19 2014 david tran
*/

int	check_neg(char *str, int *i)
{
  int	j;
  int	neg;

  j = 0;
  neg = 1;
  while (str[j] && (str[j] == '+' || str[j] == '-'))
    {
      if (str[j] == '-')
	neg = neg * -1;
      ++j;
    }
  (*i) = j;
  return (neg);
}

int	my_getnbr(char *str)
{
  int	i;
  int	nb;
  int	neg;

  nb = 0;
  neg = check_neg(str, &i);
  while (str[i] && str[i] >= 48 && str[i] <= 57)
    {
      if (nb >= 214748364)
	{
	  if ((str[i] - 48) < 8)
	    nb = nb * 10 + (str[i] - 48);
	  else
	    return (0);
	}
      else
	nb = nb * 10 + (str[i] - 48);
      i++;
    }
  return (nb * neg);
}
