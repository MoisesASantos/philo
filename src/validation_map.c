/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jda-cruz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 17:12:10 by jda-cruz          #+#    #+#             */
/*   Updated: 2025/10/30 12:36:06 by jda-cruz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../so_long.h"
#include "../libft/libft.h"

static int	check_char_and_count(char c,
		int *player_count, int *exit_count, int *collectible_count)
{
	if (c != '0' && c != '1' && c != 'C' && c != 'E' && c != 'P')
	{
		ft_putstr_fd("Erro: caracter inválido no mapa\n", 2);
		return (0);
	}
	if (c == 'P')
		(*player_count)++;
	else if (c == 'E')
		(*exit_count)++;
	else if (c == 'C')
		(*collectible_count)++;
	return (1);
}

static int	check_borders(t_game *game, int y, int x, int width)
{
	if (y == 0 || y == game->map_height - 1 || x == 0 || x == width - 1)
	{
		if (game->map[y][x] != '1')
		{
			ft_putstr_fd("Erro: mapa não rodeado por paredes\n", 2);
			return (0);
		}
	}
	return (1);
}

static int	validate_cell(t_game *game, int y, int x, t_counts *counts)
{
	if (!check_char_and_count(game->map[y][x],
		&counts->player, &counts->exit, &counts->collectible))
		return (0);
	if (!check_borders(game, y, x, ft_strlen(game->map[0])))
		return (0);
	return (1);
}

static int	validate_keep(t_game *game, t_counts *counts)
{
	int	x;
	int	y;
	int	width;

	width = ft_strlen(game->map[0]);
	y = 0;
	while (y < game->map_height)
	{
		if ((int)ft_strlen(game->map[y]) != width)
			return (ft_putstr_fd("Erro: mapa não rectangular\n", 2), 0);
		x = 0;
		while (x < width)
		{
			if (!validate_cell(game, y, x, counts))
				return (0);
			x++;
		}
		y++;
	}
	return (1);
}

int	validate_map(t_game *game)
{
	t_counts	counts;

	counts.player = 0;
	counts.exit = 0;
	counts.collectible = 0;
	if (!validate_keep(game, &counts))
		return (0);
	if (counts.player != 1)
		return (ft_putstr_fd("Erro: precisa de 1 player\n", 2), 0);
	if (counts.exit != 1)
		return (ft_putstr_fd("Erro: precisa de 1 saída\n", 2), 0);
	if (counts.collectible < 1)
		return (ft_putstr_fd("Erro: precisa de pelo menos 1 colecionável\n",
				2), 0);
	if (!check_path(game))
		return (ft_putstr_fd("Erro: locais inacessiveis!!!\n", 2), 0);
	game->collectibles_count = counts.collectible;
	return (1);
}
