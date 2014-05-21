/*
** bin_free.c for 42sh in /home/tran_0/rendu/rendugit/PSU_2013_42sh/src
** 
** Made by david tran
** Login   <tran_0@epitech.net>
** 
** Started on  Mon May 19 17:11:59 2014 david tran
** Last update Mon May 19 17:35:51 2014 david tran
*/

#include "42sh.h"
#include "my.h"

void	free_part(t_bin *bfree)
{
  if (bfree->command)
    free_wordtab(bfree->command);
  if (bfree->op)
    free(bfree->op);
  if (bfree->princ)
    free(bfree->princ);
  free(bfree);
}

void	free_all_right(t_bin *tmp)
{
  t_bin	*bfree;

  if (tmp->right)
    tmp = tmp->right;
  while (tmp->right)
    {
      bfree = tmp;
      tmp = tmp->right;
      free_part(bfree);
    }
}

void	free_all_left(t_bin *tmp)
{
  t_bin	*bfree;

  if (tmp->left)
    tmp = tmp->left;
  else
    return ;
  while (tmp->left)
    {
      bfree = tmp;
      tmp = tmp->left;
      free_part(bfree);
    }
}

void	free_bin(t_bin *bin)
{
  t_bin	*tmp;

  tmp = bin->head;
  while (tmp)
    {
      free_all_right(tmp);
      tmp = tmp->left;
    }
  tmp = bin->head;
  free_all_left(tmp);
  free_part(bin->head);
}
