/*
** tekpixel.c for raytracer in /home/rotaru_i/Coding/Liblap/gfx_raytracer1/tcore
**
** Made by Iulian Rotaru
** Login   <rotaru_i@epitech.net>
**
** Started on  Fri Mar 11 15:04:01 2016 Iulian Rotaru
** Last update Sun Mar 13 13:24:45 2016 Iulian Rotaru
*/

#include <lapin.h>

void	tekpixel(t_bunny_pixelarray *pix,
		 t_bunny_position *pos,
		 t_color *color)
{
  if ((pos->x >= 0 && pos->x < pix->clipable.clip_width)
      && (pos->y >= 0 && pos->y < pix->clipable.clip_height))
    ((unsigned int*)pix->pixels)
      [pos->y * pix->clipable.clip_width + pos->x] = color->full;
}
