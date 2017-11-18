/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emartine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 18:35:15 by emartine          #+#    #+#             */
/*   Updated: 2017/11/18 08:45:03 by fpetras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int ac, char **av)
{
	if (ac != 2)
	{
		ft_putstr("usage: ");
		ft_putstr(av[0]);
		ft_putstr(" <pieces.fillit>\n");
	}
	else
		reader(av[1]);
	return (0);
}
