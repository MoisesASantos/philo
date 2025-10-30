/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jda-cruz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 13:56:22 by jda-cruz          #+#    #+#             */
/*   Updated: 2025/10/30 16:05:42 by jda-cruz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <stddef.h>
# include "minilibx-linux/mlx.h"

typedef struct s_game
{
	void	*mlx;
	void	*win;
	char	**map;
	int		player_x;
	int		player_y;
	void	*wall_img;
	void	*player_img;
	void	*player_up;
	void	*player_down;
	void	*player_left;
	void	*player_right;
	void	*background_img;
	void	*colctb_img;
	void	*exit_img;
	int		collectibles_count;
	int		tile_w;
	int		tile_h;
	int		new_x;
	int		new_y;
	int		map_width;
	int		map_height;
	int		moves;
	int		x;
	int		y;
	int		fd;
}	t_game;

typedef struct s_counts
{
	int	player;
	int	exit;
	int	collectible;
}	t_counts;

int		count_line(char *path);
void	init_player_position(t_game *game);
int		count_colum(char *path);
void	move_player(t_game *game, int new_x, int new_y);
int		handle_destroy(t_game *game);
int		draw_images(t_game *game);
void	print_map(char **map);
int		start_game(t_game *game, int win_w, int win_h);
char	**ft_split(char const *s, char c);
int		validate_map(t_game *game);
char	**load_map(t_game *game, char *path);
void	*load_image(t_game *game, char *path);
int		handle_key(t_game *game, int keycode);
int		check_path(t_game *game);
int	is_ber_file(char *filename);

#endif
