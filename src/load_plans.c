/*
** load_plans.c for raytracer1 in /home/rotaru_i
**
** Made by Iulian Rotaru
** Login   <rotaru_i@epitech.net>
**
** Started on  Sun Mar 13 13:05:07 2016 Iulian Rotaru
** Last update Sun Mar 13 18:35:57 2016 Iulian Rotaru
*/

#include "raytracer1.h"

int		load_plans(t_bunny_ini *ini, t_rtracer *data)
{
  const char	*extract;
  int		rounds;
  int		i;

  if ((extract = bunny_ini_get_field(ini, "plan", "nb", 0)) == NULL)
    return (0);
  i = 0;
  rounds = my_getnbr(extract);
  while (i < rounds)
    {
      if (add_one_plan(data, ini, i) == -1)
	return (-1);
      i++;
    }
  return (0);
}

int		add_one_light(t_figure *data,
			      t_bunny_ini *ini,
			      int light,
			      int rounds)
{
  const char	*extract;

  if (((bunny_ini_get_field(ini, "light", "pos", light * 3)) == NULL)
      || ((bunny_ini_get_field(ini, "light", "pos", light * 3 + 1)) == NULL)
      || ((bunny_ini_get_field(ini, "light", "pos", light * 3 + 2)) == NULL)
      || ((bunny_ini_get_field(ini, "light", "color", light)) == NULL))
    return (failed_figure("light"));
  extract = bunny_ini_get_field(ini, "light", "pos", light * 3);
  data->pos.x = my_getnbr(extract);
  extract = bunny_ini_get_field(ini, "light", "pos", light * 3 + 1);
  data->pos.y = my_getnbr(extract);
  extract = bunny_ini_get_field(ini, "light", "pos", light * 3 + 2);
  data->pos.z = my_getnbr(extract);
  extract = bunny_ini_get_field(ini, "light", "color", light);
  data->color.full = (double)my_getunbr(extract);
  data->color.argb[3] = 0xFF;
  data->type = 5;
  if (light == rounds - 1)
    properly_loaded(data, 1);
  else
    properly_loaded(data, 0);
  return (0);
}

int		load_lights(t_bunny_ini *ini, t_rtracer *data)
{
  const char	*extract;
  int		rounds;
  int		i;

  if ((extract = bunny_ini_get_field(ini, "light", "nb", 0)) == NULL)
    {
      data->nb_lights = 0;
      return (0);
    }
  rounds = my_getnbr(extract);
  if ((data->lights = bunny_malloc(sizeof(t_figure) * rounds)) == NULL)
    return (failed_alloc());
  data->nb_lights = rounds;
  i = 0;
  while (i < rounds)
    {
      if (add_one_light(&data->lights[i], ini, i, rounds) == - 1)
	return (-1);
      i++;
    }
  return (0);
}

double		get_double_next(const char *nb, int i, int size, int sign)
{
  double	out;
  double	decim;

  size = size / 10;
  out = 0.0;
  while (*(nb + i) != '.' && *(nb + i))
    {
      out += (double)((*(nb + i) - 48) * size);
      size = size / 10;
      i++;
    }
  if (*(nb + i) != '.')
    return (sign == 1 ? -out : out);
  i++;
  decim = 0.1;
  while (*(nb + i))
    {
      out += (double)((*(nb + i) - 48) * decim);
      decim = decim / 10.0;
      i++;
    }
  return (sign == 1 ? -out : out);
}

double	get_double(const char *nb)
{
  int	sign;
  int	i;
  int	j;
  int	size;

  i = 0;
  sign = 0;
  if (*nb == '-')
    {
      i = 1;
      sign = 1;
    }
  j = i;
  size = 1;
  while (*(nb + j) != '.' && *(nb + j))
    {
      j++;
      size *= 10;
    }
  return (get_double_next(nb, i, size, sign));
}
