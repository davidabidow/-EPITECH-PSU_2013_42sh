/*
** my_str_redirect.c for my_str_redirect in /home/tran_0/rendu/PSU_2013_minishell2
** 
** Made by david tran
** Login   <tran_0@epitech.net>
** 
** Started on  Wed Feb 19 16:38:31 2014 david tran
** Last update Sun Feb 23 01:22:35 2014 david tran
*/

#include "minishell2.h"

int	whenredirect(char **str)
{
  int	i;

  i = 0;
  while (str[i] != NULL)
    {
      if (str[i][0] == '<' || str[i][0] == '>')
	return (i);
      i++;
    }
  return (i);
}

int	countredir(char *str)
{
  int	i;
  int	j;

  i = 0;
  j = 0;
  while (str[i] != 0)
    {
      if (str[i] == '<' || str[i] == '>')
	{
	  j++;
	  if ((str[i + 1] == '>' && str[i] == '>') ||
	      (str[i + 1] == '<' && str[i] == '<'))
	    {
	      if (str[i + 2] == '>' || str[i + 2] == '<')
		{
		  my_putstr("Invalid parse");
		  return (0);
		}
	      else
		i++;
	    }
	}
      i++;
    }
  return (j);
}

int	countpipe(char *str)
{
  int	i;
  int	j;

  i = 0;
  j = 0;
  while (str[i])
    {
      if (str[i] == '|')
	j++;
      i++;
    }
  return (j);
}

char	*epurpipechevr(char *str)
{
  int	i;
  int	j;
  char	*dest;

  i = countredir(str) + countpipe(str);
  j = 0;
  if ((dest = malloc((my_strlen(str) + 1 + i * 2) * sizeof(*dest))) == NULL)
    return (NULL);
  i = 0;
  while (str[j])
    {
      if (str[j] == '|' || str[j] == '<' || str[j] == '>')
	{
	  if (str[j - 1] != ' ')
	    dest[i++] = ' ';
	  while (str[j] && (str[j] == '<' || str[j] == '>' || str[j] == '|'))
	    dest[i++] = str[j++];
	  if (str[j] && str[j] != ' ')
	    dest[i++] = ' ';
	}
      else
	dest[i++] = str[j++];
    }
  dest[i] = 0;
  return (dest);
}
