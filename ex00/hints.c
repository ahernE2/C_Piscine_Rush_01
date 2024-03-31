/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hints.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejhern <alejhern@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 11:15:22 by alejhern          #+#    #+#             */
/*   Updated: 2024/03/31 12:27:44 by alejhern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#define N 4

void	get_row_hints(int board[N][N], int row_hints[N][2])
{
	int	i;
	int	j;
	int	visible_left;
	int	visible_right;

	i = 0;
	while (i < N)
	{
		visible_left = 0;
		visible_right = 0;
		j = 0;
		while (j < N)
		{
			if (board[i][j] > visible_left)
			{
				visible_left++;
				row_hints[i][0]++;
			}
			if (board[i][N - 1 - j] > visible_right)
			{
				visible_right++;
				row_hints[i][1]++;
			}
			j++;
		}
		i++;
	}
}

void	get_col_hints(int board[N][N], int col_hints[N][2])
{
	int	j;
	int	i;
	int	visible_up;
	int	visible_down;

	j = 0;
	while (j < N)
	{
		visible_up = 0;
		visible_down = 0;
		i = 0;
		while (i < N)
		{
			if (board[i][j] > visible_up)
			{
				visible_up++;
				col_hints[j][0]++;
			}
			if (board[N - 1 - i][j] > visible_down)
			{
				visible_down++;
				col_hints[j][1]++;
			}
			i++;
		}
		j++;
	}
}


void print_hints(int hints[N][2], char dir) {
    char buffer[20]; // Suficiente para almacenar cualquier número entero y caracteres adicionales
    int i = 0;
    int len;

    // Escribir la cadena "Pistas para "
    write(1, "Pistas para ", 12);

    // Escribir el carácter de dirección
    write(1, &dir, 1);

    // Escribir el carácter ':'
    write(1, ": ", 2);

    // Convertir e imprimir cada par de coordenadas
    while (i < N) {
        // Convertir el primer número del par a una cadena
        len = sprintf(buffer, "(%d, ", hints[i][0]);
        write(1, buffer, len);

        // Convertir el segundo número del par a una cadena
        len = sprintf(buffer, "%d) ", hints[i][1]);
        write(1, buffer, len);

        i++;
    }

    // Escribir un salto de línea al final
    write(1, "\n", 1);
}

int main() {
    int board[N][N] = {
        {1, 2, 3, 4},
        {2, 3, 4, 1},
        {3, 4, 1, 2},
        {4, 1, 2, 3}
    }; // Tablero de ejemplo

    int row_hints[N][2] = {0};
    int col_hints[N][2] = {0};

    get_row_hints(board, row_hints);
    get_col_hints(board, col_hints);

    print_hints(row_hints, 'F');
    print_hints(col_hints, 'C');

    return 0;
}
