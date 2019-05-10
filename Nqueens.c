#include "header.h"

# define N 8

void print_board(int **board, int x, int y)
{
	int i = -1;
	int j;
	printf("\n");
	while (++i < x)
	{
		j = -1;
		while(++j < y)
			printf(" %d ",board[i][j]);
		printf("\n\n");
	}
}

int is_attacked(int col,int row, int **board)
{
	int i,j;
	i = -1;
	if (col >= N)
		return 1;
	while  (++i < col)
		if (board[row][i])
			return (1);
	i = row;
	j = col;
	while (j >= 0 && i >=0)
		if (board[i--][j--])
			return (1); 
	i = row - 1;
	j = col + 1;
	while (--j >= 0 && ++i < N)
		if (board[i][j])
			return (1);
	return (0);
}

int solver(int col,int **board)
{
	int i;
	i = -1;

	if (col >= N)
		return (1);
	while (++i < N)
	{
		if (!is_attacked(col,i,board))
		{
			board[i][col] = 1;
			if (solver(col + 1, board))
				return (1);
			board[i][col] = 0;
		}
	}
	return (0);
}

int **creat_board(int x, int y)
{
	int i;
	int j;
	i = -1;
	j = -1;
	int **borad = (int **)malloc(sizeof(int *) * y);
	while (++i < x)
	{
		borad[i] = malloc(sizeof(int) * x);
		memset(borad[i],0,x * sizeof(int));
	}
	return (borad);
}

void free_board(int **board)
{
	int i = -1;

	while (++i < N)
	{
		free(board[i]);
	}
	free(board);
}

int main()
{
	int **board = creat_board(N,N);
	if (solver(0,board) == 0)
		printf("Soultion not Found ! ! \n");
	print_board(board,N,N);
	free_board(board);
	return 0;
}
