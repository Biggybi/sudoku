#include "libft.h"
#include "sudoku.h"

int		can_put(char **map, int y, int x, int numbers)
{
	int		i;
	int		j;

	i = -1;
	while (++i < SUDOKU_SIZE)
		if (map[y][i] == numbers || map[i][x] == numbers)
			return (0);
	i = -1;
	while (++i < SUDOKU_SQUARE)
	{
		j = -1;
		while (++j < SUDOKU_SQUARE)
			if (map[y - (y % SUDOKU_SQUARE) + j][x - (x % SUDOKU_SQUARE) + i] == numbers)
				return (0);
	}
	return (1);
}

int		sudoku(char **map, int one)
{
	int			x;
	int			y;
	char		numbers;
	static int	solutions = 0;

	y = -1;
	while (++y < SUDOKU_SIZE)
	{
		x = -1;
		while (++x < SUDOKU_SIZE)
			if (map[y][x] == '.')
			{
				numbers = '0';
				while (++numbers < '0' + SUDOKU_SIZE + 1)
					if (can_put(map, y, x, numbers))
					{
						map[y][x] = numbers;
						sudoku(map, one);
						map[y][x] = '.';
					}
				return (solutions);
			}
	}
	ft_putendl("");
	ft_putstrtab(map);
	ft_putendl("");
	solutions++;
	return (solutions);
}
