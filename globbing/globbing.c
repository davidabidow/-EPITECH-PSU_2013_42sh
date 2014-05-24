/*
** main.c for main in /home/briard_g/rendu/PSU_2013_42sh/globbing
** 
** Made by Guillaume Briard
** Login   <briard_g@epitech.net>
** 
** Started on  Fri May 23 18:11:43 2014 Guillaume Briard
** Last update Sat May 24 14:29:15 2014 Guillaume Briard
*/

char		**check_glob(char *path)
{
  glob_t	globbuf;

  if (glob(path, GLOB_DOOFS | GLOB_APPEND, NULL, &globbuf) != 0)
    return (NULL);
  return (globbuf.gl_pathv);
}
