/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gburtin <gburtin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 17:27:13 by gburtin           #+#    #+#             */
/*   Updated: 2025/09/05 11:05:33 by gburtin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../libft/includes/libft.h"
# include "mlx.h"
# include "mlx_int.h"
# include <errno.h>
# include <fcntl.h>
# include <math.h>
# include <stdbool.h>
# include <stdio.h>
# include <string.h>
# include <sys/stat.h>
# include <sys/time.h>
# include <sys/types.h>
# include <unistd.h>

# define WIN_WIDTH 1333
# define WIN_HEIGHT 1000

# define WALL '1'
# define FLOOR '0'

# define WALL_TEX_WIDTH 100
# define WALL_TEX_HEIGHT 100

# define VERT_HIT 0
# define HORI_HIT 1

# define COLOR_RED 0xFF0000
# define COLOR_GREEN 0x00FF00
# define COLOR_BLUE 0x0000FF
# define COLOR_WHITE 0xFFFFFF
# define COLOR_BLACK 0x000000
# define COLOR_YELLOW 0xFFFF00
# define COLOR_GREY 0x808080

# define FOV 60

# define WALK_SPEED 0.04f
# define TURN_SPEED 0.04f
# define MARGIN 0.1f

extern int				g_frame_count;

typedef struct s_coord_int
{
	int					x;
	int					y;
}						t_coord_int;

typedef struct s_coord_float
{
	float				x;
	float				y;
}						t_coord_float;

typedef struct s_key
{
	int					key_a;
	int					key_d;
	int					key_w;
	int					key_s;
	int					key_left;
	int					key_right;
}						t_key;

typedef struct s_garbage
{
	void				*alloc;
	struct s_garbage	*next;
}						t_garbage;

typedef struct s_image
{
	t_img				*image;
	int					width;
	int					height;
	int					bpp;
	int					size_line;
	int					endian;
	char				*data;
}						t_image;

typedef struct s_sprite
{
	t_image				north;
	t_image				south;
	t_image				west;
	t_image				east;
}						t_sprite;

typedef struct s_texture
{
	char				*north_texture;
	char				*south_texture;
	char				*west_texture;
	char				*east_texture;
	int					floor_color;
	int					ceiling_color;
}						t_texture;

typedef struct s_file
{
	char				*str;
	char				**tab;
	int					player_start[2];
	char				*map_name;
}						t_file;

typedef struct s_player
{
	t_coord_float		pos;
	t_coord_float		dir;
	t_coord_float		plane;
	float				angle;
}						t_player;

typedef struct s_mlx
{
	void				*ptr;
	void				*win;
	int					width;
	int					height;
}						t_mlx;

typedef struct s_ray
{
	t_coord_float		ray_dir;
	float				camera_x;
	t_coord_float		delta_dist;
	t_coord_float		step;
	t_coord_int			map;
	t_coord_float		side_dist;
	int					side;
	float				perp_wall_dist;
	t_coord_float		wall_hit;
	int					line_height;
	int					draw_start;
	int					draw_end;
	float				wall_x;
	int					tex_num;
	int					tex_x;
	float				tex_pos;
	float				tex_step;
	int					tex_y;
	unsigned int		**texture;
}						t_ray;

typedef struct s_data
{
	char				**map;
	t_file				file;
	t_mlx				mlx;
	t_player			player;
	t_garbage			*gc_list;
	t_sprite			sprite;
	t_image				frame;
	t_texture			texture;
	t_key				keys;
	t_ray				ray;
}						t_data;

// garbage collector
void					gc_free(t_garbage **gc_list);
void					*gc_add_malloc(void *ptr, t_garbage **gc_list);
char					**gc_add_tab(char **tab, t_garbage **gc_list);
void					*gc_malloc(size_t size, t_garbage **gc_list);

// img
void					destroy_img(t_data *data);
void					init_img(t_data *data);
int						pix_index(t_image *img, int x, int y);
void					img_pix_put(t_image *img, int x, int y, int color);
int						get_texture_color(t_image *img, int x, int y, int type);

// init
void					init(t_data *data);

// mov
int						handle_keypress(int keysym, t_data *data);
void					player_move(t_data *data);
int						handle_keyrelease(int keysym, t_data *data);

// parsing
bool					check_texture(char **tab, char *id);
bool					check_colors(char **tab, char *id);
bool					is_valid_map_char(char c);
bool					check_data(t_data *data);
bool					check_map_nl(char *str);
bool					check_map(t_data *data);
bool					get_data(t_data *data);
bool					get_map(t_data *data);
bool					check_filename(char *filename, char *ext);
void					parsing(int argc, char **argv, t_data *data);
bool					read_file(char *filename, t_data *data);

// raycasting
void					draw_texture(t_data *data, int x);
void					raycast(t_data *data);
void					init_ray(t_data *data, int x);

// render
int						render_frame(t_data *data);

// utils
int						exit_success(t_data *data);
int						exit_failure(t_data *data, char *str);
void					free_all(t_data *data);
void					print_data_map(t_data data);
// useless ?
int						rgb_to_int(u_int8_t r, u_int8_t g, u_int8_t b);
int						*int_to_rgb(int color);

#endif