/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complete_board.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejhern <alejhern@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 06:27:41 by alejhern          #+#    #+#             */
/*   Updated: 2024/03/31 07:58:43 by alejhern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	is_valid(int **board, int row, int col, int num)
{
	int i;
	
	i = 0;
	while (i < 4)
	{
		if (board[row][i] == num || board[i][col] == num)
			return (0);
		i++;
	}
	return (1);
}

int	generate_digit(void)
{
	static int semilla;
	int n;
	
	semilla = 0;
	if (semilla == 0)
	{
		semilla = 1;
		srand(semilla);
	}
	n = ((rand() % 4) + 1);
	return (n);
}

int	**complete_board(int **board)
{
	int **tmp_board;
	int	row;
	int	col;
	int	n;

	tmp_board = board;
	row = 0;
	while (row < 4)
	{
		col = 0;
		while (col < 4)
		{
			if(tmp_board[row][col] == 0)
			{
				n = generate_digit();
				if (is_valid(tmp_board, row, col, n) == 1)
					tmp_board[row][col] = generate_digit();
				else
					col--;
			}
			col++;
		}
		row++;
	}

	board = tmp_board;
	return (board);
}
