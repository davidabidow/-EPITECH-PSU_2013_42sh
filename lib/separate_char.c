/*
** separate_char.c for lib in /home/tran_0/rendu/rendugit/PSU_2013_42sh/src
** 
** Made by david tran
** Login   <tran_0@epitech.net>
** 
** Started on  Tue May  6 16:18:44 2014 david tran
** Last update Tue May  6 23:05:04 2014 david tran
*/

int	count_separ(char *str, char *src)
{
  int	i;
  int	count;

  i = 0;
  count = 0;
  while (str[i])
    {
      if (my_strncmp(&str[i], src, my_strlen(src)) == 0)
	count += 1;
      i++;
    }
  return (i);
}

char	*separate_char(char *src, char *str)
{
  int	i;
  int	j;
  int	k;
  char	*dest;

  i = 0;
  if ((dest = malloc(my_strlen(src) + count_separ(src, str) * 2 + 1)) == NULL)
    return (NULL);
  j = 0;
  while (src[i])
    {
      if (my_strncmp(&src[i], str) == 0)
	{
	  k = -1;
	  if (src[i - 1] && src[i - 1] != ' ')
	    dest[j++] = ' ';
	  while (str[++k])
	    dest[j++] = src[i++];
	  if (src[i + 1] && src[i + 1] != ' ')
	    dest[j++] = ' ';
	}
      else
	dest[j++] = src[i++];
    }
  return (dest);
}
