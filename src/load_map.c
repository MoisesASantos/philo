/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jda-cruz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/27 06:39:00 by jda-cruz          #+#    #+#             */
/*   Updated: 2025/10/30 13:40:51 by jda-cruz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../so_long.h"
#include"../libft/libft.h"

int	is_ber_file(char *filename)
{
	int	len;

	len = ft_strlen(filename);
	if (len < 5)
		return (0);
	if (ft_strncmp(&filename[len - 4], ".ber", 4) != 0)
	{
		ft_putstr_fd("Erro no nome do arquivo", 2);
		return (1);
	}
	if (filename[len - 5] == '.' || filename[len - 5] == '/')
	{
		ft_putstr_fd("Erro no nome do arquivo", 2);
		return (1);
	}
	return (0);
}

char	**load_map(t_game *game, char *path)
{
	int		bytes;
	char	buffer[4096];

	game->fd = open(path, O_RDONLY);
	if (game->fd == -1)
	{
		ft_putstr_fd("Ficheiro .ber nao encontrado\n", 2);
		close(game->fd);
		exit(1);
	}
	bytes = read(game->fd, buffer, sizeof(buffer) - 1);
	if (bytes == -1)
	{
		ft_putstr_fd("Erro ao ler o ficheiro\n", 2);
		close(game->fd);
		exit(1);
	}
	buffer[bytes] = '\0';
	close(game->fd);
	game->map = ft_split(buffer, '\n');
	if (!game->map)
	{
		exit(1);
	}
	return (game->map);
}
