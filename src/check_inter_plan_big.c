/*
** check_inter_plan_big.c for raytracer1 in /home/rotaru_i
**
** Made by Iulian Rotaru
** Login   <rotaru_i@epitech.net>
**
** Started on  Sun Mar 13 12:35:17 2016 Iulian Rotaru
** Last update Sun Mar 13 21:17:24 2016 Iulian Rotaru
*/

#include "raytracer1.h"

void		check_inter_plan_big(t_rtracer *data,
				     t_figure *tmp,
				     t_bunny_position *pos,
				     double *dist)
{
  t_color	dark;

  dark.full = BLACK;
  if (data->dists[pos->y * data->pix->clipable.clip_width + pos->x] == 0
      || data->dists[pos->y * data->pix->clipable.clip_width + pos->x] > *dist)
    {
      if (*dist > 300.0 && *dist < 900.0)
	norm_pls(dist, &dark, data, pos);
      if (*dist > 900.0)
	{
	  dark.argb[3] = 0xFF;
	  ((unsigned int *)data->pix->pixels)
	    [pos->y * data->pix->clipable.clip_width + pos->x]
	    = color_mixer(((unsigned int *)data->pix->pixels)
			  [pos->y * data->pix->clipable.clip_width
			   + pos->x], dark.full);
	}
      else
	tekpixel(data->pix, pos, &tmp->color);
    }
}

void		check_inter_plan(t_rtracer *data,
				 t_pos *vec,
				 t_figure *tmp,
				 t_bunny_position *pos)
{
  double	d;
  double	t;
  t_pos		test;
  t_pos		point;
  double	dist;

  vec_calc(&test, &tmp->pos, &vec[0]);
  d_calc(&d, tmp);
  if (t_calc(&t, tmp, &test, vec) == -1)
    return;
  if (t > 0.0 && t < 1000.0)
    {
      other_useless_fct(&point, &t, vec);
      dist_calc(&dist, &point, &vec[0]);
      check_inter_plan_big(data, tmp, pos, &dist);
      if ((data->dists[pos->y * data->pix->clipable.clip_width + pos->x] == 0
	   || data->dists[pos->y *
			  data->pix->clipable.clip_width + pos->x] > dist)
	  && (data->edit == 0))
	check_light_plan(pos, &point, data, tmp);
    }
}

void	inter_create_poly(t_polynome *poly, t_pos *vec, t_figure *tmp)
{
  poly->coeff_two = pow(vec[1].x, 2) + pow(vec[1].y, 2) + pow(vec[1].z, 2);
  poly->coeff_one = 2.0 * ((vec[1].x * (vec[0].x - tmp->pos.x)) +
			   (vec[1].y * (vec[0].y - tmp->pos.y)) +
			   (vec[1].z * (vec[0].z - tmp->pos.z)));
  poly->coeff_zero = pow(vec[0].x - tmp->pos.x, 2)
    + pow(vec[0].y - tmp->pos.y, 2)
    + pow(vec[0].z - tmp->pos.z, 2)
    - pow(tmp->radius, 2);
}

void	delta_calc(double *delta, t_polynome *poly)
{
  *delta = (double)((poly->coeff_one * poly->coeff_one)
		    - 4.0 * poly->coeff_two * poly->coeff_zero);
}

void	t_calcu(double *t, t_polynome *poly, double *delta)
{
  t[0] = (- poly->coeff_one - sqrt(*delta)) / (2.0 * poly->coeff_two);
  t[1] = (- poly->coeff_one + sqrt(*delta)) / (2.0 * poly->coeff_two);
}
