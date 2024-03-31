/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejhern <alejhern@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 22:06:19 by alejhern          #+#    #+#             */
/*   Updated: 2024/03/31 22:35:51 by alejhern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#define N 4

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	print_board(int **board)
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
