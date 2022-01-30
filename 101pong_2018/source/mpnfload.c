/*
** EPITECH PROJECT, 2018
** my_put_nbr_float.c
** File description:
** my_get_nbr pour float (precision de 2);
*/

#include "./../lib/my/my.h"

void mpn_float(float nbr)
{
    int i = nbr;
    int rest;
    int calcul;
    int calcul2;

    calcul = i * 100;
    rest = nbr * 100 - calcul;
    calcul2 = (nbr * 1000 - calcul * 10 - rest * 10);
    if (rest < 0) {
        rest = rest - rest * 2;
        calcul2 = calcul2 - calcul2 * 2;
    }
    if (calcul2 > 4)
        rest = rest + 1;
    if (rest >= 100) {
        rest = rest - 100;
        if (nbr > 0)
            i = i + 1;
        else
            i = i - 1;
    }
    my_put_nbr(i);
    my_putchar('.');
    my_put_nbr(rest);
    if (rest == 0)
        my_putchar('0');
}
