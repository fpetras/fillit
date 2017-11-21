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

void		the_federation(struct s_solver_ctx *ctx, int piece_id,
		int square_pos)
{
	int	piece_start;
	int	i;

	piece_start = piece_id * 16;
	i = 0;
	while (i < 16)
	{
		if (ctx->pieces[piece_start + i] == '#')
			ctx->square[square_pos + i / 4 * ctx->square_side + i % 4] = 'A'
				+ piece_id;
		i++;
	}
}

void		the_alliance(struct s_solver_ctx *ctx, int piece_id, int square_pos)
{
	int	piece_start;
	int	i;

	piece_start = piece_id * 16;
	i = 0;
	while (i < 16)
	{
		if (ctx->pieces[piece_start + i] == '#')
			ctx->square[square_pos + i / 4 * ctx->square_side + i % 4] = '.';
		i++;
	}
}

int			the_assembly(struct s_solver_ctx *ctx, int piece_id, int square_pos)
{
	int piece_pos;

	piece_pos = 0;
	while (piece_pos < 16)
	{
		if (ctx->pieces[piece_id * 16 + piece_pos] == '#')
		{
			if (square_pos % ctx->square_side + piece_pos % 4 >=
				ctx->square_side || square_pos / ctx->square_side +
				piece_pos / 4 >= ctx->square_side || ctx->square[square_pos +
				piece_pos / 4 * ctx->square_side + piece_pos % 4] != '.')
				return (0);
		}
		piece_pos++;
	}
	the_federation(ctx, piece_id, square_pos);
	return (1);
}

int			the_order(struct s_solver_ctx *ctx, int piece_id)
{
	int	i;

	if (piece_id == ctx->pieces_length)
	{
		i = 0;
		while (i < ctx->square_side)
		{
			write(1, ctx->square + i * ctx->square_side, ctx->square_side);
			write(1, "\n", 1);
			i++;
		}
		return (1);
	}
	i = 0;
	while (i < ctx->square_tiles)
	{
		if (the_assembly(ctx, piece_id, i))
		{
			if (the_order(ctx, piece_id + 1))
				return (1);
			the_alliance(ctx, piece_id, i);
		}
		i++;
	}
	return (0);
}

int			solver(char *pieces, size_t n)
{
	struct s_solver_ctx	ctx;
	int					i;
	int					j;

	ctx.pieces = pieces;
	ctx.pieces_length = n;
	i = 2;
	while (1)
	{
		ctx.square_side = i;
		ctx.square_tiles = i * i;
		j = 0;
		while (j < ctx.square_tiles)
			ctx.square[j++] = '.';
		if (the_order(&ctx, 0))
			break ;
		i++;
	}
	return (42);
}
