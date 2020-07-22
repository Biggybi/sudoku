#include "sudoku.h"
#include "libft.h"

int main(int ac, char *av[])
{
	int		file_n;
	char	**map;
	int		solutions;

	file_n = 0;
	ft_putnbr(SUDOKU_SQUARE);
	ft_putendl("");
	while (file_n++ < ac - 1)
	{
		if (!(map = file_parse(av[file_n])))
		{
			ft_putendl("Invalid map");
			return (1);
		}
		/* ft_putstrtab(map = sudoku(map)); */
		solutions = sudoku(map, 0);
		ft_putstr("solutions :");
		ft_putnbr(solutions);
		ft_putendl("");
		ft_putstrtab(map);
	}
	return (0);
}
