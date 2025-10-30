/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jda-cruz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 13:56:02 by jda-cruz          #+#    #+#             */
/*   Updated: 2025/10/30 15:59:34 by jda-cruz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"
#include "../libft/libft.h"

void	*load_image(t_game *game, char *path)
{
	void	*img;

	img = mlx_xpm_file_to_image(game->mlx, path, &game->tile_w, &game->tile_h);
	if (!img)
	{
		ft_putstr_fd("Erro ao carregar imagem: ", 2);
		ft_putstr_fd(path, 2);
		ft_putstr_fd("\n", 2);
		handle_destroy(game);
		exit(1);
	}
	return (img);
}

int	draw_images(t_game *game)
{
	game->y = 0;
	while (game->y < game->map_height && game->map[game->y])
	{
		game->x = 0;
		while (game->x < game->map_width && game->map[game->y][game->x])
		{
			mlx_put_image_to_window(game->mlx, game->win, game->background_img,
				game->x * game->tile_w, game->y * game->tile_h);
			if (game->map[game->y][game->x] == '1')
				mlx_put_image_to_window(game->mlx, game->win, game->wall_img,
					game->x * game->tile_w, game->y * game->tile_h);
			else if (game->map[game->y][game->x] == 'P')
				mlx_put_image_to_window(game->mlx, game->win, game->player_img,
					game->x * game->tile_w, game->y * game->tile_h);
			else if (game->map[game->y][game->x] == 'C')
				mlx_put_image_to_window(game->mlx, game->win, game->colctb_img,
					game->x * game->tile_w, game->y * game->tile_h);
			else if (game->map[game->y][game->x] == 'E')
				mlx_put_image_to_window(game->mlx, game->win, game->exit_img,
					game->x * game->tile_w, game->y * game->tile_h);
			game->x++;
		}
		game->y++;
	}
	return (0);
}

static int	key_wrapper(int keycode, void *param)
{
	return (handle_key((t_game *)param, keycode));
}

int	start_game(t_game *game, int win_w, int win_h)
{
	game->mlx = mlx_init();
	if (!game->mlx)
	{
		perror("Erro ao inicializar a mlx!");
	}
	game->win = mlx_new_window(game->mlx, win_w, win_h, "So_long");
	if (!game->win)
	{
		handle_destroy(game);
	}
	game->background_img = load_image(game, "textures/black.xpm");
	game->player_img = load_image(game, "textures/play.xpm");
	game->wall_img = load_image(game, "textures/parede.xpm");
	game->colctb_img = load_image(game, "textures/coletavell.xpm");
	game->exit_img = load_image(game, "textures/exit.xpm");
	game->player_down = load_image(game, "textures/play_down.xpm");
	game->player_left = load_image(game, "textures/play_left.xpm");
	game->player_right = load_image(game, "textures/play_right.xpm");
	game->player_up = load_image(game, "textures/play_up.xpm");
	draw_images(game);
	mlx_hook(game->win, 2, 1L << 0, handle_key, game);
	mlx_hook(game->win, 17, 0, handle_destroy, game);
	mlx_key_hook(game->win, key_wrapper, game);
	mlx_loop(game->mlx);
	return (0);
}
