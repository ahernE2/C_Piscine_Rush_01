/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   skycrapers_force.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejhern <alejhern@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 11:12:31 by alejhern          #+#    #+#             */
/*   Updated: 2024/03/31 16:07:54 by alejhern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#define N 4 // Tamaño del tablero (NxN)

void	print_board(int board[N][N]);
void	get_row_hints(int board[N][N], int row_hints[N][2]);
int	*conversion_argv_to_int_arr(int **argv)

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	print_board(int board[N][N])
{
	int		i;
	int		j;
	char	num_char;

	i = 0;
	while (i < N)
	{
		j = 0;
		while (j < N)
		{
			num_char = board[i][j] + '0';
			ft_putchar(num_char);
			if (j < N - 1)
				ft_putchar(' ');
			j++;
		}
		ft_putchar('\n');
		i++;
	}
	ft_putchar('\n');
}

int	is_valid(int board[N][N], int row, int col, int num)
{
	int	x;

	x = 0;
	while (x < N)
	{
		if (board[row][x] == num || board[x][col] == num)
		{
			return (0);
		}
		x++;
	}
	return (1);
}

void	generate_skyscrapers(int board[N][N], int row, int col)
{
	int	num;

	if (row == N)
	{
		print_board(board);
		return ;
	}
	if (col == N)
	{
		generate_skyscrapers(board, row + 1, 0);
		return ;
	}
	num = 1;
	while (num <= N)
	{
		if (is_valid(board, row, col, num))
		{
			board[row][col] = num;
			generate_skyscrapers(board, row, col + 1);
			board[row][col] = 0;
		}
		num++;
	}
}

int	main(int argc, char ** argv)
{
	int	board[N][N];
	int *hints;
	int i;

	hints = conversion_argv_to_int_arr(argv[2][0]);

	generate_skyscrapers(board, 0, 0);
	return (0);
}
