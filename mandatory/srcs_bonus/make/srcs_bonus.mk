# MAIN
SRCS_BONUS_PATH = ./srcs_bonus/
SRCS_BONUS = main_bonus.c

# DOORS
SRCS_BONUS_PATH += ./srcs_bonus/doors/
SRCS_BONUS += animate_doors.c
SRCS_BONUS += init_doors.c
SRCS_BONUS += interact_doors.c
SRCS_BONUS += render_doors.c

# EFFECTS
SRCS_BONUS_PATH += ./srcs_bonus/effects/
SRCS_BONUS += effects.c
SRCS_BONUS += impact.c

# ENEMIES
SRCS_BONUS_PATH += ./srcs_bonus/enemies/
SRCS_BONUS += animate_enemies.c
SRCS_BONUS += animate_skeleton.c
SRCS_BONUS += animate_werewolf.c
SRCS_BONUS += animate_zombie.c
SRCS_BONUS += combat_enemies.c
SRCS_BONUS += init_enemies.c
SRCS_BONUS += enemies.c
SRCS_BONUS += move_enemies.c
SRCS_BONUS += raycast_enemies.c
SRCS_BONUS += utils_enemies.c

# HUD
SRCS_BONUS_PATH += ./srcs_bonus/hud/
SRCS_BONUS += health.c
SRCS_BONUS += hud.c
SRCS_BONUS += m_enemies.c
SRCS_BONUS += m_player.c
SRCS_BONUS += minimap.c

# IMAGES
SRCS_BONUS_PATH += ./srcs_bonus/img/
SRCS_BONUS += destroy_effects.c
SRCS_BONUS += destroy_enemies.c
SRCS_BONUS += destroy_magick.c
SRCS_BONUS += destroy_player.c
SRCS_BONUS += destroy_sprites.c
SRCS_BONUS += destroy_textures.c
SRCS_BONUS += img.c
SRCS_BONUS += load_effects.c
SRCS_BONUS += load_enemies.c
SRCS_BONUS += load_magick.c
SRCS_BONUS += load_player.c
SRCS_BONUS += load_sprites.c
SRCS_BONUS += load_textures.c

# INPUTS
SRCS_BONUS_PATH += ./srcs_bonus/inputs/
SRCS_BONUS += keypress_bonus.c
SRCS_BONUS += keyrelease_bonus.c
SRCS_BONUS += mousehook_bonus.c

# LOOP
SRCS_BONUS_PATH += ./srcs_bonus/loop/
SRCS_BONUS += loop.c

# MOVEMENT
SRCS_BONUS_PATH += ./srcs_bonus/move/
SRCS_BONUS += move.c
SRCS_BONUS += new_pos.c

# PARSING
SRCS_BONUS_PATH += ./srcs_bonus/parsing/
SRCS_BONUS += check_data_bonus.c
SRCS_BONUS += check_data_utils_bonus.c
SRCS_BONUS += check_map_bonus.c
SRCS_BONUS += check_map_nl_bonus.c
SRCS_BONUS += get_data_bonus.c
SRCS_BONUS += get_map_bonus.c
SRCS_BONUS += parsing_bonus.c
SRCS_BONUS += read_file_bonus.c

# PLAYER
SRCS_BONUS_PATH += ./srcs_bonus/player/
SRCS_BONUS += attack.c
SRCS_BONUS += combat.c
SRCS_BONUS += idle.c
SRCS_BONUS += init_player.c
SRCS_BONUS += magick.c
SRCS_BONUS += player.c
SRCS_BONUS += running.c
SRCS_BONUS += spell.c
SRCS_BONUS += walking.c
SRCS_BONUS += weapons.c

# RAYCASTING
SRCS_BONUS_PATH += ./srcs_bonus/raycasting/
SRCS_BONUS += ceiling.c
SRCS_BONUS += central_ray.c
SRCS_BONUS += double_wall.c
SRCS_BONUS += floor.c
SRCS_BONUS += init_ray.c
SRCS_BONUS += raycasting.c
SRCS_BONUS += wall.c

# SCREENS
SRCS_BONUS_PATH += ./srcs_bonus/screens/
SRCS_BONUS += screens.c
SRCS_BONUS += img_screens.c

# SPRITES
SRCS_BONUS_PATH += ./srcs_bonus/sprites/
SRCS_BONUS += animate_sprite.c
SRCS_BONUS += draw_sprite.c
SRCS_BONUS += init_sprite.c
SRCS_BONUS += sort_sprites.c
SRCS_BONUS += render_sprites.c

# UTILS
SRCS_BONUS_PATH += ./srcs_bonus/utils/
SRCS_BONUS += colors.c
SRCS_BONUS += draw_forms.c
SRCS_BONUS += exit_bonus.c
SRCS_BONUS += fps_counter_bonus.c
SRCS_BONUS += free_bonus.c
SRCS_BONUS += garbage_collector_bonus.c
SRCS_BONUS += print_bonus.c
SRCS_BONUS += put_pix.c
SRCS_BONUS += upscale_img.c
