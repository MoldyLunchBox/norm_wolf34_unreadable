
CC = clang

NAME = wolf3d

FLAGS = 

IDIR = ./include

CFLAGS = -I include \
		 -I libSDL/SDL2.framework/Headers \
		 -I libSDL/SDL2_image.framework/Headers \
		 -I libSDL/SDL2_ttf.framework/Headers \
		 -I libSDL/SDL2_mixer.framework/Headers \
		 -g




LIBFT = libft

SDL2_F		= -framework SDL2 -framework SDL2_image -framework SDL2_ttf -framework SDL2_mixer  -F ./libSDL/

SDL2_P		= -rpath @loader_path/libSDL/

DIR_S = src

DIR_O = obj

HEADER = include

_DEPS = wolf3d.h

DEPS = $(patsubst %,$(HEADER)/%,$(_DEPS))

SOURCES =   main.c parsing.c init_loading.c tools.c tools_2.c tools_3.c load_textures.c load_textures_2.c events.c mouse_events_1.c play_conditions.c mouse_events_2.c sprites.c sprites_init_rect.c sprites_2.c sprites_reset.c screens.c screen_options.c play.c play_2.c render_1.c render_2.c render_3.c draw.c enemy.c

SRCS = $(addprefix $(DIR_S)/,$(SOURCES))

OBJS = $(addprefix $(DIR_O)/,$(SOURCES:.c=.o))

all: obj $(NAME)

$(NAME): $(OBJS)
		make -C $(LIBFT)
		$(CC) -o $(NAME) $(OBJS) $(FLAGS)  libft/libft.a $(SDL2_P) $(SDL2_F)

obj:
		mkdir -p obj

$(DIR_O)/%.o: $(DIR_S)/%.c $(DEPS)
		$(CC) -c -o $@ $< $(FLAGS) $(CFLAGS)

clean:
		rm -f $(OBJS)
		make clean -C $(LIBFT)
		rm -rf $(DIR_O)

fclean: clean
		rm -f $(NAME)
		make fclean -C $(LIBFT)

re: fclean all
