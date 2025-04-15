/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keypress.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabe <sabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 18:15:58 by sabe              #+#    #+#             */
/*   Updated: 2025/04/15 17:48:43 by sabe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int	key_hook(int keycode, t_fdf *fdf)
{
	if (keycode == 65307)
		mlx_loop_end(fdf->mlx);
	return (0);
}

int	close_win(t_fdf *fdf)
{
	mlx_loop_end(fdf->mlx);
	return (0);
}
