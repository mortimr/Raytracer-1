/*
** normifier.c for raytracer1 in /home/rotaru_i
**
** Made by Iulian Rotaru
** Login   <rotaru_i@epitech.net>
**
** Started on  Sun Mar 13 12:40:04 2016 Iulian Rotaru
** Last update Sun Mar 13 13:24:22 2016 Iulian Rotaru
*/

#include "raytracer1.h"

void	normifier(t_pos *out, t_pos *vec, double *t, double *dist)
{
  out->x = vec[0].x + vec[1].x * t[1];
  out->y = vec[0].y + vec[1].y * t[1];
  out->z = vec[0].z + vec[1].z * t[1];
  *dist = sqrt(pow(out->x - vec[0].x, 2)
	       + pow(out->y - vec[0].y, 2)
	       + pow(out->z - vec[0].z, 2));
}

void	normifier_two(t_pos *out, t_pos *vec, double *t, double *dist)
{
  out->x = vec[0].x + vec[1].x * t[0];
  out->y = vec[0].y + vec[1].y * t[0];
  out->z = vec[0].z + vec[1].z * t[0];
  *dist = sqrt(pow(out->x - vec[0].x, 2)
	       + pow(out->y - vec[0].y, 2)
	       + pow(out->z - vec[0].z, 2));
}

void	t_choice(double *t, t_pos *out, t_pos *vec, double *dist)
{
  if (t[1] < t[0])
    normifier(out, vec, t, dist);
  else
    normifier_two(out, vec, t, dist);
}

t_figure	*tmp_finder(t_rtracer *data, int nb)
{
  t_figure	*tmp;
  int		i;

  tmp = data->figure;
  i = 0;
  while (i < nb)
    {
      tmp = tmp->next;
      i++;
    }
  return (tmp);
}

void	norm_pls_again(t_rtracer *data,
		       t_bunny_position *pos,
		       t_pos *out,
		       double *dist)
{
  if (data->dists[pos->y * data->pix->clipable.clip_width + pos->x] == 0
      || data->dists[pos->y * data->pix->clipable.clip_width + pos->x] >
      *dist)
    {
      data->dists[pos->y * data->pix->clipable.clip_width + pos->x] = *dist;
      tekpixel(data->pix, pos, &data->tmp->color);
      if (data->edit == 0)
	check_light(pos, out, data, data->tmp);
    }
}
