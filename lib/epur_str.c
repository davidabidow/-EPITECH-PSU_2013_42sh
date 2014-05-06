/*
** epur_str.c for lib in /home/tran_0/rendu/rendugit/PSU_2013_42sh/src
** 
** Made by david tran
** Login   <tran_0@epitech.net>
** 
** Started on  Tue May  6 15:53:46 2014 david tran
** Last update Tue May  6 16:05:03 2014 david tran
*/

char	*epur_space(char *str)
{
  char	*dest;
  int	i;

  i = 0;
  if ((dest = malloc(sizeof(char) * (my_strlen(str) + 1))) == NULL)
    return (NULL);
  while (str)
    {
      if (str[i] && (str[i] == ' ' || str[i] == '\t'))
	i++;
      else if (str[i - 1] && (str[i - 1] == ' ' || str[i - 1] == '\t')
	       && str[i] != ' ' && str[i] != '\t')
	dest[i++] = ' ';
      else
	dest[i++] = str[i];
    }
  dest[i] = 0;
  return (dest);
}
