#ifndef HEADER_H
#define HEADER_H

#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <fcntl.h>
#include <unistd.h>

int	n_queens();

char	**create_board(int x, int y);
#endif