/*
** my_strcat.c for lib in /home/tran_0/rendu/rendugit/PSU_2013_42sh/src
** 
** Made by david tran
** Login   <tran_0@epitech.net>
** 
** Started on  Tue May  6 15:20:38 2014 david tran
** Last update Tue May  6 15:28:00 2014 david tran
*/

char	*my_strncat(char *dest, char *src, int len)
{
  int	i;
  int	j;

  i = my_strlen(dest);
  j = 0;
  while (src[j] && j < len)
    dest[i++] = src[j++];
  return (dest);
}

char	*my_strcat(char *dest, char *src)
{
  int	i;
  int	j;

  i = my_strlen(dest);
  j = 0;
  while (src[j])
    dest[i++] = src[j++];
  return (dest);
}
