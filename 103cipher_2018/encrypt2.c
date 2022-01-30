/*
** EPITECH PROJECT, 2018
** Visual Studio Live Share (Workspace)
** File description:
** encrypt2
*/

#include "cipher.h"

void upgrade_message_encrypted(cipher_t *ci)
{
    ci->i = 0;
    ci->z = 0;
    ci->y = 0;
    ci->tab_message = malloc(sizeof(int *) * (ci->size_mes));
    if (ci->size_key >= ci->size_mes)
        exit(0);
    while (ci->i < ci->size_mes) {
        ci->tab_message[ci->y] = malloc(sizeof(int *) * (ci->size_mes));
        while (ci->z < ci->size_mat) {
            ci->tab_message[ci->y][ci->z] = ci->message[ci->i];
            ci->i = ci->i + 1;
            ci->z = ci->z + 1;
        }
        ci->z = 0;
        ci->y = ci->y + 1;
    }
}