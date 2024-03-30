/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   condicionantes.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sardomin <sardomin@student.42Barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 23:07:23 by sardomin          #+#    #+#             */
/*   Updated: 2024/03/31 00:42:25 by sardomin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

/* lectura de arriba a abajo, hay que generalizarlo con i para cualquier par de externos por columnas*/
/* caso (1-2) y (1-4)*/
if (col_top[0] == 1)
{
	board[0][0] = 4;
	if(col_down[0] == 2)
	{
		board[3][0] = 3;
	}
	if(col_down[0] == 4)
	{
		board[1][0] = 3;
		board[2][0] = 2;
		board[3][0] = 1;
	}
}

/* caso (2-1) y (2-3)*/
if (col_top[0] == 2)
{
	if(col_down[0] == 1)
	{
		board[0][0] = 3;
		board[3][0] = 4;
	}
	if(col_down[0] == 3)
	{
		board[2][0] = 4;
	}
}
/* caso (3-1) y (3-2)*/
if (col_top[0] == 3)
{
	if(col_down[0] == 1)
	{
		board[3][0] = 4;
	}
	if(col_down[0] == 2)
	{
		board[2][0] = 4;
	}
}
/* caso (4-1)*/
if (top[0] == 4 && bottom[0] == 1)
{
	board[0][0] = 1	
	board[1][0] = 2;
	board[2][0] = 3;
	board[3][0] = 4;
}

/* lectura de abajo a arriba hay que generalizarlo con i para cualquier par de externos por columnas*/
/* caso (1-2) y (1-4)*/
if (bottom[0] == 1)
{
	board[0][0] = 4;
	if(top[0] == 2)
	{
		board[3][0] = 3;
	}
	if(top[0] == 4)
	{
		board[1][0] = 3;
		board[2][0] = 2;
		board[3][0] = 1;
	}
}

/* caso (2-1) y (2-3)*/
if (bottom[0] == 2)
{
	if(top[0] == 1)
	{
		board[0][0] = 3;
		board[3][0] = 4;
	}
	if(top[0] == 3)
	{
		board[2][0] = 4;
	}
}
/* caso (3-1) y (3-2)*/
if (bottom[0] == 3)
{
	if(top[0] == 1)
	{
		board[3][0] = 4;
	}
	if(top[0] == 2)
	{
		board[2][0] = 4;
	}
}
/* caso (4-1)*/
if (bottom[0] == 4 && top[0] == 1)
{
	board[0][0] = 1
	board[1][0] = 2;
	board[2][0] = 3;
	board[3][0] = 4;
}

/* lectura de izquierda a derecha hay que generalizarlo con i para cualquier par de externos por filas*/
/* caso (1-2) y (1-4)*/
if (rowleft[0] == 1)
{
	board[0][0] = 4;
	if(rowright[0] == 2)
	{
		board[0][3] = 3;
	}
	if(rowright[0] == 4)
	{
		board[0][1] = 3;
		board[0][2] = 2;
		board[0][3] = 1;
	}
}

/* caso (2-1) y (2-3)*/
if (rowleft[0] == 2)
{
	if(rowrigth[0] == 1)
	{
		board[0][0] = 3;
		board[3][0] = 4;
	}
	if(rowright[0] == 3)
	{
		board[2][0] = 4;
	}
}
/* caso (3-1) y (3-2)*/
if (rowleft[0] == 3)
{
	if(rowright[0] == 1)
	{
		board[0][3] = 4;
	}
	if(rowright[0] == 2)
	{
		board[0][2] = 4;
	}
}
/* caso (4-1)*/
if (rowleft[0] == 4 && rowright[0] == 1)
{
	board[0][0] = 1;
	board[0][1] = 2;
	board[0][2] = 3;
	board[0][3] = 4;
}

/* lectura de derecha a izquierda, hay que generalizarlo con i para cualquier par de externos por filas*/
/* caso (1-2) y (1-4)*/
if (rowrigh[0] == 1)
{
	board[0][0] = 4;
	if(rowleft[0] == 2)
	{
		board[0][3] = 3;
	}
	if(rowleft[0] == 4)
	{
		board[0][1] = 3;
		board[0][2] = 2;
		board[0][3] = 1;
	}
}

/* caso (2-1) y (2-3)*/
if (rowright[0] == 2)
{
	if(rowleft[0] == 1)
	{
		board[0][0] = 3;
		board[0][3] = 4;
	}
	if(rowleft[0] == 3)
	{
		board[0][2] = 4;
	}
}
/* caso (3-1) y (3-2)*/
if (rowright[0] == 3)
{
	if(bottom[0] == 1)
	{
		board[0][3] = 4;
	}
	if(rowleft[0] == 2)
	{
		board[0][2] = 4;
	}
}
/* caso (4-1)*/
if (rowright[0] == 4 && rowleft[0] == 1)
{
	board[0][0] = 1
	board[0][1] = 2;
	board[0][2] = 3;
	board[0][3] = 4;
}
