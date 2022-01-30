/*
** EPITECH PROJECT, 2018
** 103cipher_2018
** File description:
** 103cipher
*/

#include "cipher.h"

int main(int argc, char **argv)
{
    cipher_t *ci;

    ci = malloc(sizeof(cipher_t));
    if (argc == 2)
        check_man(argv[1]);
    if (argc != 4)
        fatal_error();
    ci->size_mes = my_strlen(argv[1]);
    ci->size_key = my_strlen(argv[2]);
    check_flag(ci, argv);
    free_all(ci, argv[1]);
    return (0);
}