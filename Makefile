# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bfernan2 <bfernan2@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/03 17:02:16 by bfernan2          #+#    #+#              #
#    Updated: 2025/11/29 15:09:27 by bfernan2         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

MAKEFLAGS += --silent

NAME= so_long

SRCS= main.c utils.c map.c validations_map.c \
validations_map2.c mlx_utils.c utils2.c utils3.c handlers.c movement.c render.c \
flood_fill.c

LIBFT_DIR= ./libft/
LIBFT= $(LIBFT_DIR)/libft.a
MINILIBX= ./minilibx-linux/libmlx.a

OBJ= $(SRCS:.c=.o)
CC= cc
CFLAGS= -Wall -Werror -Wextra -g
MLX_FLAGS= -L./minilibx-linux -lmlx -lXext -lX11

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	@$(CC) $(CFLAGS) $(SRCS) $(MLX_FLAGS) $(LIBFT) -o $(NAME)

$(LIBFT):
	@$(MAKE) -s -C $(LIBFT_DIR) all

clean:
	@rm -f $(OBJ)
	@$(MAKE) -s -C $(LIBFT_DIR) clean

fclean: clean
	@rm -f $(NAME)
	@$(MAKE) -s -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re