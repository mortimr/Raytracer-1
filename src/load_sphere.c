/*
** load_sphere.c for raytracer1 in /home/rotaru_i
**
** Made by Iulian Rotaru
** Login   <rotaru_i@epitech.net>
**
** Started on  Sun Mar 13 12:57:36 2016 Iulian Rotaru
** Last update Sun Mar 13 14:43:55 2016 Iulian Rotaru
*/

#include "raytracer1.h"

int		load_sphere(t_bunny_ini *ini, t_rtracer *data)
{
  const char	*extract;
  int		rounds;
  int		i;

  if ((extract = bunny_ini_get_field(ini, "sphere", "nb", 0)) == NULL)
    return (0);
  i = 0;
  rounds = my_getnbr(extract);
  while (i < rounds)
    {
      if (add_one_sphere(data, ini, i) == -1)
	return (-1);
      i++;
    }
  return (0);
}

void		add_one_plan_job_next(t_bunny_ini *ini,
				      t_figure *tmp,
				      int plan)
{
  const char	*extract;

  extract = bunny_ini_get_field(ini, "plan", "pos", plan * 3);
  tmp->pos.x = my_getnbr(extract);
  extract = bunny_ini_get_field(ini, "plan", "pos", plan * 3 + 1);
  tmp->pos.y = my_getnbr(extract);
  extract = bunny_ini_get_field(ini, "plan", "pos", plan * 3 + 2);
  tmp->pos.z = my_getnbr(extract);
  extract = bunny_ini_get_field(ini, "plan", "vec_dir", plan * 3);
  tmp->vec[0].x = my_getnbr(extract);
  extract = bunny_ini_get_field(ini, "plan", "vec_dir", plan * 3 + 1);
  tmp->vec[0].y = my_getnbr(extract);
  extract = bunny_ini_get_field(ini, "plan", "vec_dir", plan * 3 + 2);
  tmp->vec[0].z = my_getnbr(extract);
}

void		add_one_plan_job(t_bunny_ini *ini,
				 t_figure *tmp,
				 t_rtracer *data,
				 int plan)
{
  const char	*extract;

  add_one_plan_job_next(ini, tmp, plan);
  extract = bunny_ini_get_field(ini, "plan", "vec_norm", plan * 3);
  tmp->vec[1].x = my_getnbr(extract);
  extract = bunny_ini_get_field(ini, "plan", "vec_norm", plan * 3 + 1);
  tmp->vec[1].y = my_getnbr(extract);
  extract = bunny_ini_get_field(ini, "plan", "vec_norm", plan * 3 + 2);
  tmp->vec[1].z = my_getnbr(extract);
  extract = bunny_ini_get_field(ini, "plan", "color", plan);
  tmp->color.full = my_getnbr(extract);
  extract = bunny_ini_get_field(ini, "plan", "damier", plan);
  tmp->damier = my_getnbr(extract);
  tmp->type = 2;
  tmp->idx = data->idx;
  data->idx += 1;
  data->nb_figures += 1;
  properly_loaded(tmp, 0);
}

int	big_if(t_bunny_ini *ini, int plan)
{
  if ((bunny_ini_get_field(ini, "plan", "pos", plan * 3) == NULL)
      || (bunny_ini_get_field(ini, "plan", "pos", plan * 3 + 1) == NULL)
      || (bunny_ini_get_field(ini, "plan", "pos", plan * 3 + 2) == NULL)
      || (bunny_ini_get_field(ini, "plan", "vec_dir", plan * 3) == NULL)
      || (bunny_ini_get_field(ini, "plan", "vec_dir", plan * 3 + 1) == NULL)
      || (bunny_ini_get_field(ini, "plan", "pos", plan * 3 + 2) == NULL)
      || (bunny_ini_get_field(ini, "plan", "vec_norm", plan * 3) == NULL)
      || (bunny_ini_get_field(ini, "plan", "vec_norm", plan * 3 + 1) == NULL)
      || (bunny_ini_get_field(ini, "plan", "vec_norm", plan * 3 + 2) == NULL)
      || (bunny_ini_get_field(ini, "plan", "color", plan) == NULL)
      || (bunny_ini_get_field(ini, "plan", "damier", plan) == NULL))
    return (failed_figure("plan"));
  return (0);
}

int		add_one_plan(t_rtracer *data, t_bunny_ini *ini, int plan)
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
  if (big_if(ini, plan) == -1)
    return (-1);
  add_one_plan_job(ini, tmp, data, plan);
  return (0);
}
