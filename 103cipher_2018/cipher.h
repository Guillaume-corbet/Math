/*
** EPITECH PROJECT, 2018
** 103cipher_2018
** File description:
** cipher
*/

#ifndef CIPHER_H_
#define CIPHER_H_

#include "lib/my/my.h"
#include <stdio.h>
#include "lib/my_printf/my_printf.h"
#include <math.h>
#include <string.h>

typedef struct cipher
{
    int i;
    int y;
    int z;
    int a;
    int ouf;
    int b;
    int c;
    int k;
    int count;
    int result;
    int check;
    int reversal;
    int column;
    int column_bis;
    float determinant;
    double size_mes;
    double size_key;
    double size_mat;
    int *message;
    int *key;
    int **tab_message;
    float **tab_key;
    int *encrypted;
}cipher_t;

void check_man(char *);
void fatal_error(void);
void free_all(cipher_t *, char *);
void message_to_ascii(cipher_t *, char *);
void key_to_ascii(cipher_t *, char *);
void upgrade_message_encrypted(cipher_t *);
void upgrade_key_second_encrypted(cipher_t *);
void display_mat(cipher_t *);
void upgrade_key_encrypted(cipher_t *);
void decrypted_message(cipher_t *);
void encrypted_message(cipher_t *);
void check_flag(cipher_t *, char **);
void choose_flag(cipher_t *, char **);
void calcul_encrypted(cipher_t *);
void find_encrypted_result(cipher_t *);
void calcul_key_encrypted(cipher_t *);
void upgrade_key_decrypted(cipher_t *);
void upgrade_key_decrypted_second(cipher_t *);
void search_determinant(cipher_t *);
void calcul_key_decrypt(cipher_t *);
void upgrade_key_decrypted_other(cipher_t *);
void decrypted_key(cipher_t *);
void display_mat_float(cipher_t *);
void display_mat_second(cipher_t *);

#endif /* !CIPHER_H_ */
