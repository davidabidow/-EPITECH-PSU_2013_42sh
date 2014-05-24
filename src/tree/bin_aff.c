/*
** bin_aff.c for 42sh in /home/tran_0/rendu/rendugit/PSU_2013_42sh
** 
** Made by david tran
** Login   <tran_0@epitech.net>
** 
** Started on  Thu May 22 23:27:33 2014 david tran
** Last update Fri May 23 12:48:34 2014 david tran
*/

#include "42sh.h"
#include "my.h"

void		bin_aff_redir_redo(t_bin *tmp)
{
  t_redirec	*pars;

  pars = tmp->redo->head;
  if (!pars)
    return ;
  my_putstr("\t>/>>: ");
  while (pars)
    {
      my_putstr("fd ");
      pars = pars->next;
    }
}

void	bin_aff_redir_princ(t_bin *tmp)
{
  t_redirec	*pars;

  pars = tmp->pre->head;
  if (!pars)
    return ;
  my_putstr("\t</<<: ");
  while (pars)
    {
      my_putstr("fd ");
      pars = pars->next;
    }
}

void	bin_aff(t_bin *bin)
{
  t_bin	*node;
  t_bin	*leef;

  node = bin->head;
  while (node)
    {
      leef = node;
      my_putstr("\nPrincipal node: ");
      if (node->command)
	putwordtab(node->command);
      bin_aff_redir_redo(node);
      bin_aff_redir_princ(leef);
      while (leef->right)
	{
	  leef = leef->right;
	  my_putstr("\n\t");
	  if (leef->command)
	    putwordtab(leef->command);
	  bin_aff_redir_princ(leef);
	}
      node = node->left;
    }
  my_putstr("\n");
}
