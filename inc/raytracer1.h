/*
** raytracer1.h for raytracer1 in /home/rotaru_i/Coding/Liblap/gfx_raytracer1/inc
**
** Made by Iulian Rotaru
** Login   <rotaru_i@epitech.net>
**
** Started on  Sat Mar 12 16:28:32 2016 Iulian Rotaru
** Last update Sun Mar 13 21:20:24 2016 Iulian Rotaru
*/

#ifndef RAYTRACER1_H_
# define RAYTRACER1_H_

# include <math.h>
# include <lapin.h>

typedef struct	s_pos
{
  double	x;
  double	y;
  double	z;
}		t_pos;

typedef struct		s_figure
{
  unsigned char		type;
  t_pos			pos;
  t_color		color;
  int			radius;
  t_pos			vec[2];
  int			damier;
  double		intensity;
  int			idx;
  struct s_figure	*next;
}			t_figure;

typedef struct		s_rtracer
{
  unsigned int		*dists;
  int			edit;
  int			scr_dist;
  t_pos			scr_size;
  t_bunny_window	*win;
  t_bunny_pixelarray	*pix;
  t_bunny_pixelarray	*font;
  t_figure		*figure;
  t_figure		*lights;
  unsigned char		nb_figures;
  unsigned char		nb_lights;
  t_pos			eye;
  t_pos			eye_dir;
  t_pos			eye_up;
  t_pos			eye_right;
  unsigned char		idx;
  int			move;
  t_figure		*tmp;
  double		x_indent;
  double		y_indent;
  t_pos			upleft;
}			t_rtracer;

typedef struct	s_polynome
{
  double	coeff_zero;
  double	coeff_one;
  double	coeff_two;
}		t_polynome;

t_bunny_response	key(t_bunny_event_state state,
			    t_bunny_keysym sym,
			    void *info);
void			move_eye(t_rtracer *data);
void			move_eye_next(t_rtracer *data, double *accel);
void			move_eye_verti(t_rtracer *data, double accel);
void			move_eye_hori(t_rtracer *data, double accel);
unsigned int		color_mixer(unsigned int one, unsigned int add);
void			vec_calc(t_pos *vec, t_pos *a, t_pos *b);
void			create_poly_obs_sphere(t_polynome *pol,
					       t_figure *tmp,
					       t_pos *vec,
					       t_pos *dir);
void			create_poly_obs_plan(t_polynome *pol,
					     t_figure *tmp,
					     t_pos *vec,
					     t_pos *dir);
void			calc_the_ts(double *t, t_polynome *pol);
void			find_inter_obst(double *t,
					t_pos *inter,
					t_pos *vec,
					t_pos *dir);
int			do_the_maths(double *t,
				     t_polynome *pol,
				     t_pos *vec,
				     t_pos *dir);
double			check_obstacles_sphere(t_rtracer *data,
					       t_pos *vec,
					       t_figure *lights,
					       t_figure *actu);
double			check_obstacles_plan(t_rtracer *data,
					     t_pos *vec,
					     t_figure *lights,
					     t_figure *actu);
unsigned int		add_light(unsigned int color, int intens);
void			light_calc(t_pos *light, t_pos *a, t_pos *b);
void			angle_calc(double *angle, t_pos *norm, t_pos *light);
void			angle_lower(t_color *light_col,
				    double *angle,
				    t_bunny_position *pos,
				    t_rtracer *data);
void			angle_high(t_color *light_col,
				   t_bunny_position *pos,
				   t_rtracer *data);
void			check_light(t_bunny_position *pos,
				    t_pos *point,
				    t_rtracer *data,
				    t_figure *obj);
void			check_light_plan(t_bunny_position *pos,
					 t_pos *point,
					 t_rtracer *data,
					 t_figure *obj);
void			angle_manager(t_color *light_col,
				      double *angle,
				      t_bunny_position *pos,
				      t_rtracer *data);
void			angle_next_next(t_color *light_col,
					t_bunny_position *pos,
					t_rtracer *data);
void			angle_next(t_color *light_col,
				   double *angle,
				   t_bunny_position *pos,
				   t_rtracer *data);
