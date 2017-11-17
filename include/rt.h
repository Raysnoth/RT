/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-cren <ele-cren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/24 11:00:36 by ele-cren          #+#    #+#             */
/*   Updated: 2017/08/23 20:25:04 by ele-cren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_H
# define RT_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <libft.h>
# include <math.h>
# include <get_next_line.h>
# include <SDL_thread.h>
# include <SDL.h>
# include <SDL_ttf.h>
# include <sys/dir.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <time.h>
# define WIDTHR 640
# define HEIGHT 480
# define WIDTHS 300
# define VIEWPLANED 1.0
# define VIEWPLANEW 0.64
# define VIEWPLANEH 0.48
# define F 1.0
# define XINDENT VIEWPLANEW / (double)WIDTHR
# define YINDENT VIEWPLANEH / (double)HEIGHT
# define MAX(X, Y) (((X) > (Y)) ? (X) : (Y))

enum {SPHERE = 1, PLANE = 2, CYL = 3, CONE = 4, PARA = 5, ELL = 6};
enum {OBJ = 1, LIGHT = 2, CAM = 3};
enum {BASIC = 1, SPOT = 2};
enum {TILE = 1, PERL = 2, MAP = 3};
enum {TIMG, TINTER, TTEXT};
enum {SIMG, STEXT};
enum {DTEXT, DINTER};
enum {MIN, MAX};
enum {CHECKER = 1, MOON = 2, SUN = 3, EARTH = 4, GARDEN = 5};
enum {INTERFACE, OBJECTS, ATTRIBUTES, POSTAB, DIRTAB, COLTAB, BASETAB, EFFTAB};

typedef struct		s_vect
{
	double			x;
	double			y;
	double			z;
	double			h;
}					t_vect;

typedef struct		s_calc
{
	int				color;
	double			a;
	double			b;
	double			c;
	double			solution;
	double			delta;
	t_vect			delta_p;
}					t_calc;

typedef struct		s_color
{
	int				red;
	int				green;
	int				blue;
	int				w;
}					t_color;

typedef struct		s_cam
{
	t_vect			pos;
	int				inc;
	t_vect			dir;
	t_vect			angles;
	t_vect			pixel;
	t_vect			view_plane;
	t_vect			up;
	t_vect			right;
}					t_cam;

typedef struct		s_obj
{
	struct s_obj	*next;
	struct s_obj	*prev;
	int				type;
	int				radius;
	t_vect			pos;
	t_vect			angles;
	t_color			color;
	int				angle;
	t_vect			dir;
	int				tex;
	int				refle;
	int				refra;
	int				refra_trans;
	int				fin[2];
	int				finished;
}					t_obj;

typedef struct		s_set
{
	int				p[2];
	int				tab;
	t_obj			*obj[4];
	int				pos;
	int				nb[3];
	int				inc;
	int				at;
	int				block;
	int				select;
	int				id_o;
	int				del;
	SDL_Color		color[2];
}					t_set;

typedef struct		s_light
{
	struct s_light	*next;
	struct s_light	*prev;
	int				type;
	t_vect			pos;
	t_vect			solution_point;
	t_vect			normal_vect;
	t_vect			light_vect;
	double			norme;
	double			power;
	t_vect			dir;
	t_color			color;
}					t_light;

typedef struct		s_tmp
{
	t_vect			pos;
	t_vect			angles;
	t_vect			ray_pos;
	t_vect			ray_dir;
	int				radius;
	int				type;
	int				id_o;
	t_color			color;
	int				angle;
	double			solution;
	t_obj			*current;
	int				i;
	double			darkness;
	double			power;
	int				tex;
	int				refle;
	int				refra;
	int				refra_trans;
	int				fin[2];
	int				finished;
	int				nb_refle;
	t_vect			solution_point;
	t_light			*light;
	t_color			tab_color[5];
}					t_tmp;

typedef struct		s_check
{
	int				position;
	int				direction;
	int				color;
	int				radius;
	int				angle;
}					t_check;

typedef struct		s_parse
{
	int				fd;
	char			*file;
	int				nb_line;
	int				com;
	int				tablen;
	char			*line;
	char			**split;
	int				type;
	int				type_obj;
	int				type_light;
	int				objects;
	int				cam;
	int				lights;
}					t_parse;

typedef struct		s_input
{
	char			buttons[8];
	int				mouse_x;
	int				mouse_y;
	int				mouse_rel_x;
	int				mouse_rel_y;
	int				press;
}					t_input;

typedef struct		s_sdl
{
	SDL_Window		*win;
	SDL_Renderer	*rend;
	TTF_Font		*font[3];
	SDL_PixelFormat	*format;
	SDL_Texture		*draw;
	SDL_Texture		*tset[3];
	SDL_Surface		*text;
	SDL_Surface		*surf[5];
	void			*tmp;
	int				pitch;
	Uint32			*pixels;
	int				keep;
	SDL_Event		event;
	SDL_Rect		pos;
	SDL_Rect		rt;
	SDL_Rect		rset[2];
	t_input			in;
}					t_sdl;

typedef struct		s_shadow
{
	int				i;
	t_vect			test;
	t_vect			solution;
}					t_shadow;

typedef struct		s_thread
{
	SDL_Thread		*t[4];
	int				id;
	int				y_start;
	int				y_end;
	int				x_start;
	int				x_end;
	int				finished;
}					t_thread;

typedef struct		s_filters
{
	int				bw[3];
	int				mo[3];
	int				neg;
}					t_filters;

typedef struct		s_env
{
	t_parse			parse;
	t_sdl			sdl;
	t_shadow		shadow;
	t_obj			*obj;
	t_obj			*tmp_obj;
	t_light			*light;
	t_light			*tmp_light;
	t_cam			cam;
	t_check			check;
	t_tmp			tmp;
	t_calc			calc;
	t_thread		thread;
	t_set			set;
	t_filters		filters;
	int				amb;
	double			amb_coef;
}					t_env;

void				ft_parse(t_env *env, char *av);
void				ft_fill_cam(t_env *env);
t_light				*ft_fill_light(t_env *env);
void				ft_error(void);
void				ft_error_file(void);
void				ft_error_sdl(void);
void				ft_init_env(t_env *env);
void				ft_check_objects(t_env *env);
void				ft_check_obj_types(t_env *env);
void				ft_parse_objects(t_env *env);
void				ft_init_tmp(t_env *env);
void				ft_init_check(t_env *env);
t_obj				*ft_fill_obj(t_env *env);
t_light				*ft_fill_light(t_env *env);
void				ft_end_obj(t_env *env);
void				ft_check_lights(t_env *env);
void				ft_parse_lights(t_env *env);
void				ft_end_lights(t_env *env);
void				ft_init_sdl(t_env *env);
double				ft_scalar(t_vect vec1, t_vect vec2);
t_vect				ft_vect_op(t_vect vec1, char c, t_vect vec2);
t_vect				ft_vect_op2(double tmp, char c, t_vect vec);
void				ft_thread(t_env *env);
void				ft_browse_list(t_env *env, t_vect ray_dir, t_vect ray_pos, \
		int i);
void				ft_init_start(t_env *env);
void				ft_display(t_env *env);
void				ft_init_pixel(t_env *env);
void				ft_light(t_env *env);
void				ft_normal_vect(t_env *env);
void				ft_normal_sphere(t_env *env);
void				ft_calc_plane(t_env *env, t_vect ray_dir, t_vect ray_pos);
void				ft_calc_sphere(t_env *env, t_vect ray_dir, t_vect ray_pos);
void				ft_calc_cone(t_env *env, t_vect ray_dir, t_vect ray_pos);
void				ft_calc_cyl(t_env *env, t_vect ray_dir, t_vect ray_pos);
t_vect				ft_vect_rot(t_vect d, double angle, int axe);
void				ft_browse_pixels(t_env *env);
void				ft_calc_angles(t_env *env);
void				ft_shadow(t_env *env);
void				ft_check_light_types(t_env *env);
void				ft_check_error_obj(t_env *env);
void				ft_parse_tiles(t_env *env, int i);
t_color				ft_chose_color(t_env *env);
t_vect				ft_calc_sol(t_env *env);
SDL_Texture			*ft_img_to_tex(t_env *env, char *path);
void				ft_init_set(t_env *env);
void				ft_settings(t_env *env);
void				ft_interface(t_env *env);
void				ft_event(t_env *env);
void				ft_check_obj_types2(t_env *env);
void				ft_s_objects(t_env *env);
void				ft_ev_inter(t_env *env);
void				ft_ev_obj(t_env *env);
void				ft_attributes(t_env *env);
void				ft_ev_at(t_env *env);
void				ft_add_elem_obj(t_env *env);
void				ft_delete_elem_obj(t_env *env);
void				ft_init_draw(t_env *env);
void				ft_stock_elem(t_env *env);
void				ft_undelete(t_env *env);
void				ft_pos_tab(t_env *env);
void				ft_ev_pos(t_env *env);
void				ft_ev_dir(t_env *env);
void				ft_dir_tab(t_env *env);
void				ft_ev_col(t_env *env);
void				ft_col_tab(t_env *env);
void				ft_ev_col_rl(t_env *env);
void				ft_ev_col_dub(t_env *env);
void				ft_ev_col_return1(t_env *env);
void				ft_ev_pos_rl(t_env *env);
void				ft_ev_pos_dub(t_env *env);
void				ft_ev_pos_return1(t_env *env);
void				ft_ev_dir_rl(t_env *env);
void				ft_ev_dir_dub(t_env *env);
void				ft_ev_dir_return1(t_env *env);
void				ft_ev_obj_duret(t_env *env);
void				ft_ev_obj_rb(t_env *env);
void				ft_ev_obj_l(t_env *env);
void				ft_ev_obj_u(t_env *env);
void				ft_ev_at_dubrl(t_env *env);
void				ft_ev_at_return1(t_env *env);
void				ft_base_tab(t_env *env);
void				ft_ev_base(t_env *env);
void				ft_ev_base_rlb(t_env *env);
void				ft_ev_base_down(t_env *env);
void				ft_ev_base_up(t_env *env);
void				ft_ev_base_return1(t_env *env);
void				ft_ev_base_return3(t_env *env);
void				ft_eff_tab(t_env *env);
void				ft_ev_eff(t_env *env);
void				ft_ev_eff_rlb(t_env *env);
void				ft_ev_eff_du(t_env *env);
void				ft_ev_eff_return1(t_env *env);
void				ft_ev_tex(t_env *env);
void				ft_tex_tab(t_env *env);
void				ft_tex_text(t_env *env);
void				ft_tex_text2(t_env *env, int i, char **name);
void				ft_copy_tex_text(t_env *env, int i);
void				ft_ev_tex(t_env *env);
void				ft_ev_tex_rlb(t_env *env);
void				ft_ev_tex_du(t_env *env);
t_env				*dup_struct(t_env *src, int id);
t_vect				ft_normalize(t_vect vect);
t_env				*dup_struct(t_env *src, int id);
t_obj				*dup_obj(t_obj *src, t_env *env);
t_light				*dup_light(t_light *src);
t_tmp				dup_tmp(t_tmp src);
t_vect				dup_vect(t_vect src);
t_color				dup_color(t_color src);
void				thread_suppr_dup(t_env *env);
void				ft_event_cam(t_env *env);
void				ft_free(t_env *env);
void				ft_free_obj(t_obj *obj);
void				ft_free_light(t_light *light);
void				ft_parse_refraction(t_env *env, int i);
void				ft_update_mouse(t_env *env);
void				ft_cam_mouse(t_env *env);
char				*ft_create_date(void);
void				ft_replace(t_vect *solution, t_vect pos_obj, t_vect angles);
void				ft_direct(t_vect *solution, t_vect angles);
void				ft_redirect(t_vect *solution, t_vect angles);
void				ft_light_vect(t_env *env, int mode);
void				ft_place(t_env *env);
void				ft_loop(t_env *env);
void				ft_calc_ru(t_env *env);
t_vect				ft_inv_vect(t_vect vect);
void				ft_filters(t_env *env);
void				ft_refresh(t_env *env);
void				ft_reflexion(t_env *env);
void				ft_refraction(t_env *env);
t_color				ft_texture(t_env *env);
void				ft_option_visu(t_env *env);
t_color				ft_option_col(t_env *env, t_color color);
void				ft_event_save(t_env *env);
t_filters			dup_filters(t_filters filt);
void				ft_event_save_obj(FILE *file, char *type, t_obj *tmp);
void				ft_event_save_add(char *str, FILE *file);
void				ft_event_save_vect(t_vect vect, FILE *file);
void				ft_error_check_file(t_env *env);
int					ft_check_com(t_env *env);
int					*ft_create_tab_verif(void);
void				ft_verif_tab(t_env *env, int *tab, int action);
void				ft_parse_position(t_env *env, int i);
void				ft_parse_angles(t_env *env, int i, int *tab);
void				ft_parse_finished(t_env *env, int i);
void				ft_parse_tex(t_env *env, char *str, int *tab);
void				ft_parse_color(t_env *env, int i, int *tab);
int					ft_verif_num(char *str, t_env *env);
int					ft_check_types(t_env *env);
void				ft_parse_attribute(t_env *env, int i);
char				*ft_strtolower(char *str);
void				ft_parse_index(t_env *env, int i, int *tab);
Uint32				obtenir_pixel(SDL_Surface *surface, int x, int y);

#endif
