/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bloc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaterno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 18:30:59 by jpaterno          #+#    #+#             */
/*   Updated: 2022/08/01 18:31:00 by jpaterno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"
#include "libft/libft.h"
#include "mlx.h"

t_data	*get_wall(t_bag *as)
{
	t_data	*dr_wall;
	int		a;
	int		b;

	dr_wall = NULL;
	dr_wall = malloc(sizeof(t_data) * 1);
	if (dr_wall == NULL)
		ft_close (as, "--0Error malloc");
	dr_wall->g = mlx_xpm_file_to_image(as->sr, "./pics/wall.xpm", &a, &b);
	return (dr_wall);
}

t_data	*get_g(t_bag *as)
{
	t_data	*dr_g;
	int		a;
	int		b;

	dr_g = NULL;
	dr_g = malloc(sizeof(t_data) * 1);
	if (dr_g == NULL)
		ft_close (as, "--1Error malloc");
	dr_g->g = mlx_xpm_file_to_image(as->sr, "./pics/g.xpm", &a, &b);
	return (dr_g);
}

t_data	*get_item(t_bag *as)
{
	t_data	*dr_i;
	int		a;
	int		b;

	dr_i = NULL;
	dr_i = malloc(sizeof(t_data) * 1);
	if (dr_i == NULL)
		ft_close (as, "--2Error malloc");
	dr_i->g = mlx_xpm_file_to_image(as->sr, "./pics/collectable.xpm", &a, &b);
	return (dr_i);
}

t_data	*get_player(t_bag *as)
{
	t_data	*dr_p;
	int		a;
	int		b;

	dr_p = NULL;
	dr_p = malloc(sizeof(t_data) * 1);
	if (dr_p == NULL)
		ft_close (as, "--3Error malloc");
	dr_p->g = mlx_xpm_file_to_image(as->sr, "./pics/character.xpm", &a, &b);
	return (dr_p);
}

t_data	*get_exit(t_bag *as)
{
	t_data	*dr_exit;
	int		a;
	int		b;

	dr_exit = NULL;
	dr_exit = malloc(sizeof(t_data) * 1);
	if (dr_exit == NULL)
		ft_close (as, "--4Error malloc");
	dr_exit->g = mlx_xpm_file_to_image(as->sr, "./pics/exit.xpm", &a, &b);
	return (dr_exit);
}
