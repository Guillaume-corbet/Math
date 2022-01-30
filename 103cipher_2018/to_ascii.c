/*
** EPITECH PROJECT, 2018
** 103cipher
** File description:
** to_ascii
*/

#include "cipher.h"

void message_to_ascii(cipher_t *ci, char *argv)
{
    ci->i = 0;
    ci->message = malloc(sizeof(int) * ci->size_mes + 1);
    while (argv[ci->i] != '\0') {
        ci->message[ci->i] = argv[ci->i];
        ci->i = ci->i + 1;
    }
}

void key_to_ascii(cipher_t *ci, char *argv)
{
    ci->i = 0;
    ci->key = malloc(sizeof(ci->size_key) * my_strlen(argv) + 1);
    while (argv[ci->i] != '\0') {
        ci->key[ci->i] = argv[ci->i];
        ci->i = ci->i + 1;
    }
    ci->key[ci->i] = '\0';
}