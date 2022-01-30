/*
** EPITECH PROJECT, 2018
** 103cipher
** File description:
** encrypt.c
*/

#include "cipher.h"

void upgrade_key_second_encrypted(cipher_t *ci)
{
    if (ci->key[ci->i] == '\0')
        ci->tab_key[ci->y][ci->z] = 0;
    else {
        ci->tab_key[ci->y][ci->z] = ci->key[ci->i];
        ci->i = ci->i + 1;
    }
    ci->z = ci->z + 1;
}

void upgrade_key_encrypted(cipher_t *ci)
{
    double test = 0;

    ci->i = 0;
    ci->z = 0;
    ci->y = 0;
    ci->size_mat = sqrt(ci->size_key);
    test = ci->size_mat * ci->size_mat;
    ci->tab_key = malloc(sizeof(int *) * (ci->size_mat));
    while (ci->y < ci->size_mat) {
        ci->tab_key[ci->y] = malloc(sizeof(int) * (ci->size_mat));
        while (ci->z < ci->size_mat) {
            upgrade_key_second_encrypted(ci);
        }
        ci->z = 0;
        ci->y = ci->y + 1;
    }
}

void find_encrypted_result(cipher_t *ci)
{
    while (ci->c < ci->size_mat) {
        while (ci->a < ci->size_mat) {
            ci->result = ci->result + ci->tab_message[ci->b][ci->a]
            * ci->tab_key[ci->a][ci->c];
            ci->a = ci->a + 1;
        }
        ci->a = 0;
        ci->encrypted[ci->i] = ci->result;
        ci->result = 0;
        ci->c = ci->c + 1;
        ci->i = ci->i + 1;
    }
}

void calcul_encrypted(cipher_t *ci)
{
    ci->i = 0;
    ci->a = 0;
    ci->b = 0;
    ci->c = 0;
    ci->ouf = ci->size_mat * ci->size_mat;
    ci->encrypted = malloc(sizeof(int) * (ci->ouf) * (ci->size_mes));
    while (ci->i < ci->size_mes || ci->b < ci->size_mat) {
        find_encrypted_result(ci);
        ci->c = 0;
        ci->b = ci->b + 1;
    }
    ci->encrypted[ci->i] = '\0';
    ci->i = 0;
}

void encrypted_message(cipher_t *ci)
{
    ci->i = 0;
    display_mat(ci);
    my_printf("Encrypted message is:\n");
    while (ci->encrypted[ci->i] != '\0') {
        my_put_nbr(ci->encrypted[ci->i]);
        if (ci->encrypted[ci->i + 1] != '\0')
            my_putchar(' ');
        ci->i = ci->i + 1;
    }
    my_putchar('\n');
}