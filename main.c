/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsarapin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 15:41:06 by vsarapin          #+#    #+#             */
/*   Updated: 2017/12/05 16:55:32 by vsarapin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	free_square(char **square)
{
	int i;

	i = 0;
	while (square[i])
	{
		free(square[i]);
		i++;
	}
	free(square);
	square = NULL;
}

void	free_lst(t_tetra *div_prog)
{
	t_tetra *tmp;

	while (div_prog != NULL)
	{
		tmp = div_prog->next;
		free(div_prog);
		div_prog = tmp;
	}
}

int		main(int argc, char **argv)
{
	char	*array;
	int		fd;
	int		i;
	t_tetra	*div_prog;

	i = 0;
	if (argc != 2)
	{
		ft_putstr("usage fillit <file>\n");
		return (1);
	}
	fd = open(argv[1], O_RDONLY);
	array = read_write(fd);
	if (!array || !lets_check_all(array) || counter_tetramino(array) > 26)
	{
		ft_putstr("error\n");
		return (0);
	}
	close(fd);
	div_prog = mem_for_tetraminos(array);
	result(array, div_prog);
	free_lst(div_prog);
	free(array);
	return (0);
}
