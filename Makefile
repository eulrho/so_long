CXX = c++
SRCS = srcs/main.cpp srcs/draw.cpp srcs/draw_utils.cpp srcs/hook.cpp \
		srcs/check_map.cpp srcs/check_file.cpp \
		srcs/check_path.cpp srcs/Game.cpp srcs/Map.cpp srcs/Player.cpp
OBJS = $(SRCS:.cpp=.o)
CFLAGS = -Wall -Wextra -Werror
NAME = so_long
HIR = includes
CLIB = -Lmlx -lmlx -framework OpenGL -framework Appkit
MLX = ./mlx/libmlx.a

all : $(NAME)

$(NAME) : $(OBJS)
	make -C mlx all
	$(CXX) $(CFLAGS) $(CLIB) $(OBJS) $(MLX) -o $(NAME)

%.o : %.c
	$(CXX) $(CFLAGS) -Imlx -c $< -o $@ -I$(HIR)

clean :
	make clean -C mlx
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re :
	make fclean
	make all

.PHONY : all clean fclean re
