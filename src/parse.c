#include "libft.h"
#include "sudoku.h"
#include <stdlib.h>

static int	valid_char(char c)
{
	return ((c >= '0' && c <= '9') || c == '.');
}

static int	valid_line(char *s)
{
	while (*s)
	{
		if (!(valid_char(*s)))
			return (0);
		s++;
	}
	return (1);
}

char		**file_parse(char *file)
{
	char	**map;
	int		fd;
	int		i;
	char	c;

	if (!(fd = open(file, O_RDONLY)))
		return (0);
	if (!(map = (char **)malloc(sizeof(*map) * (SUDOKU_SIZE + 1))))
		return (0);
	i = -1;
	while (++i < SUDOKU_SIZE)
	{
		c = 0;
		if (!(map[i] = (char*)malloc(sizeof(**map) * (SUDOKU_SIZE + 1))))
			return (0);
		map[i][SUDOKU_SIZE] = 0;
		if (!(read(fd, map[i], SUDOKU_SIZE)) || (!(valid_line(map[i]))))
			return (0);
		if (!(read(fd, &c, 1)) || (c != '\n'))
			return (0);
	}
	map[SUDOKU_SIZE] = 0;
	return (map);
}

int			nofile_parse(int ac, char **av)
{
	int		x;
	int		y;

	x = -1;
	y = 0;
	if (ac == 0 || !av)
		return (0);
	while (av[++y])
	{
		while (av[y][++x])
		{
			if (!(valid_char(av[y][x])))
				return (-1);
			if (x >= SUDOKU_SIZE)
				return (-2);
		}
		if (y >= SUDOKU_SIZE + 1)
			return (-3);
		x = -1;
	}
	return (1);
}
