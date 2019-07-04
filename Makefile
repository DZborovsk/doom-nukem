# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akolinko <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/09 11:13:10 by akolinko          #+#    #+#              #
#    Updated: 2019/03/09 11:14:13 by akolinko         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

HEADER =  \n \
  ░▄█████▄    ▄██████▄   ▄██████▄   ░█████▄▄████▄        ░███████▄   ░██░  ░██░  ░██   ██ ░██████▄░  ░█████▄▄████▄  \n\
  ░███▀ ▀██  ▒██░  ░██▒ ▒██░  ░██▒  ░██░ ░██▀░░██░       ░██░░░░██▒  ░██░  ░██░  ░██ ░██░ ░██░ ░ ░   ░██░ ░██▀░░██░\n\
  ░███  ▒██  ▒██░  ░██▒ ▒██░  ░██▒  ▒██░ ▒██░ ▒██░       ░██░  ▒██░  ░██░  ░██░  ░█████░░  ░███▒░    ▒██░ ▒██░ ▒██░\n \
  ░███  ▄██  ░██░  ░██░ ░██░  ░██░  ░██░ ▒██░ ░██░       ░██░  ░██░  ░██░  ░██░  ░██░▀██▄ ░██░ ░ ░   ░██░ ▒██░ ░██░\n \
  ░██████▀ ░░ ▀██████▀░  ▀██████▀░  ░██▒ ▒██░ ▒██░▄▄▄▄▄▄▄░██▒  ▒██░   ▀██████▀░  ░██░ ▒██░ ██████▀▒  ░██▒ ▒██░ ▒██░\n \
  ░ ░▒ ▒  ░░ ▒░▒░▒░ ░ ▒▓ ░▒▓░░░ ▒░ ░░ ▓░▒ ▒░  ▒▒   ▓▒░░░ ▒░ ░▒ ▒  ▒  ░  ░ ▒░ ░▒░  ░ ░  ░░░ ░░ ░   ░  ░ ░░▒ ▒░  ▒▒  \n \
  ░ ░  ▒     ░ ▒ ▒░   ░▒ ░ ▒░ ░ ░▒ ░  ▒ ░ ░ ░  ▒   ▒▒ ░  ░▒ ░  ░  ▒░ ▒ ░  ░▒ ░ ▒░  ░ ░ ▓    ░ ▓ ░  ░   ▒ ░ ░ ░  ▒  \n \
    ░ ░      ░ ░ ░ ▒    ░░   ░    ▒     ░   ░    ░   ▒  ▒  ░    ░  ▒  ▒   ░   ░   ░ ▓  ▒ ░    ░   ▓      ░   ░    ░\n \
     ░           ░ ░     ░        ░▒ ░    ░          ░  ░       ▒   ░   ░   ░      ░  ▒      ▒    ░░ ░░    ░        \n \

NAME 	= 	doom-nukem

RESET		= \033[m
GREEN       = \033[32m

SRC_DR 	:=	src/
OBJ_DR 	:=	obj/
INC_DR 	:=	include/
LIB_DR 	:=	libft/

SRC 	= 	main.c	help_other.c			start_sdl.c				\
			quit.c			img_load.c		init_data.c 			\
			text_draw.c	tex_sprite.c								\
			init_start.c					sdl_exit.c 				\
			float_func.c				sector_inter.c 				\
			fly_mode.c		doom_map.c			main_math.c 		\
			move_keys.c		messages.c								\
			render_draw.c			screen_vec.c 	ceil_floor.c	\
			pixel_set.c		render_walls.c 	frame_draw.c 			\
			texture_draw.c		math_2.c							\
			sprites_tex.c			sprites_calc.c	sprites_draw.c	\
			enemy_draw.c	sprite_calc_2.c							\
			check_sprite.c											\
			vector.c 			line_draw.c 						\
			helmet_draw.c 				helmet_draw_2.c 			\
			weapon_load.c 			weapon_png.c	start_game.c	\
			item_draw.c												\
			enemy_png.c				color_make.c 	vline_item.c	\
			sky_draw.c				position_enemy.c				\
			wall_tex.c 												\
			key_calc.c 			mouse_calc.c 		engine.c		\
			point_pixel.c 				game_physic.c 				\
			door.c 				lift.c 				read_2.c	    \
			read_1.c 			read_3.c							\
			error_check.c 											\
			find_tex.c 	find_tex_2.c 								\
			search_map.c 											\
			split.c 			fps.c					help.c		\
			menu.c 					menu_help.c			gnl.c		\
			weapon_1.c			weapon_2.c				draw_aim.c

OBJ 	=	$(addprefix $(OBJ_DR), $(SRC:.c=.o))
LIBFT 	= 	$(LIBFT_D)libft.a
LIBFT_D :=	$(LIB_DR)
LIBFT_F := 	-lft -L $(LIBFT_D)
INC		=	-I $(INC_DR)															\
			-I ./SDL2/SDL2.framework/Versions/A/Headers 							\
			-I ./SDL2/SDL2_ttf.framework/Versions/A/Headers 						\
			-I ./SDL2/SDL2_image.framework/Versions/A/Headers 						\
			-I ./SDL2/SDL2_mixer.framework/Headers 									\
			-F ./SDL2 
FRAMEW	=	-F ./SDL2 																\
			-rpath ./SDL2 															\
			-framework OpenGL -framework AppKit -framework OpenCl 					\
			-framework SDL2 -framework SDL2_ttf -framework SDL2_image 				\
			-framework SDL2_mixer
LINK_F 	:= 	$(LIBFT_F)
GCC_F 	:= 	-Wall -Wextra -Werror -O3


#.SILENT:
all: tmp
	@make -C $(LIBFT_D)
	@make $(NAME)

tmp:	
	@make logotype
	@printf '\033[32m[ ✔ ] %58s\n\033[0m' "LOADING"
	@mkdir -p $(OBJ_DR)

run: tmp	
	@make -C $(LIBFT_D)
	@make $(NAME)
	@./$(NAME) 1 &

logotype:
	@echo "\033[1;36m$(HEADER)"

$(NAME): $(LIBFT) $(OBJ) $(INC_DR)
	@gcc $(OBJ) $(LINK_F) -o $(NAME) $(INC) $(FRAMEW) 

$(OBJ_DR)%.o: %.c
	@gcc -c $< -o $@ $(GCC_F) $(HEADER_FLAGS) $(INC)
	@echo "$(GREEN)█$(RESET)\c)"

$(LIBFT):
	@make -C $(LIBFT_D)

norm:
	@norminette ./$(LIB_PTH)/libft/*.c
	@norminette ./$(LIB_PTH)/libft/*.h
	@norminette ./$(SRC_PTH)/*.c
	@norminette ./include/*.h

clean:
	@make clean -C $(LIBFT_D)
	@printf '\033[31m[ ✔ ] %s\n\033[0m' "Clean doom"
	@/bin/rm -f $(OBJ)

fclean: clean
	@make fclean -C $(LIBFT_D)
	@printf '\033[31m[ ✔ ] %s\n\033[0m' "Fclean doom"
	@/bin/rm -f $(NAME)

re: fclean all

.PHONY: clean fclean re all

vpath %.c $(SRC_DR)
