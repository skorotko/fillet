/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsarapin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 15:40:01 by vsarapin          #+#    #+#             */
/*   Updated: 2017/12/05 19:01:43 by vsarapin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	make_one_field(t_tetra *temporary, char *array)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (array[i])
	{
		if (array[i] == '#')
		{
			temporary->x[j] = i % 5;
			temporary->y[j] = i / 5;
			j++;
		}
		i++;
	}
}

char	**square(char **new_square, int size)
{
	int x;
	int y;

	y = 0;
	if (!(new_square = (char**)malloc(sizeof(char*) * size + 1)))
		return (NULL);
	while (y < size)
	{
		if (!(new_square[y] = (char*)malloc(sizeof(char) * size + 1)))
			return (NULL);
		x = 0;
		while (x < size)
		{
			new_square[y][x] = '.';
			x++;
		}
		new_square[y][x] = '\0';
		y++;
	}
	new_square[y] = 0;
	return (new_square);
}

char	**add_tetramino(char **square, t_tetra *div_prog, int size)
{
	int x;
	int y;
	int i;

	y = 0;
	i = 0;
	while (y < size)
	{
		x = 0;
		while (x < size)
		{
			if (div_prog->y[i] == y && div_prog->x[i] == x)
			{
				square[y][x] = div_prog->letter;
				i++;
			}
			x++;
		}
		y++;
	}
	return (square);
}

char	**del_tetramino(char **square, t_tetra *div_prog, int size)
{
	int x;
	int y;

	y = 0;
	while (y < size)
	{
		x = 0;
		while (x < size)
		{
			if (square[y][x] == div_prog->letter)
				square[y][x] = '.';
			x++;
		}
		y++;
	}
	return (square);
}

void	print_square(char **square)
{
	int i;

	i = 0;
	if (square == NULL)
	{
		ft_putstr("error\n");
		return ;
	}
	while (square[i])
	{
		ft_putendl(square[i]);
		i++;
	}
}
