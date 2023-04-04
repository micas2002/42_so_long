/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tilemap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mibernar <mibernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 09:36:20 by miguel            #+#    #+#             */
/*   Updated: 2022/09/22 15:08:19 by mibernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_tile	**alloc_tilemap(char **map)
{
	t_tile	**tilemap;
	int		i;

	i = 0;
	while (map[i] != NULL)
		i++;
	tilemap = (t_tile **)malloc(sizeof(t_tile *) * (i + 1));
	if (tilemap == NULL)
		return (NULL);
	i = 0;
	while (map[i])
	{
		tilemap[i] = malloc(sizeof(t_tile) * ft_strlen(map[i]) + 1);
		if (!tilemap)
		{
			free(tilemap);
			return (NULL);
		}
		i++;
	}
	return (tilemap);
}

t_type	define_tiletype(char definer)
{
	if (definer == '1')
		return (WALL);
	if (definer == '2')
		return (ENEMY);
	if (definer == 'C')
		return (COLLECTABLE);
	if (definer == 'P')
		return (PLAYER);
	if (definer == 'E')
		return (EXIT);
	return (FLOOR);
}

void	setup_tile(t_tile **tilemap, int x, int y, t_game *mlx)
{
	tilemap[y][x].og_type = tilemap[y][x].tile_type;
	tilemap[y][x].pos.x = x * 64;
	tilemap[y][x].pos.y = y * 64;
	if (y != 0)
		tilemap[y][x].up = &tilemap[y - 1][x];
	if (y < mlx->map_info.size.x)
		tilemap[y][x].down = &tilemap[y + 1][x];
	if (x != 0)
		tilemap[y][x].left = &tilemap[y][x - 1];
	tilemap[y][x].right = &tilemap[y][x + 1];
}

void	set_gamevars(t_tile *tile, t_game *mlx)
{
	if (tile->tile_type == PLAYER)
		mlx->player.tile = tile;
	else if (tile->tile_type == COLLECTABLE)
		mlx->map_info.collectible++;
}

t_tile	**generate_tilemap(char **map, t_game *game)
{
	t_tile		**tilemap;
	int			x;
	int			y;

	tilemap = alloc_tilemap(map);
	if (!tilemap)
		return (NULL);
	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x] != '\0')
		{
			tilemap[y][x].tile_type = define_tiletype(map[y][x]);
			setup_tile(tilemap, x, y, game);
			set_gamevars(&tilemap[y][x], game);
			x++;
		}
		y++;
	}
	tilemap[y] = NULL;
	game->movements = 0;
	return (tilemap);
}
