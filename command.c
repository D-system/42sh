/*
** command.c for 42sh in /u/epitech_2012/lefebv_l/cu/public/42sh/official
** 
** Made by laurent lefebvre
** Login   <lefebv_l@epitech.net>
** 
** Started on  Tue Apr  1 12:40:36 2008 laurent lefebvre
** Last update Tue Apr 15 17:40:20 2008 thomas brennetot
*/

#include "42.h"

/*
** Recoie la commande, cherche le path, verifie les access, et fais appel a exec pour execution
*/

void	command()
{
  exec();
}