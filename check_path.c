/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mibernar <mibernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 11:31:42 by mibernar          #+#    #+#             */
/*   Updated: 2022/09/22 15:11:08 by mibernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	valid(t_game *mlx, int y, int x)
{
	if (mlx->path[y][x] == 'C')
		return (0);
	if (mlx->path[y][x] == 'E')
	{
		if (mlx->path[y][x - 1] != 'P' && mlx->path[y - 1][x] != 'P'
			&& mlx->path[y][x + 1] != 'P' && mlx->path[y + 1][x] != 'P')
			return (0);
	}
	return (1);
}

void	mark_possible(t_game *mlx, int y, int x)
{
	mlx->path[y][x] = 'P';
	if (x - 1 > -1 && (mlx->path[y][x - 1] == 'C'
		|| mlx->path[y][x - 1] == '0'))
		mark_possible(mlx, y, x - 1);
	if (y - 1 > -1 && (mlx->path[y - 1][x] == 'C'
		|| mlx->path[y - 1][x] == '0'))
		mark_possible(mlx, y - 1, x);
	if (x + 1 < (mlx->map_info.size.x)
		&& (mlx->path[y][x + 1] == 'C' || mlx->path[y][x + 1] == '0'))
		mark_possible(mlx, y, x + 1);
	if (y + 1 < (mlx->map_info.size.y)
		&& (mlx->path[y + 1][x] == 'C' || mlx->path[y + 1][x] == '0'))
		mark_possible(mlx, y + 1, x);
	return ;
}

void	copy_map(t_game *mlx)
{
	int	i;
	int	y;

	i = -1;
	y = -1;
	while (mlx->map_tiles[++y])
		;
	mlx->path = malloc(sizeof(char *) * (y + 1));
	if (!mlx->path)
		return ;
	while (++i < y)
	{
		mlx->path[i] = ft_strdup(mlx->map_tiles[i]);
		if (!mlx->path[i])
			return ;
	}
	mlx->path[i] = NULL;
}

int	check_path(t_game *mlx)
{
	int	x;
	int	y;

	copy_map(mlx);
	x = mlx->map_info.p_pos_x;
	y = mlx->map_info.p_pos_y;
	mark_possible(mlx, y, x);
	y = -1;
	while (++y < (mlx->map_info.size.y))
	{
		x = -1;
		while (mlx->path[y][++x])
		{
			if (valid(mlx, y, x) == 0)
				return (0);
		}
	}
	return (1);
}
