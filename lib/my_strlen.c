/*
** my_strlen.c for  in /u/epitech_2012/lefebv_l/public/42sh/official/lib
** 
** Made by thomas brennetot
** Login   <brenne_t@epitech.net>
** 
** Started on  Mon Mar 31 16:47:58 2008 thomas brennetot
** Last update Mon Mar 31 16:48:19 2008 thomas brennetot
*/

int     my_strlen(char *str)
{
  int	result;

  result = 0;
  while (str[result] != '\0')
    result++;
  return (result);
}
