/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jda-cruz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 13:55:23 by jda-cruz          #+#    #+#             */
/*   Updated: 2025/10/30 14:54:58 by jda-cruz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"
#include "../libft/libft.h"

int	count_line(char *path)
{
	char		ch;
	int			fd;
	int			linhas;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (-1);
	linhas = 0;
	while (read(fd, &ch, 1) > 0)
	{
		if (ch == '\n')
			linhas++;
	}
	close(fd);
	return (linhas);
}

int	count_colum(char *path)
{
	char		ch;
	int			fd;
	int			colunas;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (-1);
	colunas = 0;
	while (read(fd, &ch, 1) > 0 && ch != '\n')
		colunas++;
	close(fd);
	return (colunas);
}

void	init_player_position(t_game *game)
{
	int		y;
	int		x;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] == 'P')
			{
				game->player_x = x;
				game->player_y = y;
				return ;
			}
			x++;
		}
		y++;
	}
}

void	count_collectibles(t_game *game)
{
	int	y;
	int	x;

	game->collectibles_count = 0;
	y = 0;
	while (y < game->map_height)
	{
		x = 0;
		while (x < game->map_width)
		{
			if (game->map[y][x] == 'C')
				game->collectibles_count++;
			x++;
		}
		y++;
	}
}

int	main(int argc, char **argv)
{
	t_game	game;
	int		win_w;
	int		win_h;

	ft_bzero(&game, sizeof(t_game));
	if (argc != 2)
		return (0);
	game.tile_w = 40;
	game.tile_h = 40;
	game.moves = 0;
	game.map_width = count_colum(argv[argc - 1]);
	game.map_height = count_line(argv[argc - 1]);
	win_w = game.tile_w * game.map_width;
	win_h = game.tile_h * game.map_height;
	if (count_colum(argv[argc - 1]) > 38 || count_line(argv[argc - 1]) > 20)
	{
		printf("Erro: O mapa excede o tamanho da janela.\n");
		exit(1);
	}
	if (is_ber_file(argv[1]) == 1)
		return (0);
	game.map = load_map(&game, argv[1]);
	init_player_position(&game);
	if (!validate_map(&game))
	{
		ft_putstr_fd("Mapa inválido\n", 2);
		exit(1);
	}
	start_game(&game, win_w, win_h);
	return (0);
}
