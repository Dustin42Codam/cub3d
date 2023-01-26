NAME = cub3D

SRC_DIR = src
INC_DIR = include
OBJ_DIR = obj

TARGET := $(shell uname -s)

ifeq ($(TARGET),Linux)
	LIB_SUFFIX = a
	LIB_FLAGS := -L mlx/*.a -Lmlx -L/usr/lib -Imlx -lXext -lX11 -lm -lz
	LIB_MLX = -I/usr/include -Imlx
else
	LIB_SUFFIX = dylib
	LDFLAGS := -framework OpenGL -framework AppKit
	LIB_MLX = -I/usr/include -Imlx
endif

LIBFT = $(SRC_DIR)/libft
LIBFT_LIB := $(LIBFT)/libft.$(LIB_SUFFIX)

LINUX_LIBMLX_LIB = mlx
MACOS_LIBMLX_LIB = 0

VPATH = $(SRC_DIR);

SRC =	main.c \
		init_data.c init_map.c init_img.c init_mlx.c \
		init_sprite.c init_area.c init_textures.c \
		check_file_type.c check_save.c check_screensize.c \
		read_map.c \
		parser.c parse_resolution.c parse_textures.c parse_rgb.c parse_map.c \
		set_orientation.c set_sprites.c set_textures.c \
		validate_dummy_map.c dummy_map.c \
		loop_hooks.c key_hooks.c \
		player_move.c player_rotate.c \
		cast_rays.c cast_sprites.c \
		calculate_walls.c \
		draw_ray.c \
		make_screenshot.c \
		exit_game.c

SRC := $(SRC:%=$(SRC_DIR)/%)

OBJ := $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

CFLAGS = -Wextra -Wall

all: $(NAME)

$(NAME): $(OBJ)
	@make -C src/libft
	@make -C mlx
	@$(CC) -g $(CFLAGS) $(OBJ) -L  mlx/*.a -Lmlx -L/usr/lib -Imlx -lXext -lX11 -lm -lz src/libft/libft.a -o $(NAME)

obj/%.o: src/%.c
	@mkdir -p obj
	@$(CC) -g $(CFLAGS) -I src/libft -I mlx -c $< -o $@

run: all
	@./raycaster maps/basic_map.cub

cleanrun: all clean run
test_run: all
	@./raycaster maps/test_parser.cub

norm:
	@norminette $(SRC_DIR) $(INC_DIR)

fclean: clean
	@rm -f $(LIBFT_LIB)
	@rm -f $(NAME)

clean:
	@rm -rf $(OBJ_DIR)/*
	@$(MAKE) clean -C $(LIBFT)

re: clean all

valgrind: all
	valgrind --tool=memcheck --leak-check=yes --track-origins=yes --leak-check=full \
	--show-leak-kinds=all --error-limit=no --suppressions=mlx.supp ./cub3D maps/test_parser.cub

valgrind_re: re
	valgrind --tool=memcheck --leak-check=yes --track-origins=yes --leak-check=full \
	--show-leak-kinds=all --error-limit=no --suppressions=mlx.supp ./cub3D maps/test_parser.cub

gen_supp: all
	valgrind --tool=memcheck --leak-check=yes --track-origins=yes --leak-check=full \
	--show-leak-kinds=all --gen-suppressions=all --log-file=valgrind.out --error-limit=no \
	--suppressions=mlx.supp ./cub3D maps/test_parser.cub

test_main:
	@$(CC) -g test_main.c $(LIB_FLAGS) $(LIB_MLX)
