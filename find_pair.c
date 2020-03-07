/**************************************************************************************************
 *                                                                         ___    ____
 * Find pair with given sum in an array                                   /   |  / __ \
 *                                                                       / /| | / /_/ /
 *                                                                      / ___ |/ ____/
 *                                                                     /_/  |_/_/
 *
 *************************************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/******************************************************************************
 * Swap values
 *****************************************************************************/
void swap(int *a, int *b)
{
    int c = *a;
    *a = *b;
    *b = c;
}

/******************************************************************************
 * Sort the array in ascending order
 *****************************************************************************/
void sort_array(int *array, unsigned int size)
{
    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            if (array[i] > array[j]) {
                swap(&array[i], &array[j]);
            }
        }
    }
}

/******************************************************************************
 * Check if the input character is numerical
 * Returns 1 if numerical, 0 otherwise
 *****************************************************************************/
static int is_numerical(char number)
{
    if ((number >= '0') && (number <= '9')) {
        return 1;
    }

    return 0;
}

/******************************************************************************
 * Return the number of numerical elements in the user input
 *****************************************************************************/
unsigned int input_size(const char *input)
{
    unsigned int elements;
    unsigned int input_length = strlen(input);

    for (int i = 0; i < input_length; i++) {
        if (is_numerical(input[i])) {
            elements++;
        }
    }
    return elements;
}

/******************************************************************************
 * Convert input string into an array
 *****************************************************************************/
void unpack_input(const char *input_array, int *array)
{
    unsigned int input_length = strlen(input_array);

    for (int i = 0; i < input_length; i++) {
        if (is_numerical(*input_array)) {
            *array = atoi(input_array);
            array++;
        }
        input_array++;
    }
}

/******************************************************************************
 * Find pairs and display them
 *****************************************************************************/
void find_pair(const char *input_array, const char *input_sum)
{
    int sum = atoi(input_sum);
    unsigned int size = input_size(input_array);
    unsigned int low = 0;
    unsigned int high = size - 1;

    int *array = (int *)malloc(size * sizeof(int));

    if (array != NULL) {
        unpack_input(input_array, array);

        sort_array(array, size);

        while (low != high) {
            if ((array[low] + array[high]) < sum) {
                low++;
            }
            else {
                if ((array[low] + array[high]) == sum) {
                    printf("%d + %d = %d\n", array[low], array[high], sum);
                }
                high--;
            }
        }

        free(array);
    }
}
