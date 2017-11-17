/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpetras <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 10:40:33 by fpetras           #+#    #+#             */
/*   Updated: 2017/11/15 10:41:15 by fpetras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <fcntl.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

int					reader(char *filename);
int					checker(const char *piece);
int					solver(char *pieces, size_t n);

struct				s_solver_ctx
{
	char			*pieces;
	size_t			pieces_length;
	char			letter_list[26];
	size_t			letter_id;
	char			square[4 * 26 * 4 * 26];
	size_t			square_side;
};

int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				ft_putstr(const char *str);
size_t				ft_strlen(const char *str);

#endif
