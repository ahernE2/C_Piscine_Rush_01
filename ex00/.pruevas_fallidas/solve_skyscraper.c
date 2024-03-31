/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_skyscraper.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejhern <alejhern@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 08:06:17 by alejhern          #+#    #+#             */
/*   Updated: 2024/03/31 12:34:12 by alejhern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define N 4 // Tamaño del tablero (NxN)

// Verifica si es seguro colocar 'num' en la posición (row, col)
int is_valid(int board[N][N], int row, int col, int num) {
    // Verifica si 'num' ya está presente en la fila o la columna
    for (int x = 0; x < N; x++) {
        if (board[row][x] == num || board[x][col] == num) {
            return 0; // No válido
        }
    }
    return 1; // Válido
}

// Verifica si todas las celdas del tablero están llenas
int is_board_full(int board[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (board[i][j] == 0) {
                return 0; // Todavía hay celdas vacías
            }
        }
    }
    return 1; // Todas las celdas están llenas
}

// Encuentra la próxima celda vacía en el tablero
int find_empty_location(int board[N][N], int *row, int *col) {
    for (*row = 0; *row < N; (*row)++) {
        for (*col = 0; *col < N; (*col)++) {
            if (board[*row][*col] == 0) {
                return 1; // Celda vacía encontrada
            }
        }
    }
    return 0; // No hay celdas vacías
}

// Verifica si un número ya está en la fila o columna especificada
int used_in_row_or_col(int board[N][N], int row, int col, int num) {
    for (int i = 0; i < N; i++) {
        if (board[row][i] == num || board[i][col] == num) {
            return 1; // Número ya usado en la fila o columna
        }
    }
    return 0; // Número no usado en la fila o columna
}

// Verifica si el número se puede colocar en la celda sin romper las reglas
int is_safe_to_place(int board[N][N], int row, int col, int num) {
    return !used_in_row_or_col(board, row, col, num);
}

// Verifica si el número se puede colocar en la celda sin romper las reglas de visibilidad
int is_safe_to_place_skyscraper(int board[N][N], int row, int col, int num, int left[N], int right[N], int top[N], int bottom[N]) {
    int count_left = 0, count_right = 0, count_top = 0, count_bottom = 0;

    // Calcular visibilidad desde la izquierda
    for (int i = 0; i < col; i++) {
        if (board[row][i] > count_left) {
            count_left = board[row][i];
        }
    }

    // Calcular visibilidad desde la derecha
    for (int i = col + 1; i < N; i++) {
        if (board[row][i] > count_right) {
            count_right = board[row][i];
        }
    }

    // Calcular visibilidad desde arriba
    for (int i = 0; i < row; i++) {
        if (board[i][col] > count_top) {
            count_top = board[i][col];
        }
    }

    // Calcular visibilidad desde abajo
    for (int i = row + 1; i < N; i++) {
        if (board[i][col] > count_bottom) {
            count_bottom = board[i][col];
        }
    }

    return (count_left == left[row] && count_right == right[row] &&
            count_top == top[col] && count_bottom == bottom[col]);
}

// Función de resolución recursiva del juego Skyscrapers
int solve_skyscrapers(int board[N][N], int left[N], int right[N], int top[N], int bottom[N]) {
    int row, col;

    // Si no hay celdas vacías, el tablero está completo
    if (!find_empty_location(board, &row, &col)) {
        return 1;
    }

    // Intentar colocar números del 1 al N en la celda vacía
    for (int num = 1; num <= N; num++) {
        if (is_safe_to_place(board, row, col, num) && is_safe_to_place_skyscraper(board, row, col, num, left, right, top, bottom)) {
            board[row][col] = num;

            // Si se puede completar el tablero con esta asignación, regresa verdadero
            if (solve_skyscrapers(board, left, right, top, bottom)) {
                return 1;
            }

            // Si no se puede completar el tablero con esta asignación, retrocede y prueba otra opción
            board[row][col] = 0;
        }
    }

    // Si no se puede completar el tablero con ninguna asignación, regresa falso
    return 0;
}

