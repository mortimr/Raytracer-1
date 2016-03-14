/*
** useless_fct.c for raytracer1 in /home/rotaru_i
**
** Made by Iulian Rotaru
** Login   <rotaru_i@epitech.net>
**
** Started on  Sun Mar 13 12:08:39 2016 Iulian Rotaru
** Last update Sun Mar 13 21:20:53 2016 Iulian Rotaru
*/

#include "raytracer1.h"

void	useless_fct(t_pos *pos, t_pos *a)
{
  pos->x = a->x;
  pos->y = a->y;
  pos->z = a->z;
}

void	angle_next(t_color *light_col,
		   double *angle,
		   t_bunny_position *pos,
		   t_rtracer *data)
{
  *angle = 180 - *angle;
  light_col->argb[3] = (sqrt(90) - sqrt(*angle)) * 0xEE / sqrt(90);
  ((unsigned int *)data->pix->pixels)
    [pos->y * data->pix->clipable.clip_width + pos->x]
    = color_mixer(((unsigned int *)data->pix->pixels)
		  [pos->y * data->pix->clipable.clip_width +
		   pos->x], light_col->full);
}

void	angle_next_next(t_color *light_col,
			t_bunny_position *pos,
			t_rtracer *data)
{
  light_col->argb[3] = 0x00;
  ((unsigned int *)data->pix->pixels)
    [pos->y * data->pix->clipable.clip_width + pos->x]
    = color_mixer(((unsigned int *)data->pix->pixels)
		  [pos->y * data->pix->clipable.clip_width +
		   pos->x], light_col->full);
}

void	angle_manager(t_color *light_col,
		      double *angle,
		      t_bunny_position *pos,
		      t_rtracer *data)
{
  if (*angle <= 90)
    angle_lower(light_col, angle, pos, data);
  else
    angle_high(light_col, pos, data);
  if (*angle >= 90 && *angle <= 180)
    angle_next(light_col, angle, pos, data);
  else
    angle_next_next(light_col, pos, data);
}

void		check_light_plan(t_bunny_position *pos,
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
      if (check_obstacles_plan(data, point, &data->lights[i], obj) == 0.0)
	{
	  useless_fct(&norm, &obj->vec[1]);
	  light_calc(light, &data->lights[i].pos, point);
	  angle_calc(&angle, &norm, light);
	  light_col.full = data->lights[i].color.full;
	  angle_manager(&light_col, &angle, pos, data);
	}
      i++;
    }
}
