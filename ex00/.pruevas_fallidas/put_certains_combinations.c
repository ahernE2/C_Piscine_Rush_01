/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_certains_combinations.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejhern <alejhern@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 03:10:40 by alejhern          #+#    #+#             */
/*   Updated: 2024/03/31 05:41:46 by alejhern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	**fill_top_to_bottom(int **board, int top, int bottom, int col)
{
	if (top == 1)
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
	else if (top == 2)
	{
		if (bottom == 1)
		{
			board[0][col] = 3;
			board[3][col] = 4;
		}
		if (bottom == 3)
			board[2][col] = 4;
	}
	else if (top == 3)
	{
		if (bottom == 1)
			board[3][col] = 4;
		if (bottom == 2)
			board[2][col] = 4;
	}
	else if (top == 4 && bottom == 1)
	{
		board[0][col] = 1;
		board[1][col] = 2;
		board[2][col] = 3;
		board[3][col] = 4;
	}
	return (board);
}

int	**fill_bottom_to_top(int **board, int top, int bottom, int col)
{
	return (fill_top_to_bottom(board, bottom, top, col));
}

int	**fill_left_to_right(int **board, int left, int right, int row)
{
	if (left == 1)
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
	else if (left == 2)
	{
		if (right == 1)
		{
			board[row][0] = 3;
			board[row][3] = 4;
		}
		if (right == 3)
			board[row][2] = 4;
	}
	else if (left == 3)
	{
		if (right == 1)
			board[row][3] = 4;
		if (right == 2)
			board[row][2] = 4;
	}
	else if (left == 4 && right == 1)
	{
		board[row][0] = 1;
		board[row][1] = 2;
		board[row][2] = 3;
		board[row][3] = 4;
	}
	return (board);
}

int	**fill_right_to_left(int **board, int left, int right, int row)
{
	return (fill_left_to_right(board, right, left, row));
}
