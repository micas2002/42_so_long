/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_to.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mibernar <mibernar@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 12:38:45 by miguel            #+#    #+#             */
/*   Updated: 2022/10/17 13:41:24 by mibernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_to_floor(t_game *mlx, t_tile *tile)
{
	tile->tile_type = PLAYER;
	if (mlx->player.tile->tile_type != EXIT)
		mlx->player.tile->tile_type = FLOOR;
	mlx->player.tile = tile;
}	

void	move_to_collectible(t_game *mlx, t_tile *tile)
{
	tile->tile_type = PLAYER;
	mlx->player.tile->tile_type = FLOOR;
	mlx->player.tile = tile;
	mlx->map_info.collectible--;
}

void	move_to_exit(t_game *mlx)
{
	if (mlx->map_info.collectible > 0)
		return ;
	close_window(mlx);
}
