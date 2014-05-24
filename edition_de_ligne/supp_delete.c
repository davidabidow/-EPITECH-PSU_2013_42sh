/*
** supp_delete.c for supp_delete in /home/wallet_v/42sh_edition_historique
** 
** Made by valentin wallet
** Login   <wallet_v@epitech.net>
** 
** Started on  Mon May 19 15:09:38 2014 valentin wallet
** Last update Sat May 24 02:57:52 2014 david tran
*/

#include "42sh.h"
#include "my.h"

char			*my_del(char *str, t_cmd *data, int *x, struct winsize *mysizewin)
{
  char			*tmp;
  char			*newstr;
  char			*final;

  if ((my_strlen(str) == 0) || (*x == PROMPT_SIZE))
    return (str);
  if ((newstr = malloc(sizeof(char) * my_strlen(str))) == NULL)
    return (NULL);
  my_strcpy(&str[(*x) - PROMPT_SIZE], newstr);
  if ((tmp = malloc(sizeof(char) * (my_strlen(str)))) == NULL)
    return (NULL);
  tmp = memset(tmp, '\0', my_strlen(str));
  strncpy(tmp, str, (*x - (PROMPT_SIZE + 1)));
  move_left(data, x, mysizewin);
  tputs(data->save, 1, my_putchar2);
  my_putstr(newstr);
  write(1, " ", 1);
  tputs(data->restor, 1, my_putchar2);
  final = strcat(tmp, newstr);
  //  free(str);
  return (final);
}

char			*my_suppr(char *str, t_cmd *data, int *x, struct winsize *mysizewin UNUSED)
{
  char			*final;
  char			*tmp;
  char			*newstr;

  if ((*x - PROMPT_SIZE) == my_strlen(str))
    return (str);
  if ((newstr = malloc(sizeof(char) * my_strlen(str))) == NULL)
    return (NULL);
  my_strcpy(&str[(*x) - (PROMPT_SIZE - 1)], newstr);
  tputs(data->save, 1, my_putchar2);
  my_putstr(newstr);
  write(1, " ", 1);
  tputs(data->restor, 1, my_putchar2);
  if ((tmp = malloc(sizeof(char) * my_strlen(str))) == NULL)
    return (NULL);
  memset(tmp, '\0', my_strlen(str));
  strncpy(tmp, str, (*x - (PROMPT_SIZE)));
  final = strcat(tmp, newstr);
  free(str);
  return (final);
}
