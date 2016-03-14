/*
** loop.c for raytracer1 in /home/rotaru_i
**
** Made by Iulian Rotaru
** Login   <rotaru_i@epitech.net>
**
** Started on  Sun Mar 13 12:46:59 2016 Iulian Rotaru
** Last update Sun Mar 13 14:49:32 2016 Iulian Rotaru
*/

#include <unistd.h>
#include "raytracer1.h"

t_bunny_response	loop(void *info)
{
  t_rtracer		*data;
  int			i;

  data = (t_rtracer *)info;
  while (i < 1920 * 1080)
    {
      if (data->dists[i] != 0)
	data->dists[i] = 0;
      i++;
    }
  move_eye(data);
  if (data->move == 0 || data->move == 2)
    clear(data->pix);
  if (data->move == 0)
    do_the_ray_tracing(data);
  bunny_blit(&data->win->buffer, &data->pix->clipable, NULL);
  bunny_display(data->win);
  return (GO_ON);
}

int	my_putstr(char *str)
{
  int	i;

  i = 0;
  while (str[i])
    my_putchar(str[i++]);
  return (i);
}

void	my_putchar(char c)
{
  write(1, &c, 1);
}

int	failed_alloc()
{
  my_putstr("Failed bunny_malloc()\n");
  return (-1);
}

int	failed_figure(char *str)
{
  my_putstr("Error: Invalid parameters for figure ");
  my_putstr(str);
  my_putstr("\n");
  return (-1);
}
