/*
** EPITECH PROJECT, 2018
** 103cipher
** File description:
** check_flag
*/

#include "cipher.h"


void choose_flag(cipher_t *ci, char **argv)
{
    int i = 0;

    if (argv[3][0] == '0') {
        message_to_ascii(ci, argv[1]);
        key_to_ascii(ci, argv[2]);
        upgrade_key_encrypted(ci);
        upgrade_message_encrypted(ci);
        calcul_encrypted(ci);
        encrypted_message(ci);
    } else {
        exit(0);
    }
}

void check_flag(cipher_t *ci, char **argv)
{
    if ((argv[3][0] == '0' || argv[3][0] == '1') && (argv[3][1] == '\0'))
        choose_flag(ci, argv);
    else
        fatal_error();
}