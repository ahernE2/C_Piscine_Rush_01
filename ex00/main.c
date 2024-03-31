/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejhern <alejhern@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 21:47:19 by alejhern          #+#    #+#             */
/*   Updated: 2024/03/31 22:21:31 by alejhern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#define N 4

int		*ft_atoi(const char *argv);
void	generate_skyscrapers(int **board, int row, int col, int *hints_args);
int		**init_board(int rows, int cols);

int	main(int argc, char **argv)
{
	int	**board;
	int	*hints_args;
	int	i;

	if (argc != 2)
		return (1);
	board = init_board(N, N);
	if (board == NULL)
		return (EXIT_FAILURE);
	hints_args = ft_atoi(argv[1]);
	if (hints_args == NULL)
		return (EXIT_FAILURE);
	generate_skyscrapers(board, 0, 0, hints_args);
	i = 0;
	while (i < N)
	{
		free(board[i]);
		i++;
	}
	free(board);
	return (0);
}
