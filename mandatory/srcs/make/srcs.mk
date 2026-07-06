SRCS_PATH = ./srcs/
SRCS = main.c

SRCS_PATH += ./srcs/garbage/
SRCS += garbage_collector.c

SRCS_PATH += ./srcs/img/
SRCS += init_img.c
SRCS += destroy_img.c
SRCS += utils_img.c

SRCS_PATH += ./srcs/init/
SRCS += init.c

SRCS_PATH += ./srcs/mov/ 
SRCS += keypress.c
SRCS += keyrelease.c

SRCS_PATH += ./srcs/raycasting/
SRCS += raycast_main.c
SRCS += raycast_init.c
SRCS += raycast_texture.c

SRCS_PATH += ./srcs/parsing/
SRCS += check_data_utils.c
SRCS += check_data.c
SRCS += check_map_nl.c
SRCS += check_map.c
SRCS += get_data.c
SRCS += get_map.c
SRCS += parsing.c
SRCS += read_file.c

SRCS_PATH += ./srcs/render/
SRCS += render.c

SRCS_PATH += ./srcs/utils/
SRCS += exit.c
SRCS += free.c
SRCS += print.c
SRCS += utils.c