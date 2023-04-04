/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mibernar <mibernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 14:53:24 by miguel            #+#    #+#             */
/*   Updated: 2022/09/22 14:44:08 by mibernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_borders(char **map, int y, t_game *mlx)
{
	int	x;

	x = 0;
	if (y == mlx->map_info.size.y || y == 0)
	{
		while (map[y][x] && map[y][x] != '\n')
		{
			if (map[y][x] == '1')
				x++;
			else
				return (0);
		}
	}
	else
	{
		if (map[y][0] == '1' && map[y][mlx->map_info.size.x - 1] == '1')
			x++;
		else
			return (0);
	}
	return (1);
}

void	check_tile(char **map, int x, int y, t_game *mlx)
{
	char	c;

	c = map[y][x];
	if (c != '1' && c != '0' && c != 'C' && c != 'E' && c != 'P' && c != '2')
		mlx->map_info.true_false = 0;
	if (c == 'P')
	{
		mlx->map_info.player++;
		mlx->map_info.p_pos_x = x;
		mlx->map_info.p_pos_y = y;
	}
	if (c == 'E')
	{
		mlx->map_info.exit += 1;
		mlx->map_info.e_pos_x = x;
		mlx->map_info.e_pos_y = y;
	}
	if (c == 'C')
		mlx->map_info.collectible = 1;
	return ;
}

void	get_map_data(char **map, t_game *mlx)
{
	int	x;

	mlx->map_info.size.x = ft_strlen(map[0]) - 1;
	x = 0;
	while (map[x])
		x++;
	mlx->player.frames = 0;
	mlx->map_info.size.y = x;
	mlx->map_info.player = 0;
	mlx->map_info.exit = 0;
	mlx->map_info.collectible = 0;
	mlx->map_info.true_false = 1;
	return ;
}

int	number_lines(int fd)
{
	int		linecount;
	int		readcount;
	int		line_size;
	char	c;	

	linecount = 1;
	line_size = 0;
	while (1)
	{
		readcount = read(fd, &c, 1);
		line_size += readcount;
		if (readcount == 0)
			break ;
		if (readcount < 0)
			return (-1);
		if (c == '\n')
			linecount++;
	}
	close(fd);
	return (linecount);
}

int	check_map(t_game *mlx)
{
	int		x;
	int		y;

	get_map_data(mlx->map_tiles, mlx);
	y = -1;
	while (mlx->map_tiles[++y])
	{
		if ((int)ft_strlen(mlx->map_tiles[y]) != mlx->map_info.size.x + 1)
			return (0);
		x = 0;
		while (mlx->map_tiles[y][x] && mlx->map_tiles[y][x] != '\n')
		{
			check_tile(mlx->map_tiles, x, y, mlx);
			if (mlx->map_info.true_false == 0)
				return (0);
			x++;
		}
		if (check_borders(mlx->map_tiles, y, mlx) == 0)
			return (0);
	}
	if (mlx->map_info.collectible == 0 || mlx->map_info.exit != 1
		|| mlx->map_info.player != 1)
		return (0);
	mlx->map_info.collectible = 0;
	return (1);
}
