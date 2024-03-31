/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejhern <alejhern@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 11:27:30 by alejhern          #+#    #+#             */
/*   Updated: 2024/03/31 18:56:48 by alejhern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int *ft_atoi(const char *str)
{
    // Calculamos la longitud de la cadena
    int len = 0;
    const char *p = str;
    while (*p != '\0')
    {
        len++;
        p++;
    }

    // Reservamos memoria para el nuevo array de enteros
    int *result = (int *)malloc(len * sizeof(int));
    if (result == NULL)
    {
        // Manejo del error si la asignación de memoria falla
        return NULL;
    }

    // Converimos cada carácter de la cadena original a un entero y lo almacenamos en el nuevo array
    int i = 0;
    while (*str != '\0')
    {
        if (*str >= '0' && *str <= '9')
        {
            result[i] = *str - '0'; // Convertimos el carácter a su valor entero
            i++;
        }
        str++;
    }

    return result;
}

