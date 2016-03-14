/*
** move_eye_hori.c for raytracer1 in /home/rotaru_i
**
** Made by Iulian Rotaru
** Login   <rotaru_i@epitech.net>
**
** Started on  Sun Mar 13 11:51:32 2016 Iulian Rotaru
** Last update Sun Mar 13 14:49:19 2016 Iulian Rotaru
*/

#include "raytracer1.h"

void	move_eye_hori(t_rtracer *data, double accel)
{
  if (bunny_get_keyboard()[BKS_D] == 1)
    {
      data->move = 2;
      data->eye.x += data->eye_right.x * accel;
      data->eye.y += data->eye_right.y * accel;
      data->eye.z += data->eye_right.z * accel;
    }
  else if (bunny_get_keyboard()[BKS_A] == 1)
    {
      data->move = 2;
      data->eye.x -= data->eye_right.x * accel;
      data->eye.y -= data->eye_right.y * accel;
      data->eye.z -= data->eye_right.z * accel;
    }
}

void	move_eye_verti(t_rtracer *data, double accel)
{
  if (bunny_get_keyboard()[BKS_W] == 1)
    {
      data->move = 2;
      data->eye.x += data->eye_dir.x * accel;
      data->eye.y += data->eye_dir.y * accel;
      data->eye.z += data->eye_dir.z * accel;
    }
  else if (bunny_get_keyboard()[BKS_S] == 1)
    {
      data->move = 2;
      data->eye.x -= data->eye_dir.x * accel;
      data->eye.y -= data->eye_dir.y * accel;
      data->eye.z -= data->eye_dir.z * accel;
    }
}

void	move_eye_next(t_rtracer *data, double *accel)
{
  if (*accel == 0.0)
    *accel = 1;
  if (bunny_get_keyboard()[BKS_K] == 1)
    data->move = 0;
  if (bunny_get_keyboard()[BKS_P] == 1)
    {
      if (*accel < 70.0)
	*accel *= 2.0;
      else
	*accel = 1;
    }
}

void		move_eye(t_rtracer *data)
{
  static double	accel;

  if (data->edit == 1)
    {
      move_eye_next(data, &accel);
      move_eye_verti(data, accel);
      move_eye_hori(data, accel);
      if (bunny_get_keyboard()[BKS_SPACE] == 1)
	{
	  data->move = 2;
	  data->eye.x += data->eye_up.x * accel;
	  data->eye.y += data->eye_up.y * accel;
	  data->eye.z += data->eye_up.z * accel;
	}
      else if (bunny_get_keyboard()[BKS_LCONTROL] == 1)
	{
	  data->move = 2;
	  data->eye.x -= data->eye_up.x * accel;
	  data->eye.y -= data->eye_up.y * accel;
	  data->eye.z -= data->eye_up.z * accel;
	}
    }
}

t_bunny_response	key(t_bunny_event_state state,
			    t_bunny_keysym sym,
			    void *info)
{
  t_rtracer		*data;

  data = (t_rtracer *)info;
  data->move = 0;
  if (state == GO_DOWN && sym == BKS_ESCAPE)
    return (EXIT_ON_SUCCESS);
  if (state == GO_DOWN && sym == BKS_E && data->edit == 0)
    {
      data->edit = 1;
      data->move = 0;
    }
  else if (state == GO_DOWN && sym == BKS_E && data->edit == 1)
    {
      data->edit = 0;
      data->move = 0;
    }
  return (GO_ON);
}
