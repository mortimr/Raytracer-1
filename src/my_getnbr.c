/*
** new_my_getnbr.c for my_getnbr in /home/rotaru_i/workspace/my_getnbr
**
** Made by iulian rotaru
** Login   <rotaru_i@epitech.net>
**
** Started on  Sun Oct  4 15:28:03 2015 iulian rotaru
** Last update Sun Mar 13 13:19:45 2016 Iulian Rotaru
*/

int	my_strlen(const char *str)
{
  int	i;

  i = 0;
  while (str[i])
    i++;
  return (i);
}

int	my_getnbr(const char *nb)
{
  int	multi;
  int	out;
  int	i;

  i = my_strlen(nb) - 1;
  multi = 1;
  out = 0;
  while (i >= 0)
    {
      if (nb[i] >= '0' && nb[i] <= '9')
	out += (nb[i] - 48) * multi;
      if (nb[i] == '-')
	out = - out;
      multi *= 10;
      i--;
    }
  return (out);
}

int		my_getunbr(const char *nb)
{
  unsigned int	multi;
  unsigned int	out;
  int		i;

  i = my_strlen(nb) - 1;
  multi = 1;
  out = 0;
  while (i >= 0)
    {
      if (nb[i] >= '0' && nb[i] <= '9')
	out += (nb[i] - 48) * multi;
      if (nb[i] == '-')
	return (0);
      multi *= 10;
      i--;
    }
  return (out);
}
