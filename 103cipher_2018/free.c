/*
** EPITECH PROJECT, 2018
** 103cipher
** File description:
** free
*/

#include "cipher.h"

void free_tab_key(cipher_t *ci)
{
    ci->y = 0;
    while (ci->y < ci->size_mat) {
        free(ci->tab_key[ci->y]);
        ci->y = ci->y + 1;
    }
    free(ci->tab_key);
}

void free_tab_message(cipher_t *ci, char *argv)
{
    free(ci->tab_message);
}

void free_all(cipher_t *ci, char *argv)
{
    free_tab_key(ci);
    free(ci->encrypted);
    free(ci->message);
    free(ci->key);
    free(ci);
}