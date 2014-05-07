/*
** my_put_nbr.c for lib in /home/tran_0/rendu/rendugit/PSU_2013_42sh/lib
** 
** Made by david tran
** Login   <tran_0@epitech.net>
** 
** Started on  Wed May  7 02:49:31 2014 david tran
** Last update Wed May  7 02:53:18 2014 david tran
*/

#include "my.h"

void	aff_nb(int nb)
{
  char	chiffre;

  chiffre = 0;
  if (nb > 0)
    {
      chiffre = (nb % 10) + 48;
      nb = nb / 10;
      aff_nb(nb);
      my_putchar(chiffre);
    }
}

void	my_put_nbr(int nb)
{
  if (nb < 0)
    {
      nb = nb * (-1);
      my_putchar('-');
      aff_nb(nb);
    }
  else if (nb == 0)
    my_putchar('0');
  else
    aff_nb(nb);
}
