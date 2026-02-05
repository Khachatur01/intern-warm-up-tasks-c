#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>

/**
 * Converts a given integer to its binary representation and prints it to the standard output.
 *
 * @param number The 32-bit unsigned integer to be converted to binary and printed.
 */

void print_binary(uint32_t number) {

    //printf("number =, %d", number);
    //scanf("%d", &number);
    if (number == 0) {
        printf("0");
    }

    while ( number >= 1) {
        printf("%d", number % 2);
        number = number /2;
    }
}

/**
 * Prints the elements of an integer array to the standard output.
 *
 * @param array A pointer to the array containing the integers to be printed.
 * @param size The number of elements in the array.
 */

void print_array(int* array, int size)
{
    printf("{");

    for (int i = 0; i < size; i++)
        printf("%d,",array[i]);

    printf("}");
}

/**
 * Prints the hexadecimal representation of the elements in the given integer array.
 *
 * @param array A pointer to the integer array whose elements should be printed in hexadecimal format.
 * @param size The number of elements in the array.
 */

void print_array_hex(int* array, int size) {

    printf("{");

    for (int i = 0; i < size; i++)
        printf( "%x,",array[i]);

    printf("}");
}

/**
 * Computes the average value of the elements in the given integer array.
 *
 * @param array A pointer to the integer array whose average is to be calculated.
 * @param size The number of elements in the array. Must be greater than zero.
 * @return The average value of the array elements as an integer.
 */

float get_array_average(int* array, int size) {

    int average = 0, s = 0, k = 0;

    for (int i = 0; i < size; i++) {
        s += array[i];
        k++;
    }

    return s/k;
}

float get_array_average_float(float* array, float size) {

    int average = 0, s = 0, k = 0;

    for (int i = 0; i < size; i++) {
        s += array[i];
        k++;
    }

    return s/k;
}

/**
 * Finds and returns the largest element in the given array of integers.
 *
 * @param array A pointer to the array of integers to be searched.
 * @param size The size of the array.
 * @return The largest integer in the array. If the array is empty, the behavior is undefined.
 */

int get_largest(int* array, int size) {

    int max = array[0];

    for (int i = 0; i < size; i++) {
        if (array[i] > max)
            max = array[i];
    }

    return max;
}

float get_largest_float(float* array, int size) {

    float max = array[0];

    for (int i = 0; i < size; i++) {
        if (array[i] > max)
            max = array[i];
    }

    return max;
}

float get_smallest_float(float* array, int size) {

    float min = array[0];

    for (int i = 0; i < size; i++) {
        if (array[i] < min)
            min = array[i];
    }

    return min;
}

/**
 * Counts the number of odd elements in the given array.
 *
 * @param array A pointer to the array of integers to be processed.
 * @param size The size of the array.
 * @return The odd elements count */

int get_odd_elements_count(int* array, int size) {

    int count = 0;

    for (int i = 0; i < size; i++) {
        if (array[i] % 2 != 0)
            count++;
    }
    return count;
}


/**
 * Performs a linear search on an array to find the index of a specified value.
 *
 * @param array A pointer to the array to be searched.
 * @param size The number of elements in the array.
 * @param value The target value to search for within the array.
 * @return The index of the first occurrence of the target value if found, or -1 if the value is not present.
 ``` */

int linear_search(int* array, int size, int value) {

    for (int i = 0; i < size; i++) {
        if (array[i] == value)
            return i;
    }
    return -1;
}

/**
 * Swaps the elements of an array at the specified indices.
 *
 * @param array Pointer to the array whose elements are to be swapped.
 * @param size The size of the array.
 * @param index1 The index of the first element to be swapped.
 * @param index2 The index of the second element to be swapped.
 */

void swap_elements(int* array, int size, int index1, int index2) {

    int container = array[index1];
    array[index1] = array[index2];
    array[index2] = container;
}

void swap_elements_char(char* array, int size, int index1, int index2) {

    int container = array[index1];
    array[index1] = array[index2];
    array[index2] = container;
}

/**
 * Reverses the elements of an integer array in-place.
 *
 * @param array The pointer to the integer array to be reversed.
 * @param size The size of the array to be reversed.
 */

void reverse_array(int* array, int size) {

    for (int i = 0 ; i < size /2; i++) {
        swap_elements(array, size, i,size - i - 1);
    }
}

