/*
** find_inter_obst.c for raytracer1 in /home/rotaru_i
**
** Made by Iulian Rotaru
** Login   <rotaru_i@epitech.net>
**
** Started on  Sun Mar 13 11:57:47 2016 Iulian Rotaru
** Last update Sun Mar 13 18:39:17 2016 Iulian Rotaru
*/

#include "raytracer1.h"

void	find_inter_obst(double *t, t_pos *inter, t_pos *vec, t_pos *dir)
{
  if (t[0] > t[1])
    {
      inter->x = dir->x * t[1] + vec[0].x;
      inter->y = dir->y * t[1] + vec[0].y;
      inter->z = dir->z * t[1] + vec[0].z;
    }
  else
    {
      inter->x = dir->x * t[0] + vec[0].x;
      inter->y = dir->y * t[0] + vec[0].y;
      inter->z = dir->z * t[0] + vec[0].z;
    }
}

int	do_the_maths(double *t, t_polynome *pol, t_pos *vec, t_pos *dir)
{
  calc_the_ts(t, pol);
  find_inter_obst(t, &dir[1], vec, dir);
  if (sqrt(pow(vec[0].x - dir[1].x, 2) + pow(vec[0].y - dir[1].y, 2)
	   + pow(vec[0].z - dir[1].z , 2))
      < sqrt(pow(dir[0].x, 2) + pow(dir[0].y, 2) + pow(dir[0].z, 2)))
    return (1);
  return (0);
}

double		check_obstacles_sphere(t_rtracer *data,
				       t_pos *vec,
				       t_figure *lights,
				       t_figure *actu)
{
  t_polynome	pol;
  t_pos		dir[2];
  t_figure	*tmp;
  int		i;
  double	t[2];

  tmp = data->figure;
  i = 0;
  while (tmp)
    {
      if (tmp->type == 1 && i != actu->idx)
	{
	  vec_calc(dir, &vec[0], &lights->pos);
	  create_poly_obs_sphere(&pol, tmp, vec, dir);
	  if ((pow(pol.coeff_one, 2) - 4.0 * pol.coeff_two *
	       pol.coeff_zero > 0)
	      && (do_the_maths(t, &pol, vec, dir) == 1))
	    return (1.0);
	}
      tmp = tmp->next;
      i++;
    }
  return (0.0);
}

double		check_obstacles_plan(t_rtracer *data,
				     t_pos *vec,
				     t_figure *lights,
				     t_figure *actu)
{
  t_polynome	pol;
  t_pos		dir[2];
  t_figure	*tmp;
  int		i;
  double	t[2];

  tmp = data->figure;
  i = 0;
  while (tmp)
    {
      if (tmp->type == 1 && i != actu->idx)
	{
	  vec_calc(dir, &vec[0], &lights->pos);
	  create_poly_obs_plan(&pol, tmp, vec, dir);
	  if ((pow(pol.coeff_one, 2) - 4.0 * pol.coeff_two *
	       pol.coeff_zero > 0.0)
	      && (do_the_maths(t, &pol, vec, dir) == 1))
	    return (1.0);
	}
      tmp = tmp->next;
      i++;
    }
  return (0.0);
}

unsigned int	add_light(unsigned int color, int intens)
{
  double	ratio;
  t_color	out;
  t_color	in;

  ratio = 1.0 - intens / 1000;
  in.full = color;
  out.argb[0] = (1 - ratio * 2) * in.argb[0] + ratio * 0xFF * 2;
  out.argb[1] = (1 - ratio * 2) * in.argb[1] + ratio * 0xFF * 2;
  out.argb[2] = (1 - ratio * 2) * in.argb[2] + ratio * 0xFF * 2;
  out.argb[3] = (1 - ratio * 2) * in.argb[3] + ratio * 0xFF * 2;
  return (out.full);
}
