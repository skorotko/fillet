/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsarapin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 15:41:33 by vsarapin          #+#    #+#             */
/*   Updated: 2017/12/05 15:48:47 by vsarapin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		size(int counter_tetraminos)
{
	int i;
	int min_size_of_square;

	i = counter_tetraminos * 4;
	min_size_of_square = 0;
	while ((min_size_of_square * min_size_of_square) < i)
		min_size_of_square++;
	return (min_size_of_square);
}

void	change_coordinates(t_tetra *div_prog, int x, int y)
{
	int	change_x;
	int change_y;
	int i;

	i = 0;
	change_x = 104;
	change_y = 104;
	while (i < 4)
	{
		if (div_prog->x[i] < change_x)
			change_x = div_prog->x[i];
		if (div_prog->y[i] < change_y)
			change_y = div_prog->y[i];
		i++;
	}
	i = 0;
	while (i < 4)
	{
		div_prog->x[i] = div_prog->x[i] - change_x + x;
		div_prog->y[i] = div_prog->y[i] - change_y + y;
		i++;
	}
}

int		looking_for_sp(char **new_square, t_tetra *div_prog, int size)
{
	int i;
	int x;
	int y;

	i = 0;
	y = 0;
	while (y < size)
	{
		x = 0;
		while (x < size)
		{
			if (div_prog->y[i] < size && div_prog->x[i] < size &&
					new_square[div_prog->y[i]][div_prog->x[i]] == '.')
			{
				i++;
				if (i == 4)
					return (1);
			}
			x++;
		}
		y++;
	}
	return (0);
}

char	**try_to_add(char **new_square, t_tetra *div_prog, int size)
{
	int		x;
	int		y;
	char	**location;

	if (div_prog->next == NULL)
		return (new_square);
	location = NULL;
	y = 0;
	while (y < size)
	{
		x = 0;
		while (x < size)
		{
			change_coordinates(div_prog, x, y);
			if (looking_for_sp(new_square, div_prog, size))
				location = try_to_add(add_tetramino(new_square, div_prog, size),
					div_prog->next, size);
			if (location)
				return (location);
			new_square = del_tetramino(new_square, div_prog, size);
			x++;
		}
		y++;
	}
	return (NULL);
}

void	result(char *array, t_tetra *div_prog)
{
	char	**new_squares;
	char	**res;
	int		i;
	int		j;

	j = 0;
	i = size(counter_tetramino(array));
	new_squares = NULL;
	res = NULL;
	new_squares = square(new_squares, i);
	while (!(res = try_to_add(new_squares, div_prog, i)))
	{
		i++;
		free_square(new_squares);
		new_squares = square(new_squares, i);
	}
	print_square(res);
	free_square(res);
}
