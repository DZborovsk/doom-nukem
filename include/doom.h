/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doom.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzborovk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/02 16:39:30 by dzborovk          #+#    #+#             */
/*   Updated: 2019/03/02 17:01:47 by dzborovk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOOM_H
# define DOOM_H

# include "../libft/libft.h"

# include "SDL_mixer.h"
# include "SDL_image.h"
# include "SDL_ttf.h"

# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <time.h>
# include <math.h>
# include <string.h>
# include <errno.h>

# define BUFF_SIZE 2000

# define WIDTH 1200
# define HEIGHT 800

typedef struct	s_lin2
{
	float		y;
	float		x;
	int			m_in_i;
	int			m_in_j;
}				t_lin2;

typedef struct	s_lin3
{
	float		x;
	float		z;
	float		y;
}				t_lin3;

typedef struct	s_post
{
	int			y;
	int			x;
}				t_post;

typedef struct	s_post3
{
	int			x;
	int			y;
	int			z;
}				t_post3;

typedef struct	s_dest
{
	int			sectorno;
	int			sx1;
	int			sx2;
}				t_dest;

typedef struct	s_symvl
{
	int			size;
	t_post		pos;
	SDL_Color	color;
}				t_symvl;

typedef struct	s_spte
{
	t_lin2		position;
	int			id_sp_d;
	int			wi_sp_d;
	int			hi_sp_d;
	float		w_sp_d;
	float		f_sp_d;
	float		c_sp_d;
}				t_spte;

typedef struct	s_room
{
	signed char	*n_bor;
	unsigned	num_p;
	int			end;
	int			light;
	int			door;
	int			lift;
	int			num_t;
	float		fl_go;
	float		ce_go;
	float		floor;
	float		ceil;
	t_lin2		*d_top;
	t_spte		*sp_thi;
}				t_room;

typedef struct	s_nuk
{
	int			m_wi;
	int			p_dor;
	int			p_lif;
	int			gr_d;
	int			f_ng;
	int			m_ng;
	int			n_duc;
	int			n_pus;
	int			n_fly;
	int			x_m;
	int			y_m;
	float		n_spd;
	float		yaw;
	float		n_eyht;
	float		num_v[2];
	float		dx;
	float		dy;
}				t_nuk;

typedef struct	s_invspr
{
	int			hp;
	int			armor;
	int			ammo;
	int			i_we_tp;
	int			i_we_mh;
	int			dr_key;
	int			shine;
	int			gr_key;
	int			jackpack;
	int			gravity;
	float		wea_ph;
}				t_invspr;

typedef struct	s_user_dt
{
	float		us_ang;
	float		sin_an;
	float		cos_an;
	float		yaw;
	t_lin3		where;
	t_lin3		us_sp;
	Uint32		us_sec;
	t_invspr	invspr;
}				t_user_dt;

typedef struct	s_nuk_dr
{
	int			x1;
	int			x2;
	int			dr_nei;
	int			a1_y;
	int			b1_y;
	int			y2_a;
	int			b2_y;
	int			an_1;
	int			bn_1;
	int			an_2;
	int			bn_2;
	int			dr_bg;
	int			en_dr;
	int			x;
	int			z;
	int			y_a;
	int			cy_a;
	int			y_b;
	int			cy_b;
	int			cl_fl;
	int			u;
	int			v;
	int			edg1;
	int			edg2;
	int			loc_beg;
	int			loc_end;
	int			a_ny;
	int			a_nyc;
	int			b_ny;
	int			b_nyc;
	size_t		r1;
	size_t		r2;
	size_t		r;
	float		ce_y;
	float		flo_y;
	float		cel_ny;
	float		flo_ny;
	float		v1x;
	float		v2x;
	float		v3x;
	float		v1y;
	float		v2y;
	float		v3y;
	float		c_p;
	float		s_p;
	float		t_1;
	float		t_2;
	float		z_1;
	float		z_2;
	float		z_nea;
	float		s_nea;
	float		z_f;
	float		sd_fa;
	float		scl_x1;
	float		scl_y1;
	float		scl_x2;
	float		scl_y2;
	float		len_f;
	float		len;
	float		st_vx;
	float		en_vx;
	float		st_vy;
	float		en_vy;
	t_lin2		i1;
	t_lin2		i2;
	t_dest		now;
	t_room		*sect;
}				t_nuk_dr;

typedef struct	s_mat_spr
{
	int			n_spr;
	int			y1;
	int			y2;
	float		d_len;
}				t_mat_spr;

typedef struct	s_ini_dr
{
	size_t		n;
	size_t		s;
	int			x;
	int			qu;
	int			i_wa;
	int			i_win;
}				t_ini_dr;

typedef struct	s_draw_data
{
	size_t		sec_num;
	int			t_y[WIDTH];
	int			botm_y[WIDTH];
	int			dr_img[HEIGHT][WIDTH];
	int			**buf_im;
	int			**txs;
	int			**dr_he;
	int			**px_sky;
	int			***dr_car;
	int			***item;
	int			***blast;
	int			***shun;
	t_dest		dr_ue[32];
	t_dest		*d_he;
	t_dest		*d_til;
	t_ini_dr	tini;
	t_nuk_dr	mat;
	t_mat_spr	dr_sp;
}				t_dat_dr;

typedef struct	s_sour_fn
{
	SDL_Surface	*su_fo;
	SDL_Texture	*tx_fo;
	TTF_Font	*ttf_ft;
	SDL_Rect	rec_ft;
}				t_sour_fn;

typedef struct	s_duk_m
{
	SDL_Surface	*menu;
	int			m_n;
	int			flag;
	char		*str[3];
	SDL_Color	col_m;
}				t_duk_m;

typedef struct	s_sour
{
	char		*name;
	int			fd;
	int			ver_num;
	int			sec_sou;
	int			pl_sou;
	int			kyl_sou;
	int			amm_sou;
	int			do_sou;
	int			lft_sou;
	int			en_sou;
	int			nem_sou;
	int			xt_sou;
	int			size_vert;
	int			sou_i;
}				t_sour;

typedef struct	s_my_doom
{
	int			run_gn;
	int			md_d;
	int			time;
	int			flag;
	int			obj;
	int			monst_death;
	double		a;
	double		b;
	double		c;
	int			r;
	int			dis_sqrt;
	const Uint8	*st_key;
	SDL_Window	*window;
	SDL_Renderer*duk_ren;
	SDL_Texture	*duk_txr;
	t_nuk		duk_gm;
	t_dat_dr	duk_draw;
	t_user_dt	dk_user;
	t_room		*duk_sec;
	t_sour_fn	fonts;
	t_duk_m		menu;
	Mix_Music	*mus;
	Mix_Chunk	*guns[2];
	Mix_Music	*mus2;
	char		*fps_show;
	int			flag_1;
	size_t		m_dk_i;
	float		f;
}				t_my_doom;

typedef struct	s_duk_br
{
	int			a;
	int			b;
	int			a_sn;
	int			b_sn;
	int			f;
	int			x;
	int			y;
	int			en_dr;
	int			y_end;
}				t_duk_br;

void			draw_menu_doom(t_my_doom *dat);
void			unload_data(t_my_doom *dat);
void			sdl_start_protocols(t_my_doom *dat);
void			doom_quit(int flag, t_my_doom *dat);
int				load_png_doom(t_my_doom *dat, int tex_arr_num, char *path);
void			doom_init(t_my_doom *dat);
float			ft_map(float num, float sr_start, t_lin3 funk);
t_lin3			ft_map_help(float sr_end, float dst_start, float dst_end);
void			mission_msg(t_my_doom *dat);
void			go_doom_game(t_my_doom *dat);
void			texture_checks(t_my_doom *dat);
void			doom_parser(t_sour *data, t_my_doom *dat);
void			error_msg(char *str);
char			*join_free(char *s1, char *s2, int j);
int				arr_len(char **str);
void			init_item_count(t_sour *data);
void			count_all_item(t_sour *data, char **reading);
void			check_sec_ver(t_sour *data, char **str);
int				is_num(char *str);
int				arr_len(char **str);
int				error_check(t_sour *data, char **str);
void			pars_data_main(t_my_doom *dat, t_sour *data,
				char **reading);
void			save_coords(t_my_doom *dat, t_sour *data,
				char **reading);
int				*ft_intsplit(char const *s, char c);
void			ft_free_int(int **del);
void			doom_parse_search_item(t_my_doom *dat, char **reading,
				int y, int *sec_sprites);
void			doom_parse_search_enemy(t_my_doom *dat, char **reading,
				int y, int *sec_sprites);
void			doom_parse_search_key(t_my_doom *dat, char **reading,
				int y, int *sec_sprites);
void			menu_doom(t_my_doom *dat, t_sour *data);
int				bumps(t_my_doom *my, float d_x, float d_y, size_t n);
SDL_Surface		*load_image(char *path);
int				go_doom(t_my_doom *dat, t_sour *data);
Mix_Music		*download_music(char *path);
int				load_sounds_doom(t_my_doom *dat);
void			draw_hud_2(t_my_doom *d, SDL_Color color);
void			load_texture_doom(t_my_doom *dat);
void			doom_init_backup(t_my_doom *dat);
SDL_Surface		*doom_png_pic(char *path);
int				init_fonts(t_my_doom *main, char *font_path, int font_size);
t_symvl			set_pixel_txt(int x, int y, SDL_Color color, int font_size);
void			ft_text_write(t_my_doom *main, char *text,
				t_symvl txt, char *font_path);
void			doom_ingame_meh(t_my_doom *dat);
void			doom_render_meh(t_my_doom *dat);
void			draw_screen(t_my_doom *dat);
int				p_inside_doom(t_lin2 *ver, size_t numb,
				t_lin2 point, int flag_1);
void			help_drav_imp(t_my_doom *main);
void			draw_walls_pic_2(t_my_doom *d);
void			tex_sprt(t_my_doom *my);
int				p_inside_doom(t_lin2 *ver, size_t numb,
				t_lin2 point, int flag_1);
void			draw_scr_init(t_my_doom *dat, int *renderedsectors);
t_post3			set_point(int a, int b, int c);
void			vline(t_my_doom *dat, t_post3 borders, t_post3 colors);
void			vline_tex(t_my_doom *dat, t_post3 borders, int tex_num);
void			player_calc_view(t_my_doom *dat);
void			wall_intersec(t_my_doom *dat);
int				change_line(char **fdfile, char **line);
void			perspect_trans(t_my_doom *dat);
void			fl_ceil_view(t_my_doom *dat);
void			proj_height(t_my_doom *dat);
void			draw_ceil_floor(t_my_doom *dat);
void			draw_walls_pic(t_my_doom *dat);
void			s_neighbor(t_my_doom *dat);
void			texture_full_wall(t_my_doom *dat);
float			yaw(t_my_doom *dat, float y, float z);
void			tex_on_floor(t_my_doom *dat);
void			tex_on_ceil(t_my_doom *dat);
void			tex_on_wall(t_my_doom *dat);
void			draw_textures_wall(t_my_doom *dat);
void			draw_pre_frame(t_my_doom *dat);
void			cur_frame(t_my_doom *dat);
int				load_sky_pxl(t_my_doom *dat, char *path);
void			draw_sky_box(t_my_doom *dat);
int				pixel_bright(int pixel_color, float change);
void			draw_vectors(t_my_doom *main);
void			draw_line_doom(t_my_doom *main, t_post start,
				t_post end, int color);
void			draw_hud(t_my_doom *dat);
void			draw_inventory_pics(t_my_doom *dat);
void			draw_inventory(t_my_doom *dat, SDL_Color color, int y);
void			draw_lift_stuff(t_my_doom *dat);
int				load_helmet_view(t_my_doom *dat);
void			draw_helmet_pix(t_my_doom *dat);
int				ft_check_img(t_my_doom *main);
void			ft_help_math(t_duk_br calcul, t_my_doom *main,
				int color);
void			load_weapons(t_my_doom *dat);
void			draw_weapons(t_my_doom *dat);
void			help_check_lift(t_my_doom *main, unsigned int i, float speed);
void			dw_blaster(t_my_doom *dat, int sprite);
void			draw_pistol_an(t_my_doom *dat);
void			dw_shotgun(t_my_doom *dat, int sprite);
void			draw_shotgun(t_my_doom *dat);
void			draw_pistol(t_my_doom *dat, int x_pos,
				int y_pos, int sprite);
void			dw_item(t_my_doom *dat, int item_num, char *path);
void			dw_cards(t_my_doom *dat, int card_num, char *path);
int				load_items(t_my_doom *dat);
void			set_pxl_col(t_my_doom *main, int texture, int x, int y);
int				sprite_loading(t_my_doom *dat);
void			check_sprites(t_my_doom *dat);
void			draw_spritekit(t_my_doom *dat);
void			v_line_card(t_my_doom *dat, int x, int tex_num);
void			vline_item(t_my_doom *dat, int x, int tex_num);
void			find_end_sprt(t_my_doom *dat, float dist);
void			find_visual_sprt(t_my_doom *dat, float dist);
void			form_of_transformn(t_my_doom *dat);
int				calc_sprt_inter(t_my_doom *dat);
int				calc_view_sprt(t_my_doom *dat);
void			draw_sprt_key(t_my_doom *dat, int key);
void			draw_item_sprite(t_my_doom *dat, int some);
void			draw_imp_stuff(t_my_doom *dat);
void			doom_move_player(t_my_doom *dat, float dx, float dy);
void			doom_main_keys(t_my_doom *dat);
void			mouse_2(t_my_doom *dat, SDL_Event event, t_sour *data);
void			doom_physic(t_my_doom *dat);
void			vert_col_doom(t_my_doom *dat);
void			hor_col_doom(t_my_doom *dat, float dx,
				float dy, size_t s);
void			fly_mode_doom(t_my_doom *dat);
int				change_vec_doom(t_lin2 p, t_lin2 q, t_lin2 r);
int				vis_orient_doom(t_lin2 p, t_lin2 q, t_lin2 r);
int				main_math(t_lin2 p1, t_lin2 q1, t_lin2 p2, t_lin2 q2);
int				p_inside_doom(t_lin2 *d_top, size_t num_p,
				t_lin2 point, int flag);
int				p_doom_map(t_my_doom *dat);
int				calc_dmg_doom(t_my_doom *dat);
void			doom_died_msg(t_my_doom *dat);
void			interact_door(t_my_doom *dat);
void			check_door(t_my_doom *dat);
void			motion_lift(t_my_doom *dat);
void			doom_lift_check(t_my_doom *dat, unsigned int i);
void			main_keys_doom(t_my_doom *main);
void			mouse_main(t_my_doom *main, SDL_Event event);
void			init_start_doom(t_my_doom *main);
void			sdl_quit_doom(t_my_doom *main, int e);
void			my_error(char *c);
float			clamp_float(float a, float mi, float ma);
float			f_min(float x, float y);
float			f_max(float x, float y);
float			vxs_float(float x0, float y0, float x1, float y1);
t_lin2			doom_inter_sect(t_lin3 cr1, t_lin3 cr2, float x4, float y4);
float			point_side_fl(t_lin3 cr1, float y0, float x1, float y1);
void			render_mechanics(t_my_doom *dat);
void			pos_enemy(t_my_doom *dat);
void			ft_fps(t_my_doom *doom_fps);
int				get_next_line_specific(const int fd, char **line);
void			import_object(t_my_doom *dat);
void			draw_aim(t_my_doom *dat);
void			find_lift(t_my_doom *dat, char **reading, int y);
void			fly_phys_doom(t_my_doom *my, float nex);
void			vert_col_doom(t_my_doom *my);
void			mouse_selector(t_my_doom *my, SDL_Event event, t_sour *data);
int				doom_ev_help(t_my_doom *my, t_sour *data, SDL_Event event);
void			help_sc_cal(t_my_doom *my);
int				load_helmet_view(t_my_doom *dat);
void			load_helmet_view_data(t_my_doom *dat, SDL_Surface *pic_surface);

#endif
