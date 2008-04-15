/*
** get_param.c for 42sh in /u/epitech_2012/deraze_a/cu/rendu/c/42sh/gp2/mrk/prompt
** 
** Made by aymeric derazey
** Login   <deraze_a@epitech.net>
** 
** Started on  Tue Apr 15 14:54:50 2008 aymeric derazey
** Last update Tue Apr 15 15:26:15 2008 aymeric derazey
*/

t_prompt gl_prompt[] =
  {
    {'/', 0, 0},	/* pwd */
    {'~', 0, 0},/**/	/* affiche '~' */
    {'c', 0, 0},	/* pwd depuis l'home */
    {'C', 0, 0},	/* pwd depuis l'home sans le '~/'*/
    {'h', 0, 0},/**/	/* The current history event number */
    {'M', 0, 0},/**/	/* The full hostname */
    {'m', 0, 0},/**/	/* The hostname up to the first `.' */
    {'S', 0, 0},	/* Debut de la video inverse */
    {'s', 0, 0},	/* Fin de la video inverse */
    {'B', 0, 0},	/* Debut du mode 'gras' */
    {'b', 0, 0},	/* Fin du mode 'gras' */
    {'U', 0, 0},	/* Debut du mode 'surligne' */
    {'u', 0, 0},	/* Fin du mode 'surligne' */
    {'t', 0, 0},	/* The time of day in 12-hour AM/PM format */
    {'T', 0, 0},	/* Like `%t', but in 24-hour format */
    {'p', 0, 0},	/* Comme %t avec les secondes */
    {'P', 0, 0},	/* Comme %T avec les secondes */
    {'%', 0, 0},/**/	/* '%' */ 
    {'n', 0, 0},/**/	/* The user name */
    {'d', 0, 0},	/* The weekday in `Day' format. */
    {'D', 0, 0},	/* The day in `dd' format. */
    {'w', 0, 0},	/* The month in `Mon' format. */
    {'W', 0, 0},	/* The month in `mm' format. */
    {'y', 0, 0},	/* The year in `yy' format. */
    {'Y', 0, 0},	/* The year in `yyyy' format. */
    {'?', 0, 0},	/* Valeur de return de la derniere commande */
    {0, 0, 0},
  };

/*
** Lance la fonction adequate selon le parametre (%x)
*/

int     launch_fct(t_info *info, int i)
{
  int	gl;

  gl = 0;
  while (info->prompt[i] != gl_prompt[gl].c && gl_prompt[gl].c != 0)
    gl++;
  if (info->prompt[i] = gl_prompt[gl].c)
    {
      gl_prompt[gl].func(info);
      return (EXIT_SUCCESS);
    }
  return (EXIT_FAILURE);
}
