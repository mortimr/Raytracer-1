/*
** my_put_nbr.c for raytracer1 in /home/rotaru_i
**
** Made by Iulian Rotaru
** Login   <rotaru_i@epitech.net>
**
** Started on  Sun Mar 13 12:51:40 2016 Iulian Rotaru
** Last update Sun Mar 13 13:20:01 2016 Iulian Rotaru
*/

#include <unistd.h>
#include "raytracer1.h"

void		my_put_nbr(int nb)
{
  static char	tmp;

  if (nb < 0)
    {
      write(1, "-", 1);
      nb = - nb;
    }
  if (nb >= 10)
    my_put_nbr(nb / 10);
  tmp = (nb % 10) + 48;
  write(1, &tmp, 1);
}

void		my_put_unbr(unsigned int nb)
{
  static char	tmp;

  if (nb >= 10)
    my_put_nbr(nb / 10);
  tmp = (nb % 10) + 48;
  write(1, &tmp, 1);
}

void	properly_loaded_one(t_figure *data)
{
  if (data->type == 1)
    {
      my_putstr("\x1B[34m");
      my_putstr("Sphere\n");
      my_putstr("Coordinates are :\n");
      my_putstr("x = ");
      my_put_nbr(data->pos.x);
      my_putchar('\n');
      my_putstr("y = ");
      my_put_nbr(data->pos.y);
      my_putchar('\n');
      my_putstr("z = ");
      my_put_nbr(data->pos.z);
      my_putchar('\n');
      my_putstr("Radius is ");
      my_put_nbr(data->radius);
      my_putchar('\n');
    }
}

void	properly_loaded_two_next(t_figure *data)
{
  my_putstr("y = ");
  my_put_nbr(data->vec[1].y);
  my_putchar('\n');
  my_putstr("z = ");
  my_put_nbr(data->vec[1].z);
  my_putchar('\n');
  my_putstr("Directive Vector's Coordinates are :\n");
  my_putstr("x = ");
  my_put_nbr(data->vec[0].x);
  my_putchar('\n');
  my_putstr("y = ");
  my_put_nbr(data->vec[0].y);
  my_putchar('\n');
  my_putstr("z = ");
  my_put_nbr(data->vec[0].z);
  my_putchar('\n');
}

void	properly_loaded_two(t_figure *data)
{
  if (data->type == 2)
    {
      my_putstr("\x1B[33m");
      my_putstr("Plan\n");
      my_putstr("Coordinates are :\n");
      my_putstr("x = ");
      my_put_nbr(data->pos.x);
      my_putchar('\n');
      my_putstr("y = ");
      my_put_nbr(data->pos.y);
      my_putchar('\n');
      my_putstr("z = ");
      my_put_nbr(data->pos.z);
      my_putchar('\n');
      my_putstr("Normal Vector's Coordinates are :\n");
      my_putstr("x = ");
      my_put_nbr(data->vec[1].x);
      my_putchar('\n');
      properly_loaded_two_next(data);
    }
}
