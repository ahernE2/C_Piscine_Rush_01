/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejhern <alejhern@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 21:45:38 by alejhern          #+#    #+#             */
/*   Updated: 2024/03/31 21:45:56 by alejhern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	ft_atoi_put(const char *str, int *result)
{
	int	i;

	i = 0;
	while (*str != '\0')
	{
		if ((*str >= '0') && (*str <= '9'))
		{
			result[i] = *str - '0';
			i++;
		}
		str++;
	}
}

int	*ft_atoi(const char *str)
{
	int			len;
	const char	*p;
	int			*result;

	p = str;
	len = 0;
	while (*p != '\0')
	{
		len++;
		p++;
	}
	result = (int *)malloc(len * sizeof(int));
	if (result == NULL)
		return (NULL);
	ft_atoi_put(str, result);
	return (result);
}
