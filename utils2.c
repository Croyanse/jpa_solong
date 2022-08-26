/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaterno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 16:47:57 by jpaterno          #+#    #+#             */
/*   Updated: 2022/08/03 16:52:10 by jpaterno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "solong.h"
#include "mlx.h"

int	ft_check_ifsquare(char **tab)
{
	int	i;
	int	x;
	int	size_to_have;

	if (tab[0] == NULL || tab[1] == NULL)
		return (0);
	x = 0;
	i = 0;
	size_to_have = 0;
	while (tab[x])
	{
		while (tab[x][i] && tab[x][i] != 10)
			i++;
		if (size_to_have == 0)
			size_to_have = i;
		else if (size_to_have != i)
			return (0);
		x++;
		i = 0;
	}
	return ((size_to_have * 1000 + x));
}

int	ft_check_ifclosed(char **tab, int size)
{
	int	x;
	int	y;

	y = 0;
	x = 0;
	while (tab[0][x] == '1' && x != size / 1000)
		x++;
	if (tab[0][x] != '1' && x != size / 1000)
		return (0);
	x = 0;
	while (tab[y + 1])
	{
		if (tab[y][0] != '1' || tab[y][(size / 1000) - 1] != '1')
			return (0);
		y++;
	}
	while (tab[(size % 1000) - 1][x] == '1' && x != size / 1000)
		x++;
	if (tab[(size % 1000) - 1][x] != '1' && x != size / 1000)
		return (0);
	return (1);
}

int	ft_close2(t_bag *as, char *text)
{
	int	i;

	i = 0;
	if (as->wall != NULL && text[2] > '0')
		free (as->wall);
	if (as->g != NULL && text[2] > '1')
		free (as->g);
	if (as->item != NULL && text[2] > '2')
		free (as->item);
	if (as->p != NULL && text[2] > '3')
		free (as->p);
	if (as->exit != NULL && text[2] > '4')
		free (as->exit);
	while (as->tab[i] && text[1] != '-')
		free (as->tab[i++]);
	if (as->pp == NULL && text[2] != '-')
		free (as->pp);
	if (as->wi && text[0] != '-')
		mlx_destroy_window (as->sr, as->wi);
	ft_printf("\nGame has been closed properly\n");
	exit (0);
}

int	ft_close(t_bag *as, char *text)
{
	int	i;

	if (text[17] == ':')
		ft_printf("\nExit by red cross");
	else
		ft_printf ("\n%s", text);
	if (text[2] >= '0' && text[2] <= '4')
		ft_close2(as, text);
	i = 0;
	mlx_destroy_image (as->sr, as->exit->g);
	mlx_destroy_image (as->sr, as->wall->g);
	mlx_destroy_image (as->sr, as->g->g);
	mlx_destroy_image (as->sr, as->item->g);
	mlx_destroy_image (as->sr, as->p->g);
	return (ft_close2(as, text));
}

int	ft_check_input(char *input, int n)
{
	int	i;

	i = 0;
	if (n != 2)
	{
		ft_printf("Error \nLe nombre d'arguments n'est pas correcte\n");
		return (0);
	}
	while (input[i])
		i++;
	i--;
	if (input[i - 4] != '/' && input[i - 4] && input[i] == 'r'
		&& input[i - 1] == 'e' && input[i - 2] == 'b' && input[i - 3] == '.')
		return (1);
	ft_printf("Error \n>%s< is not a .ber file\n", input);
	return (0);
}
