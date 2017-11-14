/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emartine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 19:05:50 by emartine          #+#    #+#             */
/*   Updated: 2017/11/14 19:05:52 by emartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		checker(const char *piece)
{
	return (ft_memcmp(piece, "#...#...#...#...", 16) == 0
		|| ft_memcmp(piece, "####............", 16) == 0
		|| ft_memcmp(piece, "##..##..........", 16) == 0
		|| ft_memcmp(piece, ".##.##..........", 16) == 0
		|| ft_memcmp(piece, "#...##...#......", 16) == 0
		|| ft_memcmp(piece, "##...##.........", 16) == 0
		|| ft_memcmp(piece, ".#..##..#.......", 16) == 0
		|| ft_memcmp(piece, "###..#..........", 16) == 0
		|| ft_memcmp(piece, ".#..##...#......", 16) == 0
		|| ft_memcmp(piece, ".#..###.........", 16) == 0
		|| ft_memcmp(piece, "#...##..#.......", 16) == 0
		|| ft_memcmp(piece, "#...#...##......", 16) == 0
		|| ft_memcmp(piece, "###.#...........", 16) == 0
		|| ft_memcmp(piece, "##...#...#......", 16) == 0
		|| ft_memcmp(piece, "..#.###.........", 16) == 0
		|| ft_memcmp(piece, ".#...#..##......", 16) == 0
		|| ft_memcmp(piece, "#...###.........", 16) == 0
		|| ft_memcmp(piece, "##..#...#.......", 16) == 0
		|| ft_memcmp(piece, "###...#.........", 16) == 0);
}
