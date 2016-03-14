/*
** main.c for raytracer1 in /home/rotaru_i
**
** Made by Iulian Rotaru
** Login   <rotaru_i@epitech.net>
**
** Started on  Sat Feb 13 17:39:52 2016 Iulian Rotaru
** Last update Sun Mar 13 14:48:44 2016 Iulian Rotaru
*/

#include "raytracer1.h"

int		main(int argc, char **argv)
{
  t_rtracer	data;

  set_max_heap_size(100);
  if (argc != 2)
    return (-1);
  if ((data.win = bunny_start(1920, 1080, 1, "//Raytracer1\\\\")) == NULL)
    return (-1);
  if ((data.pix = bunny_new_pixelarray(1920, 1080)) == NULL)
    return (-1);
  main_default(&data);
  if (load_file(&data, argv[1]) == -1)
    return (-1);
  if ((data.dists = bunny_malloc(sizeof(int) * (1920 * 1080))) == NULL)
    return (-1);
  data.edit = 0;
  data.scr_dist = 2.0;
  data.scr_size.x = 1.92 * 1.0;
  data.scr_size.y = 1.08 * 1.0;
  bunny_set_loop_main_function((t_bunny_loop)loop);
  bunny_set_key_response((t_bunny_key)key);
  bunny_loop(data.win, 60, &data);
  bunny_stop(data.win);
  return (0);
}
