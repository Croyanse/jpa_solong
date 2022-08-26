/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaterno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 20:07:28 by jpaterno          #+#    #+#             */
/*   Updated: 2022/07/27 20:07:29 by jpaterno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"
#include "libft/libft.h"
#include "mlx.h"

int	ft_goup(t_bag *as)
{
	int	x;
	int	y;

	x = as->pp[0] / 50;
	y = as->pp[1] / 50;
	if (as->tab[y - 1][x] == 'E' && as->nb_c < 1)
		ft_close(as, "Exit by end game");
	if (as->tab[y - 1][x] == '1' || (as->tab[y - 1][x] == 'E' && as->nb_c != 0))
		return (0);
	else if (as->tab[y - 1][x] == 'C')
	{
		as->nb_c = as->nb_c - 1;
		as->tab[y - 1][x] = '0';
	}
	mlx_put_image_to_window(as->sr, as->wi, as->g->g, *as->pp, as->pp[1]);
	mlx_put_image_to_window(as->sr, as->wi, as->p->g, *as->pp, as->pp[1] - 50);
	as->pp[1] -= 50;
	return (1);
}

int	ft_godown(t_bag *as)
{
	int	x;
	int	y;

	x = as->pp[0] / 50;
	y = as->pp[1] / 50;
	if (as->tab[y + 1][x] == 'E' && as->nb_c < 1)
		ft_close(as, "Exit by end game");
	else if (as->tab[y + 1][x] == '1' || as->tab[y + 1][x] == 'E')
		return (0);
	else if (as->tab[y + 1][x] == 'C')
	{
		as->nb_c = as->nb_c - 1;
		as->tab[y + 1][x] = '0';
	}
	mlx_put_image_to_window(as->sr, as->wi, as->g->g, *as->pp, as->pp[1]);
	mlx_put_image_to_window(as->sr, as->wi, as->p->g, *as->pp, as->pp[1] + 50);
	as->pp[1] += 50;
	return (1);
}

int	ft_goleft(t_bag *as)
{
	int	x;
	int	y;

	x = as->pp[0] / 50;
	y = as->pp[1] / 50;
	if (as->tab[y][x - 1] == 'E' && as->nb_c < 1)
		ft_close(as, "Exit by end game");
	else if (as->tab[y][x - 1] == '1' || as->tab[y][x - 1] == 'E')
		return (0);
	else if (as->tab[y][x - 1] == 'C')
	{
		as->nb_c = as->nb_c - 1;
		as->tab[y][x - 1] = '0';
	}
	mlx_put_image_to_window(as->sr, as->wi, as->g->g, *as->pp, as->pp[1]);
	mlx_put_image_to_window(as->sr, as->wi, as->p->g, *as->pp - 50, as->pp[1]);
	as->pp[0] -= 50;
	return (1);
}

int	ft_goright(t_bag *as)
{
	int	x;
	int	y;

	x = as->pp[0] / 50;
	y = as->pp[1] / 50;
	if (as->tab[y][x + 1] == 'E' && as->nb_c < 1)
		ft_close(as, "Exit by end game");
	else if (as->tab[y][x + 1] == '1' || as->tab[y][x + 1] == 'E')
		return (0);
	else if (as->tab[y][x + 1] == 'C')
	{
		as->nb_c = as->nb_c - 1;
		as->tab[y][x + 1] = '0';
	}
	mlx_put_image_to_window(as->sr, as->wi, as->g->g, *as->pp, as->pp[1]);
	mlx_put_image_to_window(as->sr, as->wi, as->p->g, *as->pp + 50, as->pp[1]);
	as->pp[0] += 50;
	return (1);
}
