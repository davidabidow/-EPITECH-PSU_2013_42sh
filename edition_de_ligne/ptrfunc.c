/*
** ptrfunc.c for ptrfunc in /home/wallet_v/42sh_edition_historique
** 
** Made by valentin wallet
** Login   <wallet_v@epitech.net>
** 
** Started on  Sun May 18 12:25:11 2014 valentin wallet
** Last update Sun May 25 18:34:23 2014 valentin wallet
*/

#include "42sh.h"

t_data		tab[] =
  {
    {4479771, &go_left},
    {4414235, &go_right},
    {127, &my_del},
    {1, &start_of_buffer},
    {4738843, &start_of_buffer},
    {5, &end_of_buffer},
    {4607771, &end_of_buffer},
    {2117294875, &my_suppr},
    {0, NULL}
  };

int			parcours_ptr_func(t_termcap *term,
					  struct winsize *mysizewin, int *count)
{
  int			i;

  i = 0;
  while (tab[i].ptr != NULL)
    {
      if (term->buff == tab[i].id)
	{
	  if ((term->str =
	       tab[i].ptr(term->str, &term->data, &term->x, mysizewin)) == NULL)
	    return (EXIT_FAILURE);
	  (*count)++;
	}
      i++;
    }
  return (EXIT_SUCCESS);
}
