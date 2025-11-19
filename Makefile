CXX = c++
SRCS = srcs/main.cpp srcs/draw.cpp srcs/draw_utils.cpp srcs/hook.cpp \
		srcs/check_map.cpp srcs/check_file.cpp \
		srcs/check_path.cpp srcs/Game.cpp srcs/Map.cpp srcs/Player.cpp \
		srcs/sound.cpp srcs/exit_sprite.cpp srcs/collection_sprite.cpp \
		srcs/player_sprite.cpp srcs/Object.cpp srcs/Monster.cpp \
		srcs/move_monster.cpp srcs/monster_sprite.cpp srcs/game_end.cpp \
		srcs/game_error.cpp srcs/map_error.cpp
OBJS = $(SRCS:.cpp=.o)
CFLAGS = -Wall -Wextra -Werror
NAME = so_long
HIR = includes

MLX_DIR = mlx
MLX_FLAGS = -L$(MLX_DIR) -lmlx -framework OpenGL -framework Appkit
MLX_LIB = ./$(MLX_DIR)/libmlx.a

BASS_DIR    = bass24-osx
BASS_ARCH   = arm64
BASS_LIBDIR = $(BASS_DIR)/$(BASS_ARCH)
BASS_FLAGS = -L$(BASS_LIBDIR) -lbass
BASS_RPATH = -Wl,-rpath,@loader_path/$(BASS_LIBDIR)
LDFLAGS = $(MLX_FLAGS) $(BASS_FLAGS) $(BASS_RPATH)

all : $(NAME)

$(NAME) : $(OBJS)
	make -C mlx all
	make -C $(BASS_DIR) $(BASS_ARCH)
	$(CXX) $(CFLAGS) $(OBJS) $(MLX_LIB) $(LDFLAGS) -o $(NAME)

%.o : %.cpp
	$(CXX) $(CFLAGS) -I$(HIR) -I$(MLX_DIR) -c $< -o $@

clean :
	make clean -C $(MLX_DIR)
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re :
	make fclean
	make all

.PHONY : all clean fclean re
