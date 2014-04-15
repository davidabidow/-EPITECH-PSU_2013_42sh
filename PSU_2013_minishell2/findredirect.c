/*
** findredirect.c for findredirect in /home/tran_0/rendu/PSU_2013_minishell2
** 
** Made by david tran
** Login   <tran_0@epitech.net>
** 
** Started on  Wed Feb 19 11:11:42 2014 david tran
** Last update Sun Feb 23 00:06:49 2014 david tran
*/

int	my_strredir(char *str, char *dest, int min)
{
  int	i;
  int	j;
  int	k;

  i = min;
  j = 0;
  while (str[i] != 0)
    {
      k = 0;
      if (str[i] == dest[j])
	{
	  k = 1;
	  while (dest[j] != 0)
	    {
	      if (dest[++j] == 0 && k == 1)
		return (j);
	      else if (dest[j] != str[i + j])
		k = 0;
	    }
	}
      i++;
      j = 0;
    }
  return (j);
}

char	*recupfilename(char *filename, char c)
{
  int	i;
  int	j;
  int	k;
  char	*str;

  i = 0;
  j = 0;
  while (filename[i] != c)
    i++;
  while (filename[i] == c && filename[i] == ' ')
    i++;
  k = i;
  while (filename[k] != 0 || filename[k] != ' ' ||
	 filename[k] != '<' || filename[k] != '>')
    k++;
  if (str = malloc((k - i) * sizeof(*str)) == NULL)
    return (NULL);
  while (i != k)
    str[j++] = filename[i++];
  str[j] = 0;
  return (str);
}
