/*
** EPITECH PROJECT, 2018
** 101_pong
** File description:
** main
*/

#include "./../lib/my/my.h"
#include "./../include/main.h"
#include "./../include/mpnfload.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <math.h>

void display_velocity(float xvelocity, float yvelocity, float zvelocity)
{
    my_putstr("The velocity vector of the ball is:\n");
    my_putchar('(');
    mpn_float(xvelocity);
    my_putstr(", ");
    mpn_float(yvelocity);
    my_putstr(", ");
    mpn_float(zvelocity);
    my_putstr(")\n");
}

void display_result(float xresult, float yresult, float zresult, int times)
{
    my_putstr("At time t + ");
    mpn_float(times);
    my_putstr(", ball coordinates will be:\n");
    my_putchar('(');
    mpn_float(xresult);
    my_putstr(", ");
    mpn_float(yresult);
    my_putstr(", ");
    mpn_float(zresult);
    my_putstr(")\n");
}

void display_touch(int touch, float angle)
{
    if (touch == 0) {
        my_putstr("The ball won’t reach the bat.\n");
    } else {
        my_putstr("The incidence angle is:\n");
        mpn_float(angle);
        my_putstr(" degrees\n");
    }
}

int main(int argc, char **argv)
{
    if (argc == 1) {
        return (0);
    }
    if (argv[1][0] == '-' && argv[1][1] == 'h') {
        write(1, "USAGE\n", 7);
        write(1, "      ./101pong x0 y0 z0 x1 y1 z1 n\n\n", 40);
        write(1, "DESCRIPTION\n", 13);
        write(1, "      x0    ball abscissa at time t - 1\n", 45);
        write(1, "      y0    ball ordinate at time t - 1\n", 45);
        write(1, "      z0    ball altitude at time t - 1\n", 45);
        write(1, "      x1    ball abscissa at time t\n", 40);
        write(1, "      y1    ball ordinate at time t\n", 40);
        write(1, "      z1    ball altitude at time t\n", 40);
        write(1, "      n     time shift (greater than or equal to zero, integer)\n", 65);
        return (0);
    }
    if (argc != 8) {
        return (0);
    }
    char **str;
    DECLARATION;
    xnull = strtof(argv[1], str);
    ynull = strtof(argv[2], str);
    znull = strtof(argv[3], str);
    xfirst = strtof(argv[4], str);
    yfirst = strtof(argv[5], str);
    zfirst = strtof(argv[6], str);
    times = strtof(argv[7], str);
    xvelocity = xfirst - xnull;
    yvelocity = yfirst - ynull;
    zvelocity = zfirst - znull;
    xresult = xfirst + xvelocity * times;
    yresult = yfirst + yvelocity * times;
    zresult = zfirst + zvelocity * times;
    angle = acos(zvelocity/(sqrt(pow(yvelocity, 2) + pow(xvelocity, 2) + pow(zvelocity, 2)))) * 57.29578;
    if (angle > 90) {
        angle = angle - 90;
    } else if (angle < 0) {
        angle = angle * (-1);
    } else if (angle < -90) {
        angle = angle * (-1) + 90;
    }
    if ((zfirst < 0 && zresult > 0) || (zfirst > 0 && zresult < 0)) {
        touch = 1;
    }
    display_velocity(xvelocity, yvelocity, zvelocity);
    display_result(xresult, yresult, zresult, times);
    display_touch(touch, angle);
    return (0);
}
