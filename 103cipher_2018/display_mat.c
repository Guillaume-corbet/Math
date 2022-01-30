/*
** EPITECH PROJECT, 2018
** 103cipher
** File description:
** display_mat
*/

#include "cipher.h"

void choose_spaces(cipher_t *ci)
{
    if (ci->tab_key[ci->y][ci->z] > 99)
        my_putstr("     ");
    else if (ci->tab_key[ci->y][ci->z] > 9)
        my_putstr("      ");
    else
        my_putstr("       ");
}

void display_mat(cipher_t *ci)
{
    ci->z = 0;
    ci->y = 0;
    my_printf("Key matrix:\n");
    while (ci->y < ci->size_mat) {
        while (ci->z < ci->size_mat) {
            display_mat_second(ci);
        }
        ci->z = 0;
        ci->y = ci->y + 1;
        my_putchar('\n');
    }
    my_putchar('\n');
}

void display_mat_second(cipher_t *ci)
{
    my_put_nbr(ci->tab_key[ci->y][ci->z]);
    if (ci->z + 1 < ci->size_mat)
        choose_spaces(ci);
    ci->z = ci->z + 1;
}

void display_mat_float(cipher_t *ci)
{
    ci->z = 0;
    ci->y = 0;
    my_printf("Key matrix:\n");
    while (ci->y < ci->size_mat && ci->size_mat > 1 && ci->size_mat <= 2) {
        printf("%.3f   %.3f\n", ci->tab_key[ci->y][ci->z],
        ci->tab_key[ci->y][ci->z + 1]);
        ci->y = ci->y + 1;
    }
    while (ci->y < ci->size_mat && ci->size_mat > 2 && ci->size_mat <= 3) {
        printf("%.3f   %.3f   %.3f\n", ci->tab_key[ci->y][ci->z],
        ci->tab_key[ci->y][ci->z + 1], ci->tab_key[ci->y][ci->z + 2]);
        ci->y = ci->y + 1;
    }
}