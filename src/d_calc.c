/*
** d_calc.c for raytracer1 in /home/rotaru_i
**
** Made by Iulian Rotaru
** Login   <rotaru_i@epitech.net>
**
** Started on  Sun Mar 13 12:11:47 2016 Iulian Rotaru
** Last update Sun Mar 13 21:17:36 2016 Iulian Rotaru
*/

#include "raytracer1.h"

void	d_calc(double *d, t_figure *tmp)
{
  *d = - (tmp->pos.x
	  * tmp->vec[1].x
	  + tmp->pos.y
	  * tmp->vec[1].y
	  + tmp->pos.z
	  * tmp->vec[1].z);
}

int	t_calc(double *t, t_figure *tmp, t_pos *test, t_pos *vec)
{
  if (tmp->vec[1].x * vec[1].x + tmp->vec[1].y
      * vec[1].y + tmp->vec[1].z * vec[1].z == 0.0)
    return (-1);
  *t = - ((tmp->vec[1].x * test->x + tmp->vec[1].y
	   * test->y + tmp->vec[1].z * test->z) /
	  (double)(tmp->vec[1].x * vec[1].x +
		   tmp->vec[1].y * vec[1].y + tmp->vec[1].z * vec[1].z));
  return (0);
}

void	dist_calc(double *dist, t_pos *point, t_pos *vec)
{
  *dist = sqrt(pow(point->x - vec[0].x, 2)
	       + pow(point->y - vec[0].y, 2)
	       + pow(point->z - vec[0].z, 2));
}

void	other_useless_fct(t_pos *point, double *t, t_pos *vec)
{
  point->x = vec[1].x * *t + vec[0].x;
  point->y = vec[1].y * *t + vec[0].y;
  point->z = vec[1].z * *t + vec[0].z;
}

void	norm_pls(double *dist,
		 t_color *dark,
		 t_rtracer *data,
		 t_bunny_position *pos)
{
  dark->argb[3] = (0xFF / 60) * ((*dist - 300.0) / 10.0);
  ((unsigned int *)data->pix->pixels)
    [pos->y * data->pix->clipable.clip_width + pos->x]
    = color_mixer(((unsigned int *)data->pix->pixels)
		  [pos->y * data->pix->clipable.clip_width
		   + pos->x], dark->full);
}
