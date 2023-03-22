/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_imgs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mibernar <mibernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 11:07:42 by miguel            #+#    #+#             */
/*   Updated: 2022/08/10 16:23:49 by mibernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	open_doors(t_game *mlx)
{
	mlx->exit_img.exit_img = mlx_xpm_file_to_image(mlx->mlx_ptr,
			"./sprites/door.xpm", &mlx->img_size.x, &mlx->img_size.y);
	mlx->exit_img.exit_img_2 = mlx_xpm_file_to_image(mlx->mlx_ptr,
			"./sprites/door_2.xpm", &mlx->img_size.x, &mlx->img_size.y);
}

void	open_colectibles(t_game *mlx)
{
	mlx->col_img.col_img = mlx_xpm_file_to_image(mlx->mlx_ptr,
			"./sprites/colectible.xpm", &mlx->img_size.x, &mlx->img_size.y);
}

void	open_walls(t_game *mlx)
{
	mlx->wall_img.wall_img = mlx_xpm_file_to_image(mlx->mlx_ptr,
			"./sprites/wall.xpm", &mlx->img_size.x, &mlx->img_size.y);
	mlx->floor_img.floor_img = mlx_xpm_file_to_image(mlx->mlx_ptr,
			"./sprites/floor.xpm", &mlx->img_size.x, &mlx->img_size.y);
}

void	open_players(t_game *mlx)
{
	mlx->player.player_img = mlx_xpm_file_to_image(mlx->mlx_ptr,
			"./sprites/player.xpm", &mlx->img_size.x, &mlx->img_size.y);
	mlx->player.player_img_2 = mlx_xpm_file_to_image(mlx->mlx_ptr,
			"./sprites/player_2.xpm", &mlx->img_size.x, &mlx->img_size.y);
	mlx->player.current_img = mlx->player.player_img;
	mlx->enemy_img.enemy_img = mlx_xpm_file_to_image(mlx->mlx_ptr,
			"./sprites/enemy.xpm", &mlx->img_size.x, &mlx->img_size.y);
}

void	open_imgs(t_game *mlx)
{
	open_players(mlx);
	open_walls(mlx);
	open_colectibles(mlx);
	open_doors(mlx);
}
