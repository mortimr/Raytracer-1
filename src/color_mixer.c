/*
** color_mixer.c for raytracer1 in /home/rotaru_i
**
** Made by Iulian Rotaru
** Login   <rotaru_i@epitech.net>
**
** Started on  Sun Mar 13 11:54:27 2016 Iulian Rotaru
** Last update Sun Mar 13 18:33:57 2016 Iulian Rotaru
*/

#include "raytracer1.h"

unsigned int	color_mixer(unsigned int one, unsigned int add)
{
  t_color	first;
  t_color	adder;
  t_color	out;
  double	coeff;

  first.full = one;
  adder.full = add;
  coeff = adder.argb[3] / 256.0;
  out.argb[0] = adder.argb[0] * coeff + first.argb[0] * (1.0 - coeff);
  out.argb[1] = adder.argb[1] * coeff + first.argb[1] * (1.0 - coeff);
  out.argb[2] = adder.argb[2] * coeff + first.argb[2] * (1.0 - coeff);
  out.argb[3] = adder.argb[3] * coeff + first.argb[3] * (1.0 - coeff);
  return (out.full);
}

void	vec_calc(t_pos *vec, t_pos *a, t_pos *b)
{
  vec->x = b->x - a->x;
  vec->y = b->y - a->y;
  vec->z = b->z - a->z;
}

void	create_poly_obs_sphere(t_polynome *pol,
			       t_figure *tmp,
			       t_pos *vec,
			       t_pos *dir)
{
  pol->coeff_two = pow(dir->x, 2) + pow(dir->y, 2) + pow(dir->z, 2);
  pol->coeff_one = 2.0 * ((tmp->pos.x - vec[0].x) * dir->x +
			  (tmp->pos.y - vec[0].y) * dir->y +
			  (tmp->pos.z - vec[0].z) * dir->z);
  pol->coeff_zero = pow(vec[0].x - tmp->pos.x, 2) +
    pow(vec[0].y - tmp->pos.y, 2) +
    pow(vec[0].z - tmp->pos.z, 2) - pow(tmp->radius, 2);
}

void	create_poly_obs_plan(t_polynome *pol,
			     t_figure *tmp,
			     t_pos *vec,
			     t_pos *dir)
{
  pol->coeff_two = pow(dir->x, 2) + pow(dir->y, 2) + pow(dir->z, 2);
  pol->coeff_one = 2.0 * ((vec[0].x - tmp->pos.x) * dir->x +
			  (vec[0].y - tmp->pos.y) * dir->y +
			  (vec[0].z - tmp->pos.z) * dir->z);
  pol->coeff_zero = pow(vec[0].x - tmp->pos.x, 2) +
    pow(vec[0].y - tmp->pos.y, 2) +
    pow(vec[0].z - tmp->pos.z, 2) - pow(tmp->radius, 2);
}

void	calc_the_ts(double *t, t_polynome *pol)
{
  t[0] = (-pol->coeff_one + sqrt(pow(pol->coeff_one, 2) - 4.0 *
				 pol->coeff_two * pol->coeff_zero))
    / (2.0 * pol->coeff_two);
  t[1] = (pol->coeff_one + sqrt(pow(pol->coeff_one, 2) - 4.0 *
				pol->coeff_two * pol->coeff_zero))
    / (2.0 * pol->coeff_two);
}
