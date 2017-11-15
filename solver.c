/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emartine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 19:05:42 by emartine          #+#    #+#             */
/*   Updated: 2017/11/14 19:05:44 by emartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	letter_not_used(const char *letter_list, const char letter,
		const size_t id)
{
	size_t	i;

	i = 0;
	while (i < id)
	{
		if (letter_list[i] == letter)
			return (0);
		i++;
	}
	return (1);
}

static int	letter_comb(const char *pieces, const size_t n, const size_t id,
		char *letter_list)
{
	size_t	i;

	(void)pieces;
	if (id == n)
	{
		write(1, letter_list, id);
		write(1, "\n", 1);
		return (1);
	}
	i = 0;
	while (i < n)
	{
		if (letter_not_used(letter_list, 'A' + i, id))
		{
			letter_list[id] = 'A' + i;
			letter_comb(pieces, n, id + 1, letter_list);
		}
		i++;
	}
	return (0);
}

int			solver(const char *pieces, const size_t n)
{
	size_t	square_length;
	char	square[4 * 26 * 4 * 26];
	char	foo[26];

	square_length = 2;
	(void)square;
	(void)pieces;
	letter_comb(pieces, n, 0, foo);
	return (42);
}
