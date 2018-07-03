/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsarapin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 16:06:25 by vsarapin          #+#    #+#             */
/*   Updated: 2017/12/05 16:41:36 by vsarapin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <string.h>
# include <stdlib.h>

typedef struct	s_tetraminos
{
	char				letter;
	int					x[4];
	int					y[4];
	struct s_tetraminos	*next;
}				t_tetra;

void			free_lst(t_tetra *div_prog);
void			free_square(char **square);
void			ft_putendl(const char *s);
void			ft_putstr(char const *str);
void			ft_putchar(char c);
char			*ft_strsub(char const *s, unsigned int start, size_t len);
int				lets_check_all(char *array);
size_t			ft_strlen(const char *str);
void			result(char *array, t_tetra *div_prog);
char			**try_to_add(char **new_square, t_tetra *div_prog, int size);
int				size (int counter_tetraminos);
int				looking_for_sp(char **new_square, t_tetra *div_prog, int size);
void			change_coordinates(t_tetra *div_prog, int x, int y);
char			**square(char **new_square, int size);
char			*read_write(int fd);
char			**add_tetramino(char **square, t_tetra *div_prog, int size);
char			**del_tetramino(char **square, t_tetra *div_prog, int size);
void			print_square(char **square);
void			make_one_field(t_tetra *temporary, char *array);
int				counter_tetramino(char *array);
t_tetra			*mem_for_tetraminos(char *array);
int				valid(char *array, int j);
int				valid_tetraminos(char *array, int j);

#endif
