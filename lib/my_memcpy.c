/*
** my_memcpy.c for  in /u/epitech_2012/lefebv_l/public/42sh/official
**
** Made by thomas brennetot
** Login   <brenne_t@epitech.net>
**
** Started on  Mon Mar 31 17:23:33 2008 thomas brennetot
** Last update Wed May  7 23:00:20 2008 thomas brennetot
*/

void	*my_memcpy(void *dest2, void *src2, int size)
{
  int	i;
  char	*dest;
  char	*src;

  dest = dest2;
  src = src2;
  i = 0;
  while (i != size)
    {
      dest[i] = src[i];
      i++;
    }
  return (dest);
}
