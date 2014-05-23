/*
** bin_aff.c for 42sh in /home/tran_0/rendu/rendugit/PSU_2013_42sh
** 
** Made by david tran
** Login   <tran_0@epitech.net>
** 
** Started on  Thu May 22 23:27:33 2014 david tran
** Last update Thu May 22 23:35:24 2014 david tran
*/

#include "42sh.h"
#include "my.h"

void	bin_aff(t_bin *bin)
{
  t_bin	*node;
  t_bin	*leef;

  node = bin->head;
  while (node)
    {
      leef = node;
      my_putstr("\nPrincipal node: ");
      putwordtab(node->command);
      while (leef->right)
	{
	  leef = leef->right;
	  my_putstr("\n\t");
	  putwordtab(leef->command);
	}
      node = node->left;
    }
  my_putstr("\n");
}
