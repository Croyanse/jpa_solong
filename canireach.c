/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   canireach.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaterno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 22:43:51 by jpaterno          #+#    #+#             */
/*   Updated: 2022/08/05 22:43:52 by jpaterno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "solong.h"
#include "mlx.h"

int	ft_checkifdone(char **gr, int total_e);
int	ft_nbrp(char **gr);

int	co_ft_canireach(t_bag *as, int x, int y)
{
	if (y == -1)
	{
		y = 0;
		while (as->tab[y])
			free (as->tab[y++]);
		return (0);
	}
	if (as->tab[y][x - 1] != '1' && as->tab[y][x] == 'P')
		as->tab[y][x - 1] = 'P';
	if (as->tab[y][x + 1] != '1' && as->tab[y][x] == 'P')
		as->tab[y][x + 1] = 'P';
	if (as->tab[y + 1][x] != '1' && as->tab[y][x] == 'P')
		as->tab[y + 1][x] = 'P';
	if (as->tab[y - 1][x] != '1' && as->tab[y][x] == 'P')
		as->tab[y - 1][x] = 'P';
	return (0);
}

int	ft_canireach(t_bag *as)
{
	int	y;
	int	x;
	int	check_p;

	ft_putzero(&y, &x, &check_p, &as->r_i);
	while (x++ != -1)
	{
		if (co_ft_canireach(as, x, y) != 1 && as->tab[y][x] == 10)
		{
			y++;
			x = 0;
		}
		if (!as->tab[y] || !as->tab[y + 1])
		{
			if (check_p == ft_nbrp(as->tab))
				break ;
			check_p = ft_nbrp(as->tab);
			if (ft_checkifdone(as->tab, (as->r_i - 10000) / 100) == 1)
				return (co_ft_canireach(as, 0, -1));
			y = 1;
		}
	}
	return (ft_close(as, "\nError \nTout les items ne sont pas atteignables\n"));
}

int	ft_checkifdone(char **gr, int total_e)
{
	int	x;
	int	y;
	int	nbre;

	nbre = 0;
	x = 1;
	y = 1;
	while (gr[y])
	{
		if (gr[y][x] == 'E')
			nbre++;
		if (gr[y][x] == 'C' || (gr[y][x] == 'E' && nbre == total_e))
			return (0);
		x++;
		if (x == (int)ft_strlen(gr[1]))
		{
			y++;
			x = 1;
		}
	}
	return (1);
}

int	ft_nbrp(char **gr)
{
	int	x;
	int	y;
	int	count;

	x = 1;
	y = 1;
	count = 0;
	while (gr[y])
	{
		if (gr[y][x] == 'P')
			count++;
		x++;
		if (x == (int)ft_strlen(gr[1]))
		{
			y++;
			x = 1;
		}
	}
	return (count);
}
