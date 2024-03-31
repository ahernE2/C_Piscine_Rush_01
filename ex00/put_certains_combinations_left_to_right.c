/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_certains_combinations_left_to_right.c          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejhern <alejhern@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 06:00:56 by alejhern          #+#    #+#             */
/*   Updated: 2024/03/31 06:03:08 by alejhern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	fill_left_to_right_case_1(int **board, int right, int row)
{
	board[row][0] = 4;
	if (right == 2)
		board[row][3] = 3;
	if (right == 4)
	{
		board[row][1] = 3;
		board[row][2] = 2;
		board[row][3] = 1;
	}
}

void	fill_left_to_right_case_2(int **board, int right, int row)
{
	if (right == 1)
	{
		board[row][0] = 3;
		board[row][3] = 4;
	}
	if (right == 3)
		board[row][2] = 4;
}

void	fill_left_to_right_case_3(int **board, int right, int row)
{
	if (right == 1)
		board[row][3] = 4;
	if (right == 2)
		board[row][2] = 4;
}

void	fill_left_to_right_case_4(int **board, int row)
{
	board[row][0] = 1;
	board[row][1] = 2;
	board[row][2] = 3;
	board[row][3] = 4;
}

int	**fill_left_to_right(int **board, int left, int right, int row)
{
	if (left == 1)
		fill_left_to_right_case_1(board, right, row);
	else if (left == 2)
		fill_left_to_right_case_2(board, right, row);
	else if (left == 3)
		fill_left_to_right_case_3(board, right, row);
	else if (left == 4 && right == 1)
		fill_left_to_right_case_4(board, row);
	return (board);
}
