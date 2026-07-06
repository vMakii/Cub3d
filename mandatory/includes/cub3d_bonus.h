/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivogel <mivogel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 17:27:13 by gburtin           #+#    #+#             */
/*   Updated: 2025/09/05 14:37:30 by mivogel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_BONUS_H
# define CUB3D_BONUS_H

// ============================================================================
// INCLUDES
// ============================================================================

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
# include <time.h>
# include <unistd.h>

// ============================================================================
// CONSTANTS AND DEFINES
// ============================================================================

// Constants
# define WIN_WIDTH 1333
# define WIN_HEIGHT 1000

# define NB_SPRITES_C 2
# define NB_SPRITES_F 18

# define RANDOM_C 'C'
# define RANDOM_F 'F'

# define TREASURE 'T'
# define LAMP 'L'

# define ENEMY 'M'

# define WALL '1'
# define FLOOR '0'
# define DOOR 'D'

# define WALL_TEX_WIDTH 128
# define WALL_TEX_HEIGHT 128

# define FLOOR_TEX_WIDTH 128
# define FLOOR_TEX_HEIGHT 128

# define CEILING_TEX_WIDTH 64
# define CEILING_TEX_HEIGHT 64

# define DOOR_TEX_WIDTH 128
# define DOOR_TEX_HEIGHT 128

# define VERT_HIT 0
# define HORI_HIT 1

# define MINIMAP_SCALE 12
# define MINIMAP_OFFSET 5

# define HUDSCALING 4
# define UPSCALING 5
# define BIGSCALING 10

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
# define RUN_SPEED 0.08f
# define MARGIN 0.1f

# define INTERACTION_DISTANCE 1.0f

extern int							g_frame_count;

// ============================================================================
// BASIC TYPES AND COORDINATES
// ============================================================================

typedef struct s_coord_int
{
	int								x;
	int								y;
}									t_coord_int;

typedef struct s_coord_float
{
	float							x;
	float							y;
}									t_coord_float;

typedef struct s_mlx
{
	void							*ptr;
	void							*win;
	int								width;
	int								height;
}									t_mlx;

// ============================================================================
// FORWARD DECLARATIONS
// ============================================================================

typedef struct s_data				t_data;
typedef struct s_door				t_door;
typedef struct s_door_list			t_door_list;
typedef struct s_sprite				t_sprite;
typedef struct s_ray				t_ray;
typedef struct s_player				t_player;
typedef struct s_texture			t_texture;
typedef struct s_image				t_image;
typedef struct s_key				t_key;
typedef struct s_minimap			t_minimap;
typedef struct s_time				t_time;
typedef struct s_file				t_file;
typedef struct s_garbage			t_garbage;
typedef struct s_rect				t_rect;
typedef struct s_starting_screen	t_starting_screen;
typedef struct s_enemy				t_enemy;

// ============================================================================
// PARSING STRUCTURES
// ============================================================================

typedef struct s_file
{
	char							*str;
	char							**tab;
	int								player_start[2];
	char							*map_name;
	char							*north_texture;
	char							*south_texture;
	char							*west_texture;
	char							*east_texture;
	int								floor_color;
	int								ceiling_color;
}									t_file;

// ============================================================================
// IMAGE AND TEXTURE STRUCTURES
// ============================================================================

typedef struct s_image
{
	t_img							*image;
	int								width;
	int								height;
	int								bpp;
	int								size_line;
	int								endian;
	char							*data;
}									t_image;

typedef struct s_texture
{
	t_image							starting_screen_0;
	t_image							starting_screen_1;
	t_image							hit;
	t_image							north;
	t_image							south;
	t_image							west;
	t_image							east;
	t_image							up_north;
	t_image							up_south;
	t_image							up_west;
	t_image							up_east;
	t_image							player_left1;
	t_image							player_left2;
	t_image							player_cast_0_l;
	t_image							player_cast_0_r;
	t_image							player_cast_1_l;
	t_image							player_cast_1_r;
	t_image							player_cast_2_l;
	t_image							player_cast_2_r;
	t_image							player_cast_3_l;
	t_image							player_cast_3_r;
	t_image							player_cast_4_l;
	t_image							player_cast_4_r;
	t_image							player_cast_5_l;
	t_image							player_cast_5_r;
	t_image							player_right1;
	t_image							player_right2;
	t_image							player_attack_0;
	t_image							player_attack_1;
	t_image							player_attack_2;
	t_image							player_attack_3;
	t_image							player_attack_4;
	t_image							player_magick_0;
	t_image							player_magick_1;
	t_image							player_magick_2;
	t_image							player_magick_3;
	t_image							player_magick_4;
	t_image							player_magick_5;
	t_image							player_magick_6;
	t_image							player_magick_7;
	t_image							player_magick_8;
	t_image							player_magick_9;
	t_image							impact_0;
	t_image							impact_1;
	t_image							impact_2;
	t_image							impact_3;
	t_image							impact_4;
	t_image							blood_0;
	t_image							blood_1;
	t_image							blood_2;
	t_image							blood_3;
	t_image							blood_4;
	t_image							minimap;
	t_image							map_frame;
	t_image							map_wall;
	t_image							map_floor;
	t_image							sky_texture;
	t_image							floor;
	t_image							ceiling;
	t_image							door_closed;
	t_image							door_half_open;
	t_image							door_open;
	t_image							up_door_closed;
	t_image							up_door_half_open;
	t_image							up_door_open;
	t_image							lamp_0;
	t_image							lamp_1;
	t_image							lamp_2;
	t_image							lamp_3;
	t_image							sprites_ceiling[NB_SPRITES_C];
	t_image							sprites_floor[NB_SPRITES_F];
	t_image							treasure;
	t_image							bar;
	t_image							health_bar;
	t_image							stamina_bar;
	t_image							magic_bar;
	t_image							cursor;
	t_image							death_screen;
	t_image							werewolf_moving_0;
	t_image							werewolf_moving_1;
	t_image							werewolf_moving_2;
	t_image							werewolf_moving_3;
	t_image							werewolf_attack_0;
	t_image							werewolf_attack_1;
	t_image							werewolf_attack_2;
	t_image							werewolf_damaged;
	t_image							werewolf_dead;
	t_image							skeleton_moving_0;
	t_image							skeleton_moving_1;
	t_image							skeleton_moving_2;
	t_image							skeleton_moving_3;
	t_image							skeleton_attack_0;
	t_image							skeleton_attack_1;
	t_image							skeleton_attack_2;
	t_image							skeleton_attack_3;
	t_image							skeleton_attack_4;
	t_image							skeleton_attack_5;
	t_image							skeleton_damaged;
	t_image							skeleton_dead;
	t_image							zombie_moving_0;
	t_image							zombie_moving_1;
	t_image							zombie_moving_2;
	t_image							zombie_moving_3;
	t_image							zombie_moving_4;
	t_image							zombie_moving_5;
	t_image							zombie_moving_6;
	t_image							zombie_moving_7;
	t_image							zombie_attack_0;
	t_image							zombie_attack_1;
	t_image							zombie_attack_2;
	t_image							zombie_attack_3;
	t_image							zombie_attack_4;
	t_image							zombie_damaged;
	t_image							zombie_dead;
}									t_texture;

// ============================================================================
// INPUT AND MOVEMENT STRUCTURES
// ============================================================================

typedef struct s_key
{
	int								key_a;
	int								key_d;
	int								key_w;
	int								key_s;
	int								key_left;
	int								key_right;
	int								key_up;
	int								key_down;
	int								key_e;
}									t_key;

// ============================================================================
// UTILITY STRUCTURES
// ============================================================================

typedef struct s_garbage
{
	void							*alloc;
	struct s_garbage				*next;
}									t_garbage;

typedef struct s_rect
{
	t_coord_int						pos;
	float							width;
	float							height;
}									t_rect;

typedef struct s_fps
{
	float							current_time;
	float							total_time;
	float							frame_times[60];
	int								frame_index;
	int								frames_counted;
}									t_fps;

typedef struct s_time
{
	float							time;
	float							oldtime;
	float							frametime;
	int								fps;
}									t_time;

// ============================================================================
// SCREEN AND UI STRUCTURES
// ============================================================================

typedef enum state
{
	START,
	EXIT,
}									t_state;

typedef struct s_starting_screen
{
	t_state							state;
	bool							start;
}									t_starting_screen;

// ============================================================================
// HUD AND MINIMAP STRUCTURES
// ============================================================================

typedef struct s_minimap
{
	t_coord_int						here;
	t_coord_int						player;
	t_coord_int						start;
	t_coord_int						end;
	t_coord_int						offset;
	t_coord_int						pos;
	t_coord_float					pixel_offset;
	int								radius;
}									t_minimap;

typedef struct s_enemies_on_map
{
	t_coord_float					relative_pos;
	t_coord_int						map_pos;
	t_rect							rect;
}									t_enemies_on_map;

// ============================================================================
// DOOR SYSTEM STRUCTURES
// ============================================================================

typedef struct s_door
{
	t_coord_int						pos;
	bool							is_open;
	float							open_amount;
	float							open_speed;
	int								sprite_index;
}									t_door;

typedef struct s_door_list
{
	t_door							*doors;
	int								count;
	int								capacity;
}									t_door_list;

// ============================================================================
// RAYCASTING STRUCTURES
// ============================================================================

typedef struct s_ray
{
	t_coord_float					ray_dir;
	float							camera_x;
	t_coord_float					delta_dist;
	t_coord_float					step;
	t_coord_int						map;
	t_coord_float					side_dist;
	int								side;
	float							perp_wall_dist;
	t_coord_float					wall_hit;
	int								line_height;
	int								draw_start;
	int								draw_end;
	float							wall_x;
	int								tex_num;
	int								tex_x;
	float							tex_pos;
	float							tex_step;
	int								tex_y;
	int								hit;
	int								p;
	float							pos_z;
	float							row_distance;
	int								upper_wall_height;
	int								upper_draw_start;
	int								upper_draw_end;
	int								original_upper_draw_start;
	float							upper_step;
	float							skip_pixels;
	float							upper_tex_pos;
}									t_ray;

// ============================================================================
// SPRITE SYSTEM STRUCTURES
// ============================================================================

typedef struct s_sprite
{
	char							type;
	t_image							*image;
	t_coord_float					pos;
	t_coord_float					dir;
	t_coord_float					delta;
	float							distance;
	t_coord_float					transformed_pos;
	int								screen_x;
	int								height;
	int								width;
	t_coord_int						draw_start;
	t_coord_int						draw_end;
	int								tex_x;
	int								tex_y;
	int								tex_offset;
	int								d;
	float							offset;
	float							scale;
	bool							is_seeing_player;
	struct s_sprite					*next;
}									t_sprite;

// ============================================================================
// PLAYER SYSTEM STRUCTURES
// ============================================================================

typedef enum weapon_type
{
	FIST,
	SWORD,
	MAGIC_SWORD,
}									t_weapon_type;

typedef enum action
{
	IDLE,
	WALKING,
	RUNNING,
	ATTACKING,
	CASTING,
}									t_action;

typedef enum impact
{
	BASE,
	BLOOD,
}									t_impact;

typedef struct s_weapons
{
	t_weapon_type					type;
	int								damage;
	float							range;
}									t_weapons;

typedef struct s_magick
{
	t_image							*hand_left;
	t_image							*hand_right;
	t_image							*spell;
	bool							casted;
	bool							casting;
	bool							cd;
}									t_magick;

typedef struct s_player
{
	t_coord_float					pos;
	t_coord_float					dir;
	t_coord_float					plane;
	float							angle;
	int								hp;
	int								mp;
	int								is_hit;
	t_action						action;
	t_weapons						weapon;
	t_magick						magick;
	int								impact;
	t_impact						impact_effect;
	int								impact_zone;
	float							central_ray_distance;
	int								central_ray_map_x;
	int								central_ray_map_y;
}									t_player;

// ============================================================================
// ENEMY SYSTEM STRUCTURES
// ============================================================================

typedef enum e_enemy_type
{
	WEREWOLF,
	SKELETON,
	ZOMBIE
}									t_enemy_type;

typedef enum e_state_enemy
{
	STANDING,
	MOVING,
	ATTACK,
	DAMAGED,
	DEAD
}									t_state_enemy;

typedef struct s_enemy
{
	t_sprite						*sprite;
	t_enemy_type					type;
	t_state_enemy					state;
	int								hp;
	float							speed;
	float							attack_range;
	int								attack_cooldown;
	int								attack_timer;
	int								attack_damage;
	int								attack_speed;
	bool							attack_hit;
	struct s_enemy					*next;
}									t_enemy;

// ============================================================================
// MAIN DATA STRUCTURE
// ============================================================================

typedef struct s_data
{
	char							**map;
	t_file							file;
	t_mlx							mlx;
	t_starting_screen				starting_screen;
	t_time							time;
	t_player						player;
	t_garbage						*gc_list;
	t_texture						texture;
	t_door_list						doors;
	t_image							frame;
	t_key							keys;
	t_minimap						minimap;
	t_sprite						*sprite;
	t_enemy							*enemy;
	float							z_buffer[WIN_WIDTH];
}									t_data;

// ============================================================================
// PARSING FUNCTIONS
// ============================================================================

bool								check_texture(char **tab, char *id);
bool								check_colors(char **tab, char *id);
bool								is_valid_map_char(char c);
bool								check_data(t_data *data);
bool								check_map_nl(char *str);
bool								check_map(t_data *data);
bool								get_data(t_data *data);
bool								get_map(t_data *data);
bool								check_filename(char *filename, char *ext);
void								parsing(int argc, char **argv,
										t_data *data);
bool								read_file(char *filename, t_data *data);

// ============================================================================
// RAYCASTING FUNCTIONS
// ============================================================================

void								draw_ceiling_column(t_data *data, t_ray ray,
										int x, int ceiling_end);
void								update_central_ray(t_data *data, t_ray *ray,
										int x);
void								draw_double_wall(t_data *data, t_ray *ray,
										int x);
void								draw_floor_column(t_data *data, t_ray ray,
										int x, int floor_end);
void								init_ray(t_data *data, t_ray *ray, int x);
void								perp_distance_to_wall(t_data *data,
										t_ray *ray);
void								get_wall_column(t_data *data, t_ray *ray);
void								raycasting(t_data *data);
void								get_texture_column(t_ray *ray, char c);
void								draw_wall_texture(t_data *data, t_ray *ray,
										int x, t_image texture);
void								draw_wall(t_data *data, t_ray *ray, int x);

// ============================================================================
// SCREEN MANAGEMENT FUNCTIONS
// ============================================================================

void								starting_screen(t_data *data);
void								load_screens(t_data *data);
void								destroy_screens(t_data *data);

// ============================================================================
// SPRITE SYSTEM FUNCTIONS
// ============================================================================

void								render_sprites(t_data *data);
void								get_sprite_texture(t_data *data);
void								get_sprites_from_map(t_data *data);
void								sort_sprites(t_sprite **lst);
void								draw_sprites(t_data *data);
void								update_animated_sprites(t_data *data);

// ============================================================================
// ENEMY SYSTEM FUNCTIONS
// ============================================================================

void								update_enemies(t_data *data);
void								init_enemy(t_data *data);
void								update_animated_enemies(t_data *data);
void								update_skeleton(t_enemy *current,
										t_data *data);
void								update_werewolf(t_enemy *current,
										t_data *data);
void								update_zombie(t_enemy *current,
										t_data *data);
void								move_enemies(t_data *data);
void								combat_enemies(t_data *data);
void								enemy_take_damage(t_data *data,
										t_enemy *enemy);
bool								can_see_player(t_data *data,
										t_enemy *enemy);
void								check_impact_on_enemy(t_data *data,
										t_enemy *enemy);
bool								is_on_screen(t_enemy *enemy);
bool								is_enemy_blocking(t_data *data, int map_x,
										int map_y);

// ============================================================================
// EFFECTS FUNCTIONS
// ============================================================================

// From effects.h
void								render_effects(t_data *data);
void								render_impact_effect(t_data *data);

// ============================================================================
// IMAGE MANAGEMENT FUNCTIONS
// ============================================================================

void								destroy_effects(t_data *data);
void								destroy_enemies(t_data *data);
void								destroy_player(t_data *data);
void								destroy_magick(t_data *data);
void								destroy_sprites(t_data *data);
void								destroy_textures(t_data *data);
void								load_img(t_data *data, t_image *sprite,
										char *path);
void								init_img(t_data *data);
void								destroy_img(t_data *data);
void								load_effects(t_data *data);
void								load_enemies(t_data *data);
void								load_player(t_data *data);
void								load_magick(t_data *data);
void								load_sprites(t_data *data);
void								load_screens(t_data *data);
void								load_textures(t_data *data);

// ============================================================================
// GAME LOOP FUNCTIONS
// ============================================================================

int									loop(t_data *data);

// ============================================================================
// HUD AND INTERFACE FUNCTIONS
// ============================================================================

void								render_health_bar(t_data *data);
void								render_hud(t_data *data);
void								draw_enemies_on_map(t_data *data,
										t_rect *player_rect);
void								draw_player_on_map(t_data *data,
										t_rect *player_rect);
void								render_minimap(t_data *data);

// ============================================================================
// MOVEMENT AND INPUT FUNCTIONS
// ============================================================================

void								player_move(t_data *data);
void								moving_angle(t_player *player, float angle);
void								calculate_new_position(t_data *data,
										t_coord_float *move);

// ============================================================================
// PLAYER SYSTEM FUNCTIONS
// ============================================================================

void								init_player(t_data *data);
void								render_player(t_data *data);
void								render_player_idle(t_data *data);
void								render_player_walking(t_data *data,
										double current_time);
void								render_player_running(t_data *data,
										double current_time);
void								render_player_attacking(t_data *data,
										double current_time);
void								render_player_casting(t_data *data);
void								render_spell_effect(t_data *data);
void								render_player_magick(t_data *data);
void								change_weapons(t_data *data);
void								init_weapons(t_data *data);
void								combat_player(t_data *data);

// ============================================================================
// UTILITY FUNCTIONS
// ============================================================================

int									rgb_to_int(u_int8_t r, u_int8_t g,
										u_int8_t b);
int									*int_to_rgb(int color);
bool								is_pixel_transparent(unsigned int color);
void								apply_shadow(float distance, int *color,
										char type);
void								init_rect(t_rect *rect, float size,
										int start_x, int start_y);
int									draw_rect(t_image *img, t_rect rect,
										int color);
void								draw_line(t_image *img, t_coord_int start,
										t_coord_int end, int color);
void								put_img_to_frame(t_image *frame,
										t_image *img, int x, int y);
int									exit_success(t_data *data);
int									exit_failure(t_data *data, char *str);
float								get_time(void);
void								print_fps(t_data *data);
void								fps_counter(t_data *data);
void								free_all(t_data *data);
void								gc_free(t_garbage **gc_list);
void								*gc_add_malloc(void *ptr,
										t_garbage **gc_list);
char								**gc_add_tab(char **tab,
										t_garbage **gc_list);
void								*gc_malloc(size_t size,
										t_garbage **gc_list);
void								print_data_map(t_data data);
void								print_sprites(t_data *data);
void								print_enemies(t_data *data);
int									get_texture_color(t_image *texture, int x,
										int y);
void								img_pix_put(t_image *img, int x, int y,
										int color);
void								upscale_img(t_data *data, t_image *sprite,
										int dest_x, int dest_y);

// ============================================================================
// DOOR SYSTEM FUNCTIONS
// ============================================================================

void								update_doors(t_data *data);
void								get_doors_from_map(t_data *data);
void								interact_with_door(t_data *data);
bool								is_door_blocking(t_data *data, int map_x,
										int map_y);
int									get_door_texture_index(t_data *data,
										int map_x, int map_y);
bool								should_ray_pass_through_door(t_data *data,
										t_ray *ray, int x);

// ============================================================================
// INPUT HANDLING FUNCTIONS
// ============================================================================

int									handle_keypress(int keysym, t_data *data);
int									handle_keyrelease(int keysym, t_data *data);
int									mouse_hook(t_data *data);
int									handle_mouse(int button, int x, int y,
										t_data *data);

#endif