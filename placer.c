/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   placer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpetras <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/18 09:29:20 by fpetras           #+#    #+#             */
/*   Updated: 2017/11/18 10:24:35 by fpetras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

#define SQ	square
#define SP	square_pos
#define SS	square_side
#define PP	piece_pos

static void	copy_piece(t_solver_ctx *ctx, char letter, size_t square_pos)
{
	size_t	i;
	size_t	tmp;
	size_t	piece_start;

	i = 0;
	tmp = 0;
	piece_start = (letter - 'A') * 16;
	while (i < 16)
	{
		if (ctx->pieces[piece_start + i] == '#')
		{
			tmp++;
			ctx->square[square_pos + i / 4 * ctx->square_side + i % 4] = letter;
		}
		i++;
	}
}

int			place(t_solver_ctx *ctx, char letter)
{
	size_t	square_pos;
	size_t	piece_id;
	size_t	piece_pos;

	square_pos = 0;
	piece_id = letter - 'A';
	while (square_pos < ctx->square_side * ctx->square_side)
	{
		piece_pos = 0;
		while (piece_pos < 16)
		{
			if (ctx->pieces[piece_id * 16 + piece_pos] == '#')
				if (SP % ctx->SS + PP % 4 >= ctx->SS || SP / ctx->SS + PP / 4
				>= ctx->SS || ctx->SQ[SP + PP / 4 * ctx->SS + PP % 4] != '.')
					break ;
			piece_pos++;
		}
		if (piece_pos == 16)
		{
			copy_piece(ctx, letter, square_pos);
			return (1);
		}
		square_pos++;
	}
	return (0);
}
