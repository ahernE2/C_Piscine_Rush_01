/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   board.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejhern <alejhern@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 22:10:05 by alejhern          #+#    #+#             */
/*   Updated: 2024/03/31 22:36:59 by alejhern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

#define N 4

void	print_board(int **board);
void	fill_hints(int **board, int *hints);

int	is_valid(int **board, int row, int col, int num)
{
	int	x;

	x = 0;
	while (x < N)
	{
		if (board[row][x] == num || board[x][col] == num)
			return (0);
		x++;
	}
	return (1);
}

int	is_same_pattern(int **board, int *hints_args)
{
	int	hints[N * 4];
	int	i;

	fill_hints(board, hints);
	i = 0;
	while (i < 16)
	{
		if (hints[i] != hints_args[i])
			return (0);
		i++;
	}
	return (1);
}

void	generate_skyscrapers(int **board, int row, int col, int *hints_args)
{
	int	num;

	if (row == N)
	{
		if (is_same_pattern(board, hints_args))
			print_board(board);
		return ;
	}
	if (col == N)
	{
		generate_skyscrapers(board, row + 1, 0, hints_args);
		return ;
	}
	num = 1;
	while (num <= N)
	{
		if (is_valid(board, row, col, num))
		{
			board[row][col] = num;
			generate_skyscrapers(board, row, col + 1, hints_args);
			board[row][col] = 0;
		}
		num++;
	}
}

int	**init_board(int rows, int cols)
{
	int	**board;
	int	i;

	board = (int **)malloc(rows * sizeof(int *));
	if (board == NULL)
		return (NULL);
	i = 0;
	while (i < rows)
	{
		board[i] = (int *)malloc(cols * sizeof(int));
		if (board[i] == NULL)
		{
			while (i > 0)
			{
				free(board[i - 1]);
				i--;
			}
			free(board);
			return (NULL);
		}
		i++;
	}
	return (board);
}
