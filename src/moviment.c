/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moviment.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jda-cruz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 16:48:17 by jda-cruz          #+#    #+#             */
/*   Updated: 2025/10/30 12:35:42 by jda-cruz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../so_long.h"
#include"../libft/libft.h"
#include"../ft_printf/ft_printf.h"

static int	check_exit(t_game *game, int new_x, int new_y)
{
	if (game->map[new_y][new_x] == 'E')
	{
		if (game->collectibles_count == 0)
		{
			ft_putstr_fd("Parabéns! Você venceu!\n", 1);
			handle_destroy(game);
		}
		return (0);
	}
	return (1);
}

void	move_player(t_game *game, int new_x, int new_y)
{
	if (new_y < 0 || new_y >= game->map_height
		|| new_x < 0 || new_x >= game->map_width)
		return ;
	if (game->map[new_y][new_x] == '1')
		return ;
	if (game->map[new_y][new_x] == 'C')
	{
		game->collectibles_count--;
		game->map[new_y][new_x] = '0';
	}
	if (!check_exit(game, new_x, new_y))
		return ;
	game->map[game->player_y][game->player_x] = '0';
	game->player_x = new_x;
	game->player_y = new_y;
	game->map[new_y][new_x] = 'P';
	game->moves++;
	ft_printf("Movimentos: %d\n", game->moves);
	draw_images(game);
}