void reverse_array_char(char* array, int size) {

    for (int i = 0 ; i < size /2; i++) {
        swap_elements_char(array, size, i,size - i - 1);
    }
}


/**
 * Copies the contents of one integer array to another.
 *
 * @param to_array Pointer to the destination array where data will be copied.
 * @param from_array Pointer to the source array to copy data from.
 * @param size The number of elements to be copied from the source array.
 */

void copy_array(int* to_array, int* from_array, int size) {

    //Destination array??

    for (int i = 0; i < size; i++) {
        to_array[i] = from_array[i];
    }
}

/**############################################## ADVANCED TASKS#####################################################*/
/**
 * Imagine an array containing the temperature values read from sensors.
 * Sometimes sensors can glitch and send very strange values (eg. 1547.4, 52002.985) instead of real temperature
 * (eg. 10.4, 21.0, -18.4)
 * Function that calculates the average temperature should "fix" this incorrect values to not pollute
 * the average calculation.
 * For that we define min and max threshold values to filter out the incorrect values.
 * You should either ignore incorrect values or replace them with the nearest valid value.
 * For example if min is -50 and max is 90, you should interpret these value like this:
 *      -15.9   ->  -15.9 (value is in the valid range, use it as it is)
 *      -98.2   ->  -50 (value is NOT in the valid range, use -50 instead)
 *      24.5    ->  24.5 (value is in the valid range, use it as it is)
 *      2015.98 ->  90 (value is NOT in the valid range, use 90 instead)
 *
 * NOTE: we are using float instead of integer as temperature is a real number value (11.87, 74, 91.6, 66, -2.0 not only 74 and 66)
 *
 * @param array The pointer to the integer array of temperatures.
 * @param size The size of the array of temperatures.
 * @param min The minimum valid temperature value.
 * @param max The maximum valid temperature value.
 */
float temperature_average(float* array, float size, float min, float max) {

    int count = 0;
    float sum = 0;

    // max = get_largest_float(array,(int)size);
    // min = get_smallest_float(array, (int)size);

    for (int i = 0; i < size; i++) {
        if (array[i] >= min && array[i] <= max) {
            printf("%f,- value is in the valid range, use it as it is", array[i]);
            sum += array[i];
            count++;
        }
        else if (array[i]< min) {
            printf("%f,- value is NOT in the valid range, use %f instead", array[i], min);
            array[i] = min;
            sum += array[i];
            count++;
        }
        else {
            printf("%f,- value is NOT in the valid range, use %f instead", array[i], max);
            array[i] = max;
            sum += array[i];
            count++;
        }

    }

    return sum / count;
}


int power_of_2(int n) {
    int result = 1;
    //
    // for (int i = 0; i < n; i++) {
    //     result = result * 2;
    // }
    return result;
}

/**
 * Computes 2 raised to the power of the given integer without using loops and multiplication
 *
 * @param n The exponent to which 2 is raised. Must be a non-negative integer.
 * @return The result of 2 raised to the power of n.
 */
int power_of_2(int n) {
    int result = 1;

    // for (int i = 0; i < n; i++) {
    //     result = result * 2;
    // }
    return result;
}


/**
 * Sets the bit at the specified index in the given integer to 1.
 * 
 * NOTE: You have to learn about bitwise operations and how numbers are represented in binary (if not already familiar).
 *
 * @param number The one-byte unsigned integer whose bit is to be set.
 * @param bit_index The zero-based position of the bit to be set.
 * @return The new integer value with the specified bit set to 1.
 *
 ***********************************************************************************************************************
 * @example number = 00000000, bit_index = 0 -> result is 00000001
 *                          ^                                    ^
 ***********************************************************************************************************************
 * @example number = 00000000, bit_index = 5 -> result is 00100000
 *                     ^                                    ^
 ***********************************************************************************************************************
 * @example number = 10000000, bit_index = 1 -> result is 10000010
 *                         ^                                    ^
 * (we didn't change the bit in index 7, just 1)
 ***********************************************************************************************************************
 * @example number = 00000010, bit_index = 1 -> result is 00000010
 *                         ^                                    ^
 * (bit 1 is already set, so after setting it again nothing changes)
 */

uint8_t set_bit(uint8_t number, uint8_t bit_index) {

    int k = 0;
    while (number > 0) {
        number /= 10;
        k++;
    }

    print_binary(number);

    char str[k];
    sprintf(str, "%d", number);
    reverse_array_char(str,k);

    for (int i = 0; i < k; i++) {
        if (bit_index == i) {
            str[i] = '1';
        }
    }

    number = strtol(str, NULL, 2);

    return number;
}

