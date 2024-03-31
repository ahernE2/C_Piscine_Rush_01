/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejhern <alejhern@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 01:56:00 by alejhern          #+#    #+#             */
/*   Updated: 2024/03/31 12:39:00 by alejhern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

int	**fill_top_to_bottom(int **board, int top, int bottom, int col);
int	**fill_bottom_to_top(int **board, int top, int bottom, int col);
int	**fill_left_to_right(int **board, int left, int right, int row);
int	**fill_right_to_left(int **board, int left, int right, int row);
int solve_skyscrapers(int** board, int* left, int* right, int* top, int* bottom);

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void print_board(int **board)
{
    int row;
    int col;
    char num_char;

	row = 0;
    while (row < 4)
    {
        col = 0;
        while (col < 4)
        {
            num_char = board[row][col] + '0';
            ft_putchar(num_char);
            if (col < 3)
				ft_putchar(' ');
			col++;
        }
        ft_putchar('\n');
        row++;
    }
}

int	**generate_board(void)
{
	int	**board;
	int	i;

	board = (int **)malloc(4 * sizeof(int *));
	if (!board)
		return (NULL);
	i = 0;
	while (i < 4)
	{
		board[i] = (int *)malloc(4 * sizeof(int));
		if (!board[i])
			return (NULL);
		i++;
	}
	return (board);
}


int main() {

    // Matriz vacía para el tablero
    int **board;
	int row;
	int col;
    // Arrays de pistas para los lados izquierdo, derecho, superior e inferior
   	int	top[4] = {4, 3, 2, 1};
	int	bottom[4] = {1, 2, 2, 2};
	int	left[4] = {4, 3, 2, 1};
	int	right[4] = {1, 2, 2, 2};
	
	board = generate_board();
	row = 0;
	while (row < 4)
	{
		col = 0;
		while (col < 4)
		{
			board = fill_top_to_bottom(board, top[col], bottom[col], col);
			//board = fill_bottom_to_top(board, top[j], bottom[j]);
			board = fill_left_to_right(board, left[row], right[row], row);
			//board = fill_right_to_left(board, left[i], right[i]);
			write(1, "Tablero después de llenar con (", 32);
			ft_putchar(top[col] + '0');
			write(1, ", ", 2);
			ft_putchar(bottom[col] + '0');
			write(1, ", ", 2);
			ft_putchar(left[row] + '0');
			write(1, ", ", 2);
			ft_putchar(right[row] + '0');
			write(1, "):\n", 3);
			print_board(board);
			write(1, "\n", 1);
			col++;
		}
		row++;
	}
	if(solve_skyscrapers(board, left, right, top, bottom))
	{
		write(1, "Tablero después de completar", 32);
		ft_putchar('\n');
		print_board(board);
	}
	else
		write(1, "Error\n", 6);
	return 0;
}