void			useless_fct(t_pos *pos, t_pos *a);
void			norm_pls(double *dist,
				 t_color *dark,
				 t_rtracer *data,
				 t_bunny_position *pos);
void			other_useless_fct(t_pos *point, double *t, t_pos *vec);
void			dist_calc(double *dist, t_pos *point, t_pos *vec);
int			t_calc(double *t,
			       t_figure *tmp,
			       t_pos *test,
			       t_pos *vec);
void			d_calc(double *d, t_figure *tmp);
void			delta_calc(double *delta, t_polynome *poly);
void			t_calcu(double *t, t_polynome *poly, double *delta);
void			inter_create_poly(t_polynome *poly,
					  t_pos *vec,
					  t_figure *tmp);
void			check_inter_plan(t_rtracer *data,
					 t_pos *vec,
					 t_figure *tmp,
					 t_bunny_position *pos);
void			check_inter_plan_big(t_rtracer *data,
					     t_figure *tmp,
					     t_bunny_position *pos,
					     double *dist);
void			norm_pls_again(t_rtracer *data,
				       t_bunny_position *pos,
				       t_pos *out,
				       double *dist);
t_figure		*tmp_finder(t_rtracer *data, int nb);
void			t_choice(double *t,
				 t_pos *out,
				 t_pos *vec,
				 double *dist);
void			normifier_two(t_pos *out,
				      t_pos *vec,
				      double *t,
				      double *dist);
void			normifier(t_pos *out,
				  t_pos *vec,
				  double *t,
				  double *dist);
int			failed_alloc();
int			failed_figure(char *str);
void			my_putchar(char c);
int			my_putstr(char *str);
t_bunny_response	loop(void *info);
void			clear(t_bunny_pixelarray *pix);
void			do_the_ray_tracing(t_rtracer *data);
void			main_vec_calc(t_rtracer *data,
				      t_bunny_position *blit,
				      t_pos *vec);
void			prepare_raytracing(t_rtracer *data);
void			check_inter(t_rtracer *data,
				    t_pos *vec,
				    int nb,
				    t_bunny_position *pos);
void			my_put_nbr(int nb);
void			my_put_unbr(unsigned int nb);
void			properly_loaded_one(t_figure *data);
void			properly_loaded_two_next(t_figure *data);
void			properly_loaded_two(t_figure *data);
void			tekpixel(t_bunny_pixelarray *pix,
				 t_bunny_position *pos,
				 t_color *color);
int			my_getnbr(const char *nb);
int			my_getunbr(const char *nb);
int			add_one_sphere(t_rtracer *data,
				       t_bunny_ini *ini,
				       int sphere);
void			add_one_sphere_job(t_bunny_ini *ini,
					   t_figure *tmp,
					   t_rtracer *data,
					   int sphere);
void			properly_loaded(t_figure *data, int last);
void			properly_loaded_end(int last);
void			properly_loaded_five(t_figure *data);
int			add_one_plan(t_rtracer *data,
				     t_bunny_ini *ini,
				     int plan);
int			big_if(t_bunny_ini *ini, int plan);
void			add_one_plan_job(t_bunny_ini *ini,
					 t_figure *tmp,
					 t_rtracer *data,
					 int plan);
void			add_one_plan_job_next(t_bunny_ini *ini,
					      t_figure *tmp,
					      int plan);
int			load_sphere(t_bunny_ini *ini, t_rtracer *data);
double			get_double(const char *nb);
double			get_double_next(const char *nb,
					int i,
					int size,
					int sign);
int			load_lights(t_bunny_ini *ini, t_rtracer *data);
int			add_one_light(t_figure *data,
				      t_bunny_ini *ini,
				      int light,
				      int rounds);
int			load_plans(t_bunny_ini *ini, t_rtracer *data);
void			main_default(t_rtracer *data);
int			load_file(t_rtracer *data, char *file);
int			load_file_next(t_rtracer *data, t_bunny_ini *ini);
int			load_eyes(t_bunny_ini *ini, t_rtracer *data);
void			load_eyes_next(t_rtracer *data, t_bunny_ini *ini);

#endif /* !RAYTRACER1_H_ */