#define KNRM  "\x1B[0m"
#define KRED  "\x1B[31m"
#define KGRN  "\x1B[32m"
#define KYEL  "\x1B[33m"
#define KBLU  "\x1B[34m"

int main(void) {
    printf("%s=== Testing print_binary ===\n", KBLU);
    printf("%sBinary of 0: ", KYEL);
    print_binary(0);
    printf("%s\nBinary of 5: ", KYEL);
    print_binary(5);
    printf("%s\nBinary of 7: ", KYEL);
    print_binary(7);
    printf("%s\nBinary of 8: ", KYEL);
    print_binary(8);
    printf("%s\nBinary of 255: ", KYEL);
    print_binary(255);
    printf("%s\nBinary of 4294967295: ", KYEL);
    print_binary(4294967295);
    printf("\n\n");

    printf("%s=== Testing print_array ===\n", KBLU);
    int test_array[] = {1, 2, 3, 4, 5};
    printf("%sArray: ", KYEL);
    print_array(test_array, 5);
    printf("\n\n");

    printf("%s=== Testing print_array_hex ===\n", KBLU);
    int hex_array[] = {10, 15, 255, 256, 4096};
    printf("%sArray in hex: ", KYEL);
    print_array_hex(hex_array, 5);
    printf("\n\n");

    printf("%s=== Testing get_array_average ===\n", KBLU);
    int avg_array[] = {10, 20, 30, 40, 50};
    float average = get_array_average(avg_array, 5);
    printf("%sAverage of {10, 20, 30, 40, 50}: %.2f (expected: 30.00)\n\n", average == 30 ? KGRN : KRED, average);

    printf("%s=== Testing get_largest ===\n", KBLU);
    int largest_array[] = {3, 7, 2, 9, 1, 5};
    int largest = get_largest(largest_array, 6);
    printf("%sLargest in {3, 7, 2, 9, 1, 5}: %d (expected: 9)\n\n", largest == 9 ? KGRN : KRED, largest);

    printf("%s=== Testing get_odd_elements_count ===\n", KBLU);
    int odd_array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int odd_count = get_odd_elements_count(odd_array, 9);
    printf("%sOdd count in {1, 2, 3, 4, 5, 6, 7, 8, 9}: %d (expected: 5)\n\n", odd_count == 5 ? KGRN : KRED, odd_count);

    printf("%s=== Testing linear_search ===\n", KBLU);
    int search_array[] = {10, 20, 30, 40, 50};
    int index_found = linear_search(search_array, 5, 30);
    int index_not_found = linear_search(search_array, 5, 99);
    printf("%sIndex of 30 in {10, 20, 30, 40, 50}: %d (expected: 2)\n", index_found == 2 ? KGRN : KRED, index_found);
    printf("%sIndex of 99 in {10, 20, 30, 40, 50}: %d (expected: -1)\n\n", index_not_found == -1 ? KGRN : KRED, index_not_found);

    printf("%s=== Testing swap_elements ===\n", KBLU);
    int swap_array[] = {1, 2, 3, 4, 5};
    printf("Before swap: ");
    print_array(swap_array, 5);
    swap_elements(swap_array, 5, 1, 3);
    printf("\nAfter swapping indices 1 and 3: ");
    print_array(swap_array, 5);
    printf("%s (expected: {1, 4, 3, 2, 5})\n\n", swap_array[1] == 4 && swap_array[3] == 2 ? KGRN : KRED);

    printf("%s=== Testing reverse_array ===\n", KBLU);
    int reverse_array_test[] = {1, 2, 3, 4, 5};
    printf("Before reverse: ");
    print_array(reverse_array_test, 5);
    reverse_array(reverse_array_test, 5);
    printf("\nAfter reverse: ");
    print_array(reverse_array_test, 5);
    printf("%s (expected: {5, 4, 3, 2, 1})\n\n", reverse_array_test[0] == 5 && reverse_array_test[1] == 4 && reverse_array_test[2] == 3 && reverse_array_test[3] == 2 && reverse_array_test[4] == 1 ? KGRN : KRED);

    printf("%s=== Testing copy_array ===\n", KBLU);
    int source_array[] = {10, 20, 30, 40, 50};
    int dest_array[5] = {0};
    printf("Source array: ");
    print_array(source_array, 5);
    printf("\nDestination before copy: ");
    print_array(dest_array, 5);
    copy_array(dest_array, source_array, 5);
    printf("\nDestination after copy: ");
    print_array(dest_array, 5);
    printf("%s (expected: {10, 20, 30, 40, 50})\n\n", dest_array[0] == 10 && dest_array[1] == 20 && dest_array[2] == 30 && dest_array[3] == 40 && dest_array[4] == 50 ? KGRN : KRED);

    printf("%s=== Testing copy_array 2 ===\n", KBLU);
    int source_array2[] = {10, 20, 30, 40, 50};
    int dest_array2[5] = {0};
    printf("Source array: ");
    print_array(source_array2, 5);
    printf("\nDestination before copy: ");
    print_array(dest_array2, 5);
    copy_array(dest_array2, source_array2, 2);
    printf("\nDestination after copy: ");
    print_array(dest_array2, 5);
    printf("%s (expected: {10, 20, 0, 0, 0})\n\n", dest_array2[0] == 10 && dest_array2[1] == 20 && dest_array2[2] == 0 && dest_array2[3] == 0 && dest_array2[4] == 0 ? KGRN : KRED);

    printf("%s=== Testing temperature_average ===\n", KBLU);
    float temp_array[] = {-15.9, -98.2, 24.5, 2015.98, 20.0, -30.0};
    float temp_avg = temperature_average(temp_array, 6, -50.0, 90.0);
    printf("Values: -15.9 -> -15.9, -98.2 -> -50, 24.5 -> 24.5, 2015.98 -> 90, 20.0 -> 20.0, -30.0 -> -30.0\n");
    float real_average = (-15.9 + -50.0 + 24.5 + 90.0 + 20.0 + -30.0) / 6.0;
    printf("%sTemperature average with thresholds [-50, 90]: %.2f (expected %.2f)\n\n", temp_avg == real_average ? KGRN : KRED, temp_avg, real_average);

    printf("%s=== Testing power_of_2 ===\n", KBLU);
    int pow_test1 = power_of_2(5);
    printf("%s2 raised to the power of 5: %d (expected: 32)\n", pow_test1 == 32 ? KGRN : KRED, pow_test1);
    int pow_test2 = power_of_2(7);
    printf("%s2 raised to the power of 7: %d (expected: 128)\n", pow_test2 == 128 ? KGRN : KRED, pow_test2);
    int pow_test3 = power_of_2(0);
    printf("%s2 raised to the power of 0: %d (expected: 1)\n", pow_test3 == 1 ? KGRN : KRED, pow_test3);
    int pow_test4 = power_of_2(8);
    printf("%s2 raised to the power of 8: %d (expected: 256)\n", pow_test4 == 256 ? KGRN : KRED, pow_test4);
    int pow_test5 = power_of_2(16);
    printf("%s2 raised to the power of 16: %d (expected: 65536)\n", pow_test5 == 65536 ? KGRN : KRED, pow_test5);
    printf("\n");

    printf("%s=== Testing set_bit ===\n", KBLU);
    uint8_t bit_test1 = set_bit(0b00000000, 0);
    printf("%sset_bit(0b00000000, 0) = 0b%08d (expected: 0b00000001, decimal: %d)\n", bit_test1 == 0b00000001 ? KGRN : KRED, bit_test1, bit_test1);

    uint8_t bit_test2 = set_bit(0b00000000, 5);
    printf("%sset_bit(0b00000000, 5) = 0b%08d (expected: 0b00100000, decimal: %d)\n", bit_test2 == 0b00100000 ? KGRN : KRED, bit_test2, bit_test2);

    uint8_t bit_test3 = set_bit(0b10000000, 1);
    printf("%sset_bit(0b10000000, 1) = 0b%08d (expected: 0b10000010, decimal: %d)\n", bit_test3 == 0b10000010 ? KGRN : KRED, bit_test3, bit_test3);

    uint8_t bit_test4 = set_bit(0b00000010, 1);
    printf("%sset_bit(0b00000010, 1) = 0b%08d (expected: 0b00000010, decimal: %d)\n", bit_test4 == 0b00000010 ? KGRN : KRED, bit_test4, bit_test4);

    printf("%s\n=== All tests completed ===\n", KBLU);

    return 0;
}