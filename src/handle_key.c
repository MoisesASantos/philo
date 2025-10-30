/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_key.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jda-cruz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 11:40:59 by jda-cruz          #+#    #+#             */
/*   Updated: 2025/10/30 12:35:00 by jda-cruz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../so_long.h"

static void	move_with_key(t_game *game, int keycode)
{
	if (keycode == 119)
	{
		game->player_img = game->player_up;
		move_player(game, game->player_x, game->player_y - 1);
	}
	else if (keycode == 115)
	{
		game->player_img = game->player_down;
		move_player(game, game->player_x, game->player_y + 1);
	}
	else if (keycode == 97)
	{
		game->player_img = game->player_left;
		move_player(game, game->player_x - 1, game->player_y);
	}
	else if (keycode == 100)
	{
		game->player_img = game->player_right;
		move_player(game, game->player_x + 1, game->player_y);
	}
}

int	handle_key(t_game *game, int keycode)
{
	if (keycode == 65307)
		handle_destroy(game);
	else
		move_with_key(game, keycode);
	return (0);
}
