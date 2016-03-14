/*
** tekray.c for raytracer1 in /home/rotaru_i/Coding/Liblap/gfx_raytracer1/tcore
**
** Made by Iulian Rotaru
** Login   <rotaru_i@epitech.net>
**
** Started on  Sat Mar 12 15:53:42 2016 Iulian Rotaru
** Last update Sat Mar 12 15:56:15 2016 Iulian Rotaru
*/

#include <lapin.h>

void	tekray(const t_bunny_position *screen_info,
	       int *x,
	       int *y,
	       int *z)
{
  *x = - (screen_info[0].x / 2) + screen_info[1].x;
  *y = - (screen_info[0].y / 2) + screen_info[1].y;
  *z = 100;
}
