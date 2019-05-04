#include "header.h"


char	**create_board(int x, int y)
{
	int i,j;
	char **board = malloc(sizeof(char **) * x);
	for(i=1;i<=x;i++)
    {
		board[i] = malloc(sizeof(char *) * y);
        for(j=1;j<=y;j++)
        {
            board[i][j] = 1;
        }
        printf("\n");
    }
	return (board);
}

void print_board(char **board, int x, int y)
{
	int i , j = 0;
	while (i <= x)
	{
		while(j <= y){
			printf("%c \n",board[i][j]);
			j++;
		}
		i++;
	}
}

int	n_queens()
{
	int x = 4;
	int y = 4;
	int i , j = 0;
	char **board = create_board(x,y);
	while (i < x)
	{
		while(j < y){
			board[i][j] = 1;
			j++;
		}
		i++;
	}
	printf("%d \n",board[1][1]);
	//print_board(board,x,y);
	return 0;
}
