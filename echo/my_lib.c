/*
** my_lib.c for mini lib in /home/lacour_a/rendu
**
** Made by arthur lacour
** Login   <lacour_a@epitech.net>
**
** Started on  Fri May 23 17:00:15 2014 arthur lacour
** Last update Fri May 23 17:04:34 2014 arthur lacour
*/

void	my_putchar(char c)
{
  write(1, &c, 1);
}

void	my_putstr(char *str)
{
  int	i;

  i = 0;
  while (str[i])
    my_putchar(str[i++]);
}

int	my_strlen(char *str)
{
  int   i;

  i = 0;
  while (str[i])
    i++;
  return (i);
}
