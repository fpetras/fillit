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

static int	comb_solv(struct s_solver_ctx *ctx)
{
	write(1, ctx->letter_list, ctx->letter_id);
	write(1, "\n", 1);
	return (42);
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
			letter_comb(ctx);
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
	ctx.square_length = 2;
	letter_comb(&ctx);
	return (42);
}
