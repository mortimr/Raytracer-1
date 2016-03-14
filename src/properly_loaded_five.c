/*
** properly_loaded_five.c for raytracer1 in /home/rotaru_i
**
** Made by Iulian Rotaru
** Login   <rotaru_i@epitech.net>
**
** Started on  Sun Mar 13 12:55:30 2016 Iulian Rotaru
** Last update Sun Mar 13 13:21:28 2016 Iulian Rotaru
*/

#include "raytracer1.h"

void	properly_loaded_five(t_figure *data)
{
  if (data->type == 5)
    {
      my_putstr("\x1B[35m");
      my_putstr("Light\n");
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
      my_putstr("Color is :\n");
      my_put_unbr(data->color.full);
      my_putchar('\n');
    }
}

void	properly_loaded_end(int last)
{
  if (last == 1)
    {
      my_putstr("=====\n");
      my_putstr("====\n");
      my_putstr("===\n");
      my_putstr("==\n");
      my_putstr("=\n");
    }
  my_putstr("\x1B[0m");
}

void		properly_loaded(t_figure *data, int last)
{
  static int	loader;

  my_putstr("\x1B[32m");
  if (loader == 0)
    {
      my_putstr("=\n");
      my_putstr("==\n");
      my_putstr("===\n");
      my_putstr("====\n");
      my_putstr("=====\n");
    }
  my_putstr("-=====================================-\n");
  my_putstr("\x1B[0m");
  my_putstr("Properly loaded figure ");
  properly_loaded_one(data);
  properly_loaded_two(data);
  properly_loaded_five(data);
  my_putstr("\x1B[32m");
  my_putstr("-=====================================-\n");
  properly_loaded_end(last);
  loader++;
}

void		add_one_sphere_job(t_bunny_ini *ini,
				   t_figure *tmp,
				   t_rtracer *data,
				   int sphere)
{
  const char	*extract;

  extract = bunny_ini_get_field(ini, "sphere", "pos", sphere * 3);
  tmp->pos.x = my_getnbr(extract);
  extract = bunny_ini_get_field(ini, "sphere", "pos", sphere * 3 + 1);
  tmp->pos.y = my_getnbr(extract);
  extract = bunny_ini_get_field(ini, "sphere", "pos", sphere * 3 + 2);
  tmp->pos.z = my_getnbr(extract);
  extract = bunny_ini_get_field(ini, "sphere", "radius", sphere);
  tmp->radius = my_getnbr(extract);
  extract = bunny_ini_get_field(ini, "sphere", "color", sphere);
  tmp->color.full = my_getunbr(extract);
  tmp->type = 1;
  tmp->idx = data->idx;
  data->idx++;
  data->nb_figures += 1;
  properly_loaded(tmp, 0);
}

int		add_one_sphere(t_rtracer *data, t_bunny_ini *ini, int sphere)
{
  t_figure	*tmp;
  int		i;

  tmp = data->figure;
  i = 0;
  while (i < data->idx)
    {
      tmp = tmp->next;
      i++;
    }
  if ((tmp->next = bunny_malloc(sizeof(t_figure))) == NULL)
    return (failed_alloc());
  if (((bunny_ini_get_field(ini, "sphere", "pos", sphere * 3)) == NULL)
      || ((bunny_ini_get_field(ini, "sphere", "pos", sphere * 3 + 1)) == NULL)
      || ((bunny_ini_get_field(ini, "sphere", "pos", sphere * 3 + 2)) == NULL)
      || ((bunny_ini_get_field(ini, "sphere", "radius", sphere)) == NULL)
      || ((bunny_ini_get_field(ini, "sphere", "color", sphere)) == NULL))
    return (failed_figure("sphere"));
  add_one_sphere_job(ini, tmp, data, sphere);
  return (0);
}
