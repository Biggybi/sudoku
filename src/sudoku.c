#include "sudoku.h"
#include "libft.h"

int main(int ac, char *av[])
{
	int		file_n;
	char	**map;
	int		solutions;

	file_n = 0;
	while (file_n++ < ac - 1)
	{
		if (!(map = parse(av[file_n])))
		{
			ft_putendl("Invalid map");
			return (1);
		}
		solutions = sudoku(map, 0);
		ft_putstr("solutions :");
		ft_putnbr(solutions);
		ft_putendl("");
		ft_putstrtab(map);
		while (*map)
			ft_strdel(map++);
		free(map - SUDOKU_SIZE);
	}
	return (0);
}
