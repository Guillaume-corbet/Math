/*
** EPITECH PROJECT, 2018
** 103cipher
** File description:
** decrypt.c
*/

#include "cipher.h"

void upgrade_key_second_decrypted(cipher_t *ci)
{
    if (ci->key[ci->i] == '\0')
        ci->tab_key[ci->y][ci->z] = 0;
    else {
        ci->tab_key[ci->y][ci->z] = ci->key[ci->i];
        ci->i = ci->i + 1;
    }
    ci->z = ci->z + 1;
}

void upgrade_key_decrypted(cipher_t *ci)
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

void search_determinant(cipher_t *ci)
{
    float calcul = 0;
    if (ci->size_mat > 1 && ci->size_mat <= 2) {
        ci->determinant = ci->tab_key[0][0] * ci->tab_key[1][1];
        ci->determinant = ci->determinant - ci->tab_key[0][1]
        * ci->tab_key[1][0];
    } else if (ci->size_mat > 2 && ci->size_mat <= 3) {
        ci->determinant = ci->tab_key[0][0] * ci->tab_key[1][1]
        * ci->tab_key[2][2];
        calcul = ci->tab_key[0][1] * ci->tab_key[1][2] * ci->tab_key[2][0];
        ci->determinant = ci->determinant + calcul;
        calcul = ci->tab_key[0][2] * ci->tab_key[1][0] * ci->tab_key[2][1];
        ci->determinant = ci->determinant + calcul;
        calcul = ci->tab_key[0][2] * ci->tab_key[1][1] * ci->tab_key[2][0];
        ci->determinant = ci->determinant - calcul;
        calcul = ci->tab_key[0][1] * ci->tab_key[1][0] * ci->tab_key[2][2];
        ci->determinant = ci->determinant - calcul;
        calcul = ci->tab_key[0][0] * ci->tab_key[1][2] * ci->tab_key[2][1];
        ci->determinant = ci->determinant - calcul;
    }
}

void calcul_key_decrypt(cipher_t *ci)
{
    if (ci->determinant == 0) {
        exit(0);
    }
    if (ci->size_mat > 1 && ci->size_mat <= 2) {
        ci->tab_key[0][0] = ci->tab_key[1][1] / ci->determinant;
        ci->tab_key[0][1] = ci->tab_key[1][0] / ci->determinant * -1;
        ci->tab_key[1][0] = ci->tab_key[0][1] / ci->determinant * -1;
        ci->tab_key[1][1] = ci->tab_key[0][0] / ci->determinant;
    } else if (ci->size_mat > 2 && ci->size_mat <= 3) {
        ci->tab_key[0][0] = ci->tab_key[0][0] / ci->determinant;
        ci->tab_key[0][1] = ci->tab_key[0][1] / ci->determinant;
        ci->tab_key[0][2] = ci->tab_key[0][2] / ci->determinant;
        ci->tab_key[1][0] = ci->tab_key[1][0] / ci->determinant;
        ci->tab_key[1][1] = ci->tab_key[1][1] / ci->determinant;
        ci->tab_key[1][2] = ci->tab_key[1][2] / ci->determinant;
        ci->tab_key[2][0] = ci->tab_key[2][0] / ci->determinant;
        ci->tab_key[2][1] = ci->tab_key[2][1] / ci->determinant;
        ci->tab_key[2][2] = ci->tab_key[2][2] / ci->determinant;
    }
}

void upgrade_key_decrypted_other(cipher_t *ci)
{
    while (ci->y < ci->size_mat) {
        while (ci->z < ci->size_mat) {
            ci->tab_key[ci->y][ci->z] = ci->key[ci->i];
            ci->i = ci->i + 1;
            ci->z = ci->z + 1;
        }
        ci->z = 0;
        ci->y = ci->y + 1;
    }
}
