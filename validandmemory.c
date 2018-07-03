/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ValidAndMemory.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsarapin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 15:40:42 by vsarapin          #+#    #+#             */
/*   Updated: 2017/12/05 18:41:38 by vsarapin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			counter_tetramino(char *array)
{
	int		i;
	int		j;

	j = 0;
	i = 0;
	while (array[i] != '\0')
	{
		if (array[i] == '#')
			j++;
		i++;
	}
	return (j / 4);
}

t_tetra		*mem_for_tetraminos(char *array)
{
	int		count_tetras;
	int		add_num;
	char	letter;
	t_tetra *mem;
	t_tetra *temporary;

	add_num = 0;
	letter = 'A';
	count_tetras = counter_tetramino(array);
	if (!(mem = (t_tetra *)malloc(sizeof(t_tetra))))
		return (NULL);
	temporary = mem;
	while (count_tetras > 0)
	{
		mem->letter = letter;
		make_one_field(mem, ft_strsub(array, add_num, 20));
		if (!(mem->next = (t_tetra *)malloc(sizeof(t_tetra))))
			return (NULL);
		mem = mem->next;
		count_tetras--;
		letter++;
		add_num += 21;
	}
	mem->next = NULL;
	return (temporary);
}

int			valid(char *array, int j)
{
	int counter_diez;
	int dots;
	int new_line;
	int i;

	dots = 0;
	i = 0;
	new_line = 0;
	counter_diez = 0;
	while (array[i] != '\0' && i + j < 20 + j)
	{
		if (array[i] == '#')
			counter_diez++;
		if (array[i] == '.')
			dots++;
		if (array[i] == '\n')
			new_line++;
		i++;
	}
	if (counter_diez == 4 && new_line == 4 && dots == 12)
		return (1);
	return (0);
}

int			valid_tetraminos(char *array, int j)
{
	int i;
	int counter_diez;

	i = 0;
	counter_diez = 0;
	while (i + j < 20 + j)
	{
		if (array[i + j] == '#')
		{
			if (array[i + j + 1] == '#' && (i + j + 1) <= (20 + j))
				counter_diez++;
			if (array[i + j - 1] == '#' && (i + j - 1) >= (0 + j))
				counter_diez++;
			if (array[i + j + 5] == '#' && (i + j + 5) <= (20 + j))
				counter_diez++;
			if (array[i + j - 5] == '#' && (i + j - 5) >= (0 + j))
				counter_diez++;
		}
		i++;
	}
	if (counter_diez == 6 || counter_diez == 8)
		return (1);
	return (0);
}

int			lets_check_all(char *array)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (array[i + j] != '\0')
	{
		if (!(valid(array, j) && valid_tetraminos(array, j)))
			return (0);
		i = 19;
		if (array[i + j] == '\n' && array[i + j + 1] == '\0')
			return (1);
		if (array[i + j] == '\n' && array[i + j + 1] == '\n'
				&& (array[i + j + 2] == '.' || array[i + j + 2] == '#'))
			j += 21;
		else
			return (0);
		i = 0;
	}
	return (1);
}
