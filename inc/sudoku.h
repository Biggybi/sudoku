#ifndef _SUDOKU_H_
# define _SUDOKU_H_

#include "libft.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>

#define SUDOKU_SIZE 9
#define SUDOKU_SQUARE ft_sqrt(SUDOKU_SIZE)
#define REPEAT 0

char	**parse(char *file);
int		sudoku(char **map, int one);

#endif
