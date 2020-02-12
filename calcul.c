/*
** EPITECH PROJECT, 2020
** PSU_2019_malloc
** File description:
** calcul
*/

#include "mem.h"

size_t power(size_t len)
{
	size_t count = 1;

	while (count < len)
		count = count * 2;
	return (count);
}

bool mul_overflow(int x, int y)
{
    if (x > INT_MAX / y || x < INT_MIN / y)
        return (false);
    return (true);
}