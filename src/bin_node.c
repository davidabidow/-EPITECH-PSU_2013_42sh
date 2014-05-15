/*
** bin_node.c for 42sh in /home/tran_0/rendu/rendugit/PSU_2013_42sh/include
** 
** Made by david tran
** Login   <tran_0@epitech.net>
** 
** Started on  Thu May 15 01:01:29 2014 david tran
** Last update Thu May 15 01:53:34 2014 david tran
*/

#include "42sh.h"
#include "my.h"

void	init_node(t_bin *bin)
{
  bin->left = NULL;
  bin->right = NULL;
  bin->wone = 0;
}

int	create_nodd_command(t_bin **bin, char **command)
{
  t_bin *tmpNode;
  t_bin	*tmpTree;
  t_bin	*new;

  tmpTree = bin;
  if (!(new = malloc(sizeof(node))))
    return (EXIT_FAILURE);
  new->command = command;
  new->wone = 0;
  new->left = NULL;
  new->right = NULL;
  if (tmpTree)
    {
      while (tmpTree)
	{
	  tmpNode = tmpTree;
	  tmpTree = tmpTree->left;
	  if (!tmpTree)
	    tmpNode->left = new;
	}
    }
  else
    *bin = new;
  return (EXIT_SUCCESS);
}

int	create_nodd_redir(t_bin **bin, char *file, char id, int fd)
{
  t_bin *tmpNode;
  t_bin	*tmpTree;
  t_bin	*new;

  tmpTree = bin;
  if (!(new = malloc(sizeof(node))))
    return (EXIT_FAILURE);
  new->redi.id = id;
  new->redi.fd = fd;
  new->wone = 1;
  new->left = NULL;
  new->right = NULL;
  if (tmpTree)
    {
      while (tmpTree)
	{
	  tmpNode = tmpTree;
	  tmpTree = tmpTree->left;
	  if (!tmpTree)
	    tmpNode->left = new;
	}
    }
  else
    *bin = new;
  return (EXIT_SUCCESS);
}
