/*
** separate_char.c for lib in /home/tran_0/rendu/rendugit/PSU_2013_42sh/src
** 
** Made by david tran
** Login   <tran_0@epitech.net>
** 
** Started on  Tue May  6 16:18:44 2014 david tran
** Last update Tue May  6 16:22:18 2014 david tran
*/

int	count_separate(char *str, char *src)
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
  return (i + 1);
}

char	*separate_char(char *src, char *str)
{

}
