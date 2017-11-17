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

#include <stdio.h>
static void	copy_piece(struct s_solver_ctx *ctx, char letter, size_t square_pos)
{
	size_t	piece_start;
	size_t	i;
	size_t tmp = 0;

	piece_start = (letter - 'A') * 16;
	i = 0;
	while (i < 16)
	{
		if (ctx->pieces[piece_start + i] == '#')
		{
			tmp++;
			ctx->square[square_pos + i / 4 * ctx->square_side + i % 4] = letter;
		}
		i++;
	}
	//printf("===== copied %lu\n", tmp);
	//fflush(stdout);
}

static int	place(struct s_solver_ctx *ctx, char letter)
{
	size_t	square_pos;
	size_t	piece_id;
	size_t	piece_pos;

	square_pos = 0;
	piece_id = letter - 'A';
	while (square_pos < ctx->square_side * ctx->square_side)
	{
		//printf("[begin piece %c on pos %lu]\n", letter, square_pos);
		//fflush(stdout);
		piece_pos = 0;
		while (piece_pos < 16)
		{
			if (ctx->pieces[piece_id * 16 + piece_pos] == '#')
			{
				//printf("[sqside=%lu x=%lu y=%lu sqpos=%lu ppos=%lu]\n", ctx->square_side, square_pos % ctx->square_side + piece_pos % 4, square_pos / ctx->square_side + piece_pos / 4, square_pos, piece_pos);
				//fflush(stdout);
				if (square_pos % ctx->square_side + piece_pos % 4 >= ctx->square_side
						|| square_pos / ctx->square_side + piece_pos / 4 >= ctx->square_side
						|| ctx->square[square_pos + piece_pos / 4 *
						ctx->square_side + piece_pos % 4 ] != '.')
				{
					break ;
				}
			}
			piece_pos++;
		}
		if (piece_pos == 16)
		{
			//printf("------------ [copy piece %c on pos %lu]\n", letter, square_pos);
			//fflush(stdout);
			copy_piece(ctx, letter, square_pos);
			return (1);
		}
	square_pos++;
	}
	return (0);
}

static int	comb_solv(struct s_solver_ctx *ctx)
{
	size_t	i;

	empty_square(ctx->square, ctx->square_side * ctx->square_side);
	//printf("------------------------- {%.*s} -----------------\n", (int)ctx->letter_id, ctx->letter_list);
	//fflush(stdout);
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
		write(1, ctx->square + i * ctx->square_side, ctx->square_side);
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
	size_t				i;

	ctx.pieces = pieces;
	ctx.pieces_length = n;
	ctx.letter_id = 0;
	i = 2;
	while (1)
	{
		ctx.square_side = i++;
		if(letter_comb(&ctx))
			break ;
	}
	return (42);
}
