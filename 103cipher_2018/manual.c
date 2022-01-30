/*
** EPITECH PROJECT, 2018
** 103cipher
** File description:
** manual
*/

#include "cipher.h"

void display_man(void)
{
    my_printf("USAGE\n    ./103cipher message key flag\n\n");
    my_printf("DESCRIPTION\n    message      a message, made of ");
    my_printf("ASCII characters\n    key          the encryption ");
    my_printf("key, made of ASCII characters\n    flag         0 ");
    my_printf("for the message to be encrypted, 1 to be decrypted\n");
    exit(0);
}

void fatal_error(void)
{
    my_printf("WRONG USAGE\nUse -h for more information\n");
    exit(84);
}

void check_man(char *argv)
{
    if (argv[0] == '-' && argv[1] == 'h' && argv[2] == '\0')
        display_man();
    else
        fatal_error();
}