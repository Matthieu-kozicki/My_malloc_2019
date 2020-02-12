/*
** EPITECH PROJECT, 2018
** my_put_nbr.c
** File description:
** .
*/

#include <math.h>
#include "mem.h"

void my_putchar(char c)
{
    write(1, &c, 1);
}

void  my_put_nbr(int nb)
{
    int z = 0;
    int d = 1;

    if (nb < 0) {
        my_putchar('-');
        nb = nb *-1;
    }
    while (nb/d >= 10) {
        d *= 10;
    }
    while (d >= 1 ) {
        z = nb / d;
        z = z + 48;
        my_putchar(z);
        nb = nb % d;
        d = d / 10;
    }
}

int my_strlen(char const *str)
{
    int i = 0;

    while (str[i] != '\0')
        i = i + 1;
    return (i);
}

void my_putstr(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        write(1, &str[i], 1);
        i = i + 1;
    }
}

char *my_revstr(char *str)
{
    int i = 0;
    int j = my_strlen(str);
    int temp = 0;

    j = j - 1;
    while (i < j) {
        temp = str[j];
        str[j] = str[i];
        str[i] = temp;
        j = j - 1;
        i = i + 1;
    }
    return (str);
}
