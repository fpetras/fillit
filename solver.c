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

static void	empty_square(char *square, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
		square[i++] = '.';
}

static int	place(struct s_solver_ctx *ctx, char letter)
{
	size_t	piece_id;

	(void)ctx;
	piece_id = letter - 'A';
	return (42);
}

static int	comb_solv(struct s_solver_ctx *ctx)
{
	size_t	i;

	empty_square(ctx->square, ctx->square_side * ctx->square_side);
	i = 0;
	while (i < ctx->letter_id)
	{
		if (!place(ctx, ctx->letter_list[i]))
			return (0);
		i++;
	}
	i = 0;
	while (i < ctx->square_side)
	{
		write(1, ctx->square, ctx->square_side);
		write(1, "\n", 1);
		i++;
	}
	return (1);
}

static int	letter_comb(struct s_solver_ctx *ctx)
{
	size_t	i;

	if (ctx->letter_id == ctx->pieces_length)
		return (comb_solv(ctx));
	i = 0;
	while (i < ctx->pieces_length)
	{
		if (letter_not_used(ctx->letter_list, 'A' + i, ctx->letter_id))
		{
			ctx->letter_list[ctx->letter_id] = 'A' + i;
			ctx->letter_id++;
			if (letter_comb(ctx))
				return (1);
			ctx->letter_id--;
		}
		i++;
	}
	return (0);
}

int			solver(char *pieces, size_t n)
{
	struct s_solver_ctx	ctx;

	ctx.pieces = pieces;
	ctx.pieces_length = n;
	ctx.letter_id = 0;
	ctx.square_side = 2; // TODO loop
	letter_comb(&ctx);
	return (42);
}
