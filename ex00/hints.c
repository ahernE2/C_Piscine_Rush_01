/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hints.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejhern <alejhern@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 11:15:22 by alejhern          #+#    #+#             */
/*   Updated: 2024/03/31 16:52:09 by alejhern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#define N 4

/*void	get_row_hints(int board[N][N], int row_hints[N][2])
{
	int	i;
	int	j;
	int	visible_left;
	int	visible_right;

	i = 0;
	j = 1;
	visible_left = 1;
	visible_right = 0;
	while (i < N)
	{
	//	visible_left = 1;
	//	visible_right = 0;
		printf("0 position: %d\n", visible_left);
		if (board[i][1] > board[i][0])
		{
			visible_left++;
			printf("1nd:  %d \n", visible_left);
			j++;
		}
		if ((board[i][j] > board[i][0]) && (board[i][j] > board[i][j - 1]))
		{
			visible_left++;
			printf("2nd - %d  \n", visible_left);
			j++;
		}
		if ((board[i][j + 1] > board[i][0]) && (board[i][j +1] > board[i][1]) && (board[i][j+1] > board[i][2]))
		{
			visible_left++;
			printf("3rd - %d \n", visible_left);
			row_hints[i][0]++;
		}			
		if	(board[i][N - 1 - j] > visible_right)
		{
			visible_right++;
			row_hints[i][1]++;
		}
		i++;
		j = 1;
	}
}*/

void get_row_hints(int board[N][N], int row_hints[N][2]) {
    int i = 0;
    while (i < N) {
        int visible_left = 0;
        int visible_right = 0;
        int max_height_left = 0;
        int max_height_right = 0;

        int j = 0;
        while (j < N) {
            // Calculamos pistas de visibilidad desde la izquierda
            if (board[i][j] > max_height_left) {
                visible_left++;
                max_height_left = board[i][j];
            }
			// array[8 + i] = visible_left;
			
            // Calculamos pistas de visibilidad desde la derecha
            if (board[i][N - 1 - j] > max_height_right) {
                visible_right++;
                max_height_right = board[i][N - 1 - j];
            }
			// array[13 + i] = visible_right;
            j++;
        }

        // Actualizamos las pistas de la fila
        row_hints[i][0] = visible_left;
        row_hints[i][1] = visible_right;

        i++;
    }
}

void get_col_hints(int board[N][N], int col_hints[N][2]) {
    int j = 0;
    while (j < N) {
        int visible_up = 0;
        int visible_down = 0;
        int max_height_up = 0;
        int max_height_down = 0;

        int i = 0;
        while (i < N) {
            // Calculamos pistas de visibilidad desde arriba
            if (board[i][j] > max_height_up) {
                visible_up++;
                max_height_up = board[i][j];
            }
			// array[i] = visible_up;
	
            // Calculamos pistas de visibilidad desde abajo
            if (board[N - 1 - i][j] > max_height_down) {
                visible_down++;
                max_height_down = board[N - 1 - i][j];
            }

			// array[4 + i] = visible_down;

            i++;
        }

        // Actualizamos las pistas de la columna
        col_hints[j][0] = visible_up;
        col_hints[j][1] = visible_down;

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
        {4, 2, 3, 1},
        {2, 3, 4, 1},
        {3, 4, 1, 2},
        {1, 4, 2, 3}
    }; // Tablero de ejemplo

    int row_hints[N][2] = {0};
    int col_hints[N][2] = {0};

    get_row_hints(board, row_hints);
    get_col_hints(board, col_hints);

    print_hints(row_hints, 'F');
    print_hints(col_hints, 'C');

    return 0;
}
