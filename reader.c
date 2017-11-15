/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emartine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 19:05:37 by emartine          #+#    #+#             */
/*   Updated: 2017/11/14 19:05:39 by emartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	print_error(void)
{
	ft_putstr("error\n");
	return (42);
}

/*
** Piece vertical copy (to left)
*/

static int	p_cpy(char *dst, char *src, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		dst[i + 0] = src[i + 0];
		dst[i + 4] = src[i + 4];
		dst[i + 8] = src[i + 8];
		dst[i + 12] = src[i + 12];
		i++;
	}
	return (42);
}

static char	*piece_corner(char *p)
{
	if (p[0] == '.' && p[1] == '.' && p[2] == '.' && p[3] == '.')
	{
		if (p[4] == '.' && p[5] == '.' && p[6] == '.' && p[7] == '.')
		{
			if (p[8] == '.' && p[9] == '.' && p[10] == '.' && p[11] == '.')
				ft_memcpy(p, p + 12, 4) && ft_memcpy(p + 4, "............", 12);
			else
				ft_memcpy(p, p + 8, 8) && ft_memcpy(p + 8, "........", 8);
		}
		else
			ft_memcpy(p, p + 4, 12) && ft_memcpy(p + 12, "....", 4);
	}
	if (p[0] == '.' && p[4] == '.' && p[8] == '.' && p[12] == '.')
	{
		if (p[1] == '.' && p[5] == '.' && p[9] == '.' && p[13] == '.')
		{
			if (p[2] == '.' && p[6] == '.' && p[10] == '.' && p[14] == '.')
				p_cpy(p, p + 3, 1) && p_cpy(p + 1, "...............", 3);
			else
				p_cpy(p, p + 2, 2) && p_cpy(p + 2, "..............", 2);
		}
		else
			p_cpy(p, p + 1, 3) && p_cpy(p + 3, ".............", 1);
	}
	return (p);
}

static int	valid(char *pieces, char *buffer, size_t buffer_length)
{
	size_t	i;
	size_t	n;

	if (buffer_length == 546)
		return (0);
	n = (buffer_length + 1) / (16 + 5);
	if (n * (16 + 5) - 1 != buffer_length)
		return (0);
	i = 0;
	while (i < n)
	{
		if (buffer[4] != '\n' || buffer[9] != '\n' || buffer[14] != '\n'
				|| buffer[19] != '\n' || (i < n - 1 && buffer[20] != '\n'))
			return (0);
		ft_memcpy(pieces, buffer, 4);
		ft_memcpy(pieces + 4, buffer + 5, 4);
		ft_memcpy(pieces + 8, buffer + 10, 4);
		ft_memcpy(pieces + 12, buffer + 15, 4);
		if (!checker(piece_corner(pieces)))
			return (0);
		pieces += 16;
		buffer += 16 + 5;
		i++;
	}
	return (1);
}

int			reader(char *filename)
{
	int		fd;
	size_t	buffer_length;
	int		r;
	char	pieces[416];
	char	buffer[546];

	if ((fd = open(filename, O_RDONLY)) < 0)
		return (print_error());
	buffer_length = 0;
	while (1)
	{
		r = read(fd, buffer + buffer_length, 546 - buffer_length);
		if (r == -1)
			return (print_error());
		if (r == 0)
			break ;
		buffer_length += r;
	}
	if (!valid(pieces, buffer, buffer_length))
		return (print_error());
	return (42);
}
