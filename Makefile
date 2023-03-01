GREENGREEN = \033[38;5;46m
RED = \033[0;31m
BLUE = \033[0;34m
GREY = \033[38;5;240m
RESET = \033[0m

NAME = fractol

CC = gcc
CFLAGS = -Wall -Wextra -Werror -O3
RM = rm -rf

DIR_H = headers/
DIR_S =	srcs/
DIR_O =	objs/

SRCS_LIST = init.c mandelbrot.c main.c hook.c julia.c colors.c burningship.c

SRCS = $(addprefix $(DIR_S), $(SRCS_LIST))

OBJS = $(SRCS:$(DIR_S)%.c=$(DIR_O)%.o)

# Compile la Libft
DIR_LIBFT = libft/
LIBFT_INC = -I ${DIR_LIBFT}
LIBFT =	${DIR_LIBFT}libft.a
FT_LNK = -L ${DIR_LIBFT} -l ft

# Compile la MiniLibX suivant l'OS
ifeq (${shell uname}, Linux)
	DIR_MLX = mlx_linux/
	MLX_LNK	= -L $(DIR_MLX) -lXext -lX11 -lbsd -l mlx
else
	DIR_MLX = mlx_macos/
	MLX_LNK	= -L $(DIR_MLX) -l mlx -framework OpenGL -framework AppKit
endif
MLX_INC = -I ${DIR_MLX}
MLX =	${DIR_MLX}/mlx.a

LIBS = $(FT_LNK) $(MLX_LNK)

$(NAME): $(LIBFT) $(MLX) $(OBJS)
	@echo "$(BLUE)  ______ _____ ########## _____ _______ ____  _ $(RESET)"
	@echo "$(GREENGREEN) |  ____|  __ \     /\   / ____|__   __/ __ \| | $(RESET)"
	@echo "$(GREENGREEN) | |__  | |__| |   /  \ | |       | | | |  | | |$(RESET)"
	@echo "$(GREENGREEN) |  __| |  _  /   / /\ \| |       | | | |  | | | $(RESET)"
	@echo "$(GREENGREEN) | |    | | \ \  / ____ \ |____   | | | |__| | |____ $(RESET)"
	@echo "$(BLUE) |_|    |_|  \_\/_/    \_\_____|  |_|  \____/|______|$(RESET)"
	${CC} ${OBJS} ${LIBS} -o ${NAME}

$(LIBFT):
	$(MAKE) -sC $(@D)

$(MLX):
	$(MAKE) -sC $(@D)

all: $(NAME)

${DIR_O}%.o:${DIR_S}%.c
	@mkdir -p ${DIR_O}
	${CC} ${CFLAGS} ${LIBFT_INC} ${MLX_INC} -I ${DIR_H} -o $@ -c $<
# ${CC} ${CFLAGS} -I ${DIR_H} ${LIBFT_INC} ${MLX_INC} -o $@ -c $<

clean:
	@echo "$(RED)╔═╗╔═╗╔═╗╔╦╗╔╗ ╦ ╦╔═╗$(RESET)"
	@echo "$(RED)║ ╦║ ║║ ║ ║║╠╩╗╚╦╝║╣$(RESET)"
	@echo "$(RED)╚═╝╚═╝╚═╝═╩╝╚═╝ ╩ ╚═╝$(RESET)"
	$(RM) $(OBJS)
	${RM} ${DIR_O}

libclean:
	@echo "Clean de MiniLibX"
	${MAKE} -sC ${DIR_MLX} clean
	@echo "Clean de libft"
	${MAKE} -sC ${DIR_LIBFT} fclean
	
fclean: clean libclean
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re