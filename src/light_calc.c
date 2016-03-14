/*
** light_calc.c for raytracer1 in /home/rotaru_i
**
** Made by Iulian Rotaru
** Login   <rotaru_i@epitech.net>
**
** Started on  Sun Mar 13 12:01:14 2016 Iulian Rotaru
** Last update Sun Mar 13 21:18:27 2016 Iulian Rotaru
*/

#include "raytracer1.h"

void	light_calc(t_pos *light, t_pos *a, t_pos *b)
{
  light[1].x = b->x - a->x;
  light[1].y = b->y - a->y;
  light[1].z = b->z - a->z;
  light[0].x = a->x;
  light[0].y = a->y;
  light[0].z = a->z;
}

void	angle_calc(double *angle, t_pos *norm, t_pos *light)
{
  *angle = acos((norm->x * light[1].x + norm->y *
		 light[1].y + norm->z * light[1].z)
		/ (sqrt(pow(norm->x, 2) + pow(norm->y, 2)
			+ pow(norm->z, 2)) * sqrt(pow(light[1].x, 2)
						  + pow(light[1].y, 2)
						  + pow(light[1].z, 2))));
  *angle = *angle * 180 / M_PI;
}

void	angle_lower(t_color *light_col,
		    double *angle,
		    t_bunny_position *pos,
		    t_rtracer *data)
{
  light_col->argb[3] = (sqrt(90) - sqrt(*angle)) * 0xEE / sqrt(90);
  ((unsigned int *)data->pix->pixels)
    [pos->y * data->pix->clipable.clip_width + pos->x]
    = color_mixer(((unsigned int *)data->pix->pixels)
		  [pos->y * data->pix->clipable.clip_width
		   + pos->x], light_col->full);
}

void	angle_high(t_color *light_col,
		   t_bunny_position *pos,
		   t_rtracer *data)
{
  light_col->argb[3] = 0x00;
  ((unsigned int *)data->pix->pixels)
    [pos->y * data->pix->clipable.clip_width + pos->x]
    = color_mixer(((unsigned int *)data->pix->pixels)
		  [pos->y * data->pix->clipable.clip_width
		   + pos->x], light_col->full);
}

void		check_light(t_bunny_position *pos,
			    t_pos *point,
			    t_rtracer *data,
			    t_figure *obj)
{
  t_pos		norm;
  t_pos		light[2];
  int		i;
  double	angle;
  t_color	light_col;

  i = 0;
  while (i < data->nb_lights)
    {
      if (check_obstacles_sphere(data, point, &data->lights[i], obj) == 0.0)
	{
	  vec_calc(&norm, point, &obj->pos);
	  light_calc(light, &data->lights[i].pos, point);
	  angle_calc(&angle, &norm, light);
	  light_col.full = data->lights[i].color.full;
	  if (angle <= 90)
	    angle_lower(&light_col, &angle, pos, data);
	  else
	    angle_high(&light_col, pos, data);
	}
      i++;
    }
}
