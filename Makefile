# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bfresque <bfresque@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/17 10:44:39 by abonnefo          #+#    #+#              #
#    Updated: 2024/01/11 11:04:25 by bfresque         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

CC = gcc

CFLAGS = -Wall -Wextra -Werror -g3

FLAGMLX = -L ./includes/minilibx-linux/ -lmlx -lX11 -lXext -g3 -lm
DIRMLX = ./includes/minilibx-linux/
MLXFILE = libmlx.a
MLXEXE = $(addprefix $(DIRMLX), $(MLXFILE)) $(FLAGMLX)

OBJ_DIR_CUB3D = objs_cub3D

OBJ_DIR_LIBFT = libft/obj_libft

SRCS_MAIN = srcs/main/main.c \

SRCS_EXEC_CUB3D = srcs/exec_cub3D/cub3d.c \
	srcs/exec_cub3D/display_game.c \
	srcs/exec_cub3D/display_map.c \
	srcs/exec_cub3D/display_pixels.c \
	srcs/exec_cub3D/key_press.c \
	srcs/exec_cub3D/player_move.c \
	srcs/exec_cub3D/put_pixels.c \
	srcs/exec_cub3D/rays.c \

SRCS_INIT = srcs/init/init_colors.c \
	srcs/init/init_pos_directions.c \
	srcs/init/init_pos_player.c \
	srcs/init/init_rays_directions.c \
	srcs/init/init_textures_adress.c \
	srcs/init/init_textures_filename.c \
	srcs/init/init_window.c \
	srcs/init/master_init.c \

SRCS_PARSING = srcs/parsing/master_pars.c \
	srcs/parsing/pars_begin_params.c \
	srcs/parsing/pars_floor_and_ceiling.c \
	srcs/parsing/pars_textures.c \
	srcs/parsing/pars_maps.c \
	srcs/parsing/pars_start_player.c \

SRCS_UTILS = srcs/utils/create_map.c \
	srcs/utils/free.c \
	srcs/utils/libft_modify.c \
	srcs/utils/put_in_tab.c \
	srcs/utils/read_and_join.c \
	srcs/utils/utils_parsing.c \
	srcs/utils/utils.c \

SRCS_LIBFT = libft/ft_atoi.c \
	libft/ft_bzero.c \
	libft/ft_calloc.c \
	libft/ft_isalnum.c \
	libft/ft_isalpha.c \
	libft/ft_isascii.c \
	libft/ft_isdigit.c \
	libft/ft_isprint.c \
	libft/ft_itoa.c \
	libft/ft_memchr.c \
	libft/ft_memcmp.c \
	libft/ft_memcpy.c \
	libft/ft_memmove.c \
	libft/ft_memset.c \
	libft/ft_putchar_fd.c \
	libft/ft_putendl_fd.c \
	libft/ft_putnbr_fd.c \
	libft/ft_putstr_fd.c \
	libft/ft_split.c \
	libft/ft_strchr.c \
	libft/ft_strcpy.c \
	libft/ft_strdup.c \
	libft/ft_striteri.c \
	libft/ft_strjoin.c \
	libft/ft_strlcat.c \
	libft/ft_strlcpy.c \
	libft/ft_strlen.c \
	libft/ft_strmapi.c \
	libft/ft_strncmp.c \
	libft/ft_strnstr.c \
	libft/ft_strrchr.c \
	libft/ft_strtrim.c \
	libft/ft_substr.c \
	libft/ft_tolower.c \
	libft/ft_toupper.c \

SRCS_LIBFT_BONUS = libft/ft_lstadd_back.c \
	libft/ft_lstadd_front.c \
	libft/ft_lstclear.c \
	libft/ft_lstdelone.c \
	libft/ft_lstiter.c \
	libft/ft_lstlast.c \
	libft/ft_lstmap.c \
	libft/ft_lstnew.c \
	libft/ft_lstsize.c \
	libft/ft_realloc.c \
	libft/ft_strncpy.c \

SRCS_GNL = libft/GNL/get_next_line.c \
	libft/GNL/get_next_line_utils.c \

SRCS_PRINTF = libft/ft_printf/ft_printf.c \
	libft/ft_printf/ft_print_%.c \
	libft/ft_printf/ft_print_c.c \
	libft/ft_printf/ft_print_d.c \
	libft/ft_printf/ft_print_p.c \
	libft/ft_printf/ft_print_s.c \
	libft/ft_printf/ft_print_u.c \
	libft/ft_printf/ft_print_x.c \

OBJS = $(SRCS_MAIN:%.c=$(OBJ_DIR_CUB3D)/%.o) \
		$(SRCS_EXEC_CUB3D:%.c=$(OBJ_DIR_CUB3D)/%.o) \
		$(SRCS_INIT:%.c=$(OBJ_DIR_CUB3D)/%.o) \
		$(SRCS_PARSING:%.c=$(OBJ_DIR_CUB3D)/%.o) \
		$(SRCS_UTILS:%.c=$(OBJ_DIR_CUB3D)/%.o) \
		$(SRCS_LIBFT:%.c=$(OBJ_DIR_LIBFT)/%.o) \
		$(SRCS_LIBFT_BONUS:%.c=$(OBJ_DIR_LIBFT)/%.o) \
		$(SRCS_GNL:%.c=$(OBJ_DIR_LIBFT)/%.o) \
		$(SRCS_PRINTF:%.c=$(OBJ_DIR_LIBFT)/%.o) \

AR = ar rcs

RM = rm -f

all : mlx $(NAME)

mlx :
	@$(MAKE) -sC $(DIRMLX)

$(OBJ_DIR_CUB3D)/%.o $(OBJ_DIR_LIBFT)/%.o: %.c
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS) Makefile includes/minilibx-linux/mlx.h
	@$(CC) $(CFLAGS) $(OBJS) $(MLXEXE) -o $(NAME)
	@echo "\033[5;36m-gcc *.c minilibx done\033[0m"
	@echo "\033[5;36m\n-gcc *.c libft done\033[0m"
	@echo "\033[5;36m-gcc *.c get_next_line done\033[0m"
	@echo "\033[5;36m-gcc *.c ft_printf done\033[0m"
	@echo "\033[5;36m-gcc *.c cub3D done\n\033[0m"
	@echo "\033[1;32m[Make : 'cub3D' is done]\033[0m"

clean :
	@$(RM) $(OBJS)
	@$(RM) -rf $(OBJ_DIR_CUB3D)
	@$(RM) -rf $(OBJ_DIR_LIBFT)
	@echo "\033[1;33m[.o] Object files and directories removed\033[0m"

fclean : clean
	@$(RM) $(NAME)
	@echo "\033[1;33m[.a] Binary file removed\033[0m"

re : fclean all

.PHONY: all clean fclean re