/*
** load_eyes_next.c for raytracer1 in /home/rotaru_i
**
** Made by Iulian Rotaru
** Login   <rotaru_i@epitech.net>
**
** Started on  Sun Mar 13 13:07:14 2016 Iulian Rotaru
** Last update Sun Mar 13 13:41:52 2016 Iulian Rotaru
*/

#include "raytracer1.h"

void	load_eyes_next(t_rtracer *data, t_bunny_ini *ini)
{
  data->eye.x = get_double(bunny_ini_get_field(ini, "eye", "pos", 0));
  data->eye.y = get_double(bunny_ini_get_field(ini, "eye", "pos", 1));
  data->eye.z = get_double(bunny_ini_get_field(ini, "eye", "pos", 2));
  data->eye_dir.x = get_double(bunny_ini_get_field(ini, "eye", "dir", 0));
  data->eye_dir.y = get_double(bunny_ini_get_field(ini, "eye", "dir", 1));
  data->eye_dir.z = get_double(bunny_ini_get_field(ini, "eye", "dir", 2));
  data->eye_up.x = get_double(bunny_ini_get_field(ini, "eye", "up", 0));
  data->eye_up.y = get_double(bunny_ini_get_field(ini, "eye", "up", 1));
  data->eye_up.z = get_double(bunny_ini_get_field(ini, "eye", "up", 2));
  data->eye_right.x = get_double(bunny_ini_get_field(ini, "eye", "right", 0));
  data->eye_right.y = get_double(bunny_ini_get_field(ini, "eye", "right", 1));
  data->eye_right.z = get_double(bunny_ini_get_field(ini, "eye", "right", 2));
}

int		load_eyes(t_bunny_ini *ini, t_rtracer *data)
{
  const	char	*extract;

  if ((extract = bunny_ini_get_field(ini, "eye", "pos", 0)) == NULL)
    return (0);
  if (((bunny_ini_get_field(ini, "eye", "pos", 0)) == NULL)
      || ((bunny_ini_get_field(ini, "eye", "pos", 1)) == NULL)
      || ((bunny_ini_get_field(ini, "eye", "pos", 2)) == NULL)
      || ((bunny_ini_get_field(ini, "eye", "dir", 0)) == NULL)
      || ((bunny_ini_get_field(ini, "eye", "dir", 1)) == NULL)
      || ((bunny_ini_get_field(ini, "eye", "dir", 2)) == NULL)
      || ((bunny_ini_get_field(ini, "eye", "up", 0)) == NULL)
      || ((bunny_ini_get_field(ini, "eye", "up", 1)) == NULL)
      || ((bunny_ini_get_field(ini, "eye", "up", 2)) == NULL)
      || ((bunny_ini_get_field(ini, "eye", "right", 0)) == NULL)
      || ((bunny_ini_get_field(ini, "eye", "right", 1)) == NULL)
      || ((bunny_ini_get_field(ini, "eye", "right", 2)) == NULL))
    return (failed_figure("eye"));
  load_eyes_next(data, ini);
  return (0);
}

int	load_file_next(t_rtracer *data, t_bunny_ini *ini)
{
  if ((load_lights(ini, data)) == -1)
    return (-1);
  if ((load_eyes(ini, data)) == -1)
    return (-1);
  return (0);
}

int		load_file(t_rtracer *data, char *file)
{
  t_bunny_ini	*ini;

  if ((ini = bunny_load_ini(file)) == NULL)
    return (-1);
  if ((data->figure = bunny_malloc(sizeof(t_figure))) == NULL)
    return (-1);
  if ((load_sphere(ini, data)) == -1)
    return (-1);
  if ((load_plans(ini, data)) == -1)
    return (-1);
  if (load_file_next(data, ini) == -1)
    return (-1);
  return (0);
}

void	main_default(t_rtracer *data)
{
  data->idx = 0;
  data->nb_figures = 0;
  data->eye.x = 0.0;
  data->eye.y = 0.0;
  data->eye.z = 0.0;
  data->eye_dir.x = 0.0;
  data->eye_dir.y = 0.0;
  data->eye_dir.z = 1.0;
  data->eye_up.z = 0.0;
  data->eye_up.x = 0.0;
  data->eye_up.y = 1.0;
  data->eye_right.x = 1.0;
  data->eye_right.y = 0.0;
  data->eye_right.z = 0.0;
}
