/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_certains_combinations_top_to_bottom.c          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejhern <alejhern@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 06:01:27 by alejhern          #+#    #+#             */
/*   Updated: 2024/03/31 06:04:02 by alejhern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	fill_top_to_bottom_case_1(int **board, int bottom, int col)
{
	board[0][col] = 4;
	if (bottom == 2)
		board[3][col] = 3;
	if (bottom == 4)
	{
		board[1][col] = 3;
		board[2][col] = 2;
		board[3][col] = 1;
	}
}

void	fill_top_to_bottom_case_2(int **board, int bottom, int col)
{
	if (bottom == 1)
	{
		board[0][col] = 3;
		board[3][col] = 4;
	}
	if (bottom == 3)
		board[2][col] = 4;
}

void	fill_top_to_bottom_case_3(int **board, int bottom, int col)
{
	if (bottom == 1)
		board[3][col] = 4;
	if (bottom == 2)
		board[2][col] = 4;
}

void	fill_top_to_bottom_case_4(int **board, int col)
{
	board[0][col] = 1;
	board[1][col] = 2;
	board[2][col] = 3;
	board[3][col] = 4;
}

int	**fill_top_to_bottom(int **board, int top, int bottom, int col)
{
	if (top == 1)
		fill_top_to_bottom_case_1(board, bottom, col);
	else if (top == 2)
		fill_top_to_bottom_case_2(board, bottom, col);
	else if (top == 3)
		fill_top_to_bottom_case_3(board, bottom, col);
	else if (top == 4 && bottom == 1)
		fill_top_to_bottom_case_4(board, col);
	return (board);
}
