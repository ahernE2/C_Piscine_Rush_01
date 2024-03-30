/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validators.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sardomin <sardomin@student.42Barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 14:03:09 by sardomin          #+#    #+#             */
/*   Updated: 2024/03/31 00:44:59 by sardomin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void validate_inicial_inputs(int input)
{
	if ((input != 1) && (input != 2) && (input != 3) || (input != 4))
	{
		write(1, 'E', 1);
	}
}

void validate_sums_of_elementss_values(int element1, int element2, int element3, int element4)
{
	int sums;

	sums = element1 + element2 + element3 + element4;

	if (sum != 10)
	{
		write(1, 'E', 1);
	}
}
