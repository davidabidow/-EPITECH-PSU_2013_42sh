/*
** my_strdup.c<2> for lib in /home/tran_0/rendu/rendugit/PSU_2013_42sh/lib
** 
** Made by david tran
** Login   <tran_0@epitech.net>
** 
** Started on  Tue May  6 06:12:27 2014 david tran
** Last update Tue May  6 06:14:37 2014 david tran
*/

char	*my_strdup(char *str)
{
  int	i;
  char	*dest;
  int	j;

  i = my_strlen (str);
  if ((dest = malloc(i + 1)) == NULL)
    return (NULL);
  dest[i] = 0;
  j = 0;
  while (j < i)
    {
      dest[j] = src[j];
      j++;
    }
  return (dest);
}
