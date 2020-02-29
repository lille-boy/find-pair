/**************************************************************************************************
 *                                                                         ___    ____
 * Main Program                                                           /   |  / __ \
 *                                                                       / /| | / /_/ /
 *                                                                      / ___ |/ ____/
 *                                                                     /_/  |_/_/
 *
 *************************************************************************************************/
#include <stdio.h>
#include "find_pair.h"

/******************************************************************************
 * Main
 *****************************************************************************/
int main(int argc, char *argv[])
{
    if (argc > 2) {
        find_pair(argv[1], argv[2]);
    }
    else {
        printf("Enter a list of numbers and a sum. Example: [8,7,2,5,3,1] 10");
    }

    return 0;
}