/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_destroy.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jda-cruz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 11:40:02 by jda-cruz          #+#    #+#             */
/*   Updated: 2025/10/30 16:04:44 by jda-cruz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../so_long.h"

void	free_images(t_game *game)
{
	if (game->player_img)
		mlx_destroy_image(game->mlx, game->player_img);
	if (game->background_img)
		mlx_destroy_image(game->mlx, game->background_img);
	if (game->wall_img)
		mlx_destroy_image(game->mlx, game->wall_img);
	if (game->colctb_img)
		mlx_destroy_image(game->mlx, game->colctb_img);
	if (game->exit_img)
		mlx_destroy_image(game->mlx, game->exit_img);
	if (game->player_down)
		mlx_destroy_image(game->mlx, game->player_down);
	if (game->player_left)
		mlx_destroy_image(game->mlx, game->player_left);
	if (game->player_right)
		mlx_destroy_image(game->mlx, game->player_right);
	if (game->player_up)
		mlx_destroy_image(game->mlx, game->player_up);
}

void	free_map(t_game *game)
{
	int	i;

	if (!game->map)
		return ;
	i = 0;
	while (game->map[i])
		free(game->map[i++]);
	free(game->map);
}

int	handle_destroy(t_game *game)
{
	free_images(game);
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
	free_map(game);
	exit(1);
}
