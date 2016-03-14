/*
** check_inter.c for raytracer1 in /home/rotaru_i
**
** Made by Iulian Rotaru
** Login   <rotaru_i@epitech.net>
**
** Started on  Sun Mar 13 12:41:59 2016 Iulian Rotaru
** Last update Sun Mar 13 16:12:05 2016 Iulian Rotaru
*/

#include "raytracer1.h"

void		check_inter(t_rtracer *data,
			    t_pos *vec,
			    int nb,
			    t_bunny_position *pos)
{
  t_polynome	poly;
  double	delta;
  t_figure	*tmp;
  double	t[2];
  t_pos		out;
  double	dist;

  tmp = tmp_finder(data, nb);
  if (tmp->type == 1)
    {
      if ((data->edit == 1 && tmp->color.full != 0) || (data->edit == 0))
	{
	  inter_create_poly(&poly, vec, tmp);
	  delta_calc(&delta, &poly);
	  if (delta > 0.0)
	    {
	      t_calcu(t, &poly, &delta);
	      t_choice(t, &out, vec, &dist);
	      data->tmp = tmp;
	      norm_pls_again(data, pos, &out, &dist);
	    }
	}
    }
  if (tmp->type == 2)
    check_inter_plan(data, vec, tmp, pos);
}

void	prepare_raytracing(t_rtracer *data)
{
  data->upleft.x = data->eye.x +
    ((data->eye_dir.x * (double)data->scr_dist)
     + (data->eye_up.x * ((double)data->scr_size.y / 2.0))
     - (data->eye_right.x * ((double)data->scr_size.x / 2.0)));
  data->upleft.y = data->eye.y +
    ((data->eye_dir.y * (double)data->scr_dist)
     + (data->eye_up.y * ((double)data->scr_size.y / 2.0))
     - (data->eye_right.y * ((double)data->scr_size.x / 2.0)));
  data->upleft.z = data->eye.z +
    ((data->eye_dir.z * (double)data->scr_dist)
     + (data->eye_up.z * ((double)data->scr_size.y / 2.0))
     - (data->eye_right.z * ((double)data->scr_size.x / 2.0)));
  data->x_indent = (double)(data->scr_size.x
			    / (double)data->pix->clipable.clip_width);
  data->y_indent = (double)(data->scr_size.y
			    / (double)data->pix->clipable.clip_height);
}

void	main_vec_calc(t_rtracer *data, t_bunny_position *blit, t_pos *vec)
{
  vec[0].x = data->eye.x;
  vec[0].y = data->eye.y;
  vec[0].z = data->eye.z;
  vec[1].x = data->upleft.x + data->eye_right.x *
    (double)(blit->x * data->x_indent) - data->eye_up.x *
    (double)(blit->y * data->y_indent) - data->eye.x;
  vec[1].y = data->upleft.y + data->eye_right.y *
    (double)(blit->x * data->x_indent) - data->eye_up.y *
    (double)(blit->y * data->y_indent) - data->eye.y;
  vec[1].z = data->upleft.z + data->eye_right.z *
    (double)(blit->x * data->x_indent) - data->eye_up.z *
    (double)(blit->y * data->y_indent) - data->eye.z;
}

void			do_the_ray_tracing(t_rtracer *data)
{
  t_pos			vec[2];
  t_bunny_position	blit;
  int			i;

  prepare_raytracing(data);
  blit.y = 0;
  while (blit.y < data->pix->clipable.clip_height)
    {
      blit.x = 0;
      while (blit.x < data->pix->clipable.clip_width)
	{
	  main_vec_calc(data, &blit, vec);
	  i = 0;
	  while (i < data->nb_figures)
	    {
	      check_inter(data, vec, i, &blit);
	      i++;
	    }
	  blit.x++;
	}
      blit.y++;
    }
  data->move = 1;
}

void	clear(t_bunny_pixelarray *pix)
{
  int	i;

  i = 0;
  while (i < pix->clipable.clip_width * pix->clipable.clip_height)
    {
      if (((unsigned int *)pix->pixels)[i] != (unsigned int)BLACK)
	((unsigned int *)pix->pixels)[i] = (unsigned int)BLACK;
      i++;
    }
}
