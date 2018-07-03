/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ReadWrite.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsarapin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 15:38:17 by vsarapin          #+#    #+#             */
/*   Updated: 2017/12/05 15:38:52 by vsarapin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	*read_write(int fd)
{
	int		i;
	int		j;
	char	buf;
	char	*array;

	i = 0;
	array = NULL;
	j = read(fd, &buf, 1);
	if (j < 0)
		return (NULL);
	if (j == 1)
	{
		array = (char *)malloc(sizeof(char) * 600);
		while (j != '\0')
		{
			array[i] = buf;
			i++;
			j = read(fd, &buf, 1);
		}
		array[i] = '\0';
	}
	return (array);
}
