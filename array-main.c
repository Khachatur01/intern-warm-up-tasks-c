#include <stdio.h>

#define ARRAY_CAPACITY 10

typedef struct int_array {
    int elements[ARRAY_CAPACITY];
    int size;
} int_array_t;

/**
 * Initializes an integer array structure.
 * Sets the size to 0.
 *
 * @param array Pointer to the int_array_t structure to initialize
 */
void array_init(int_array_t* array) {
}

/**
 * Prints all elements in the array to standard output.
 *
 * @param array Pointer to the int_array_t structure to print
 */
void array_print(int_array_t* array) {
    
}

/**
 * Adds an element to the end of the array.
 *
 * @param array Pointer to the int_array_t structure
 * @param element The integer value to add to the array
 * @return 0 if successful, -1 if an array is full
 */
int array_push_back(int_array_t* array, int element) {
   return 0;
}

/**
 * Retrieves the element at the specified index.
 *
 * @param array Pointer to the int_array_t structure
 * @param index The position of the element to retrieve
 * @return The integer value at the specified index. Return -1 if the index is out of bounds
 */
int array_get(int_array_t* array, int index) {
    return 0;
}

/**
 * Sets the element at the specified index to a new value.
 *
 * @param array Pointer to the int_array_t structure
 * @param index The position where the element should be set
 * @param element The new integer value to set
 * @return 0 if successful, -1 if the index is out of bounds
 */
int array_set(int_array_t* array, int index, int element) {
    return 0;
}

/**
 * Inserts an element at the specified index, shifting subsequent elements.
 *
 * @param array Pointer to the int_array_t structure
 * @param index The position where the element should be inserted
 * @param element The integer value to insert
 * @return 0 if successful, -1 if the index is out of bounds, -2 if the array is full
 */
int array_insert(int_array_t* array, int index, int element) {
    return 0;
}

/**
 * Removes the element at the specified index, shifting subsequent elements.
 *
 * @param array Pointer to the int_array_t structure
 * @param index The position of the element to remove
 * @return 0 if successful, -1 if the index is out of bounds, -2 if the array is empty
 */
int array_remove(int_array_t* array, int index) {
    return 0;
}

/**
 * Resets size to 0.
 *
 * @param array Pointer to the int_array_t structure to clear
 */
void array_clear(int_array_t* array) {
    
}

#define KNRM  "\x1B[0m"
#define KRED  "\x1B[31m"
#define KGRN  "\x1B[32m"
#define KYEL  "\x1B[33m"
#define KBLU  "\x1B[34m"

int main(void) {
    int_array_t array;

    printf("%s=== Testing array_init ===\n", KBLU);
    array.size = 5; /* assuming that size has some garbage value */
    array_init(&array);
    printf("%sarray_init: size = %d (expected: 0)\n\n", array.size == 0 ? KGRN : KRED, array.size);

    printf("%s=== Testing array_push_back ===\n", KBLU);
    array.size = 0;
    int push_test1 = array_push_back(&array, 10);
    printf("%sarray_push_back(10) = %d (expected: 0), size = %d\n", push_test1 == 0 ? KGRN : KRED, push_test1,
           array.size);

    int push_test2 = array_push_back(&array, 20);
    printf("%sarray_push_back(20) = %d (expected: 0), size = %d\n", push_test2 == 0 ? KGRN : KRED, push_test2,
           array.size);

    int push_test3 = array_push_back(&array, 30);
    printf("%sarray_push_back(30) = %d (expected: 0), size = %d\n", push_test3 == 0 ? KGRN : KRED, push_test3,
           array.size);

    printf("%sArray after push_back: ", KYEL);
    array_print(&array);
    printf("\n");

    printf("%s=== Testing array_get ===\n", KBLU);
    int get_test1 = array_get(&array, 0);
    printf("%sarray_get(0) = %d (expected: 10)\n", get_test1 == 10 ? KGRN : KRED, get_test1);

    int get_test2 = array_get(&array, 1);
    printf("%sarray_get(1) = %d (expected: 20)\n", get_test2 == 20 ? KGRN : KRED, get_test2);

    int get_test3 = array_get(&array, 2);
    printf("%sarray_get(2) = %d (expected: 30)\n", get_test3 == 30 ? KGRN : KRED, get_test3);

    int get_test4 = array_get(&array, 10);
    printf("%sarray_get(10) = %d (expected: -1 - out of bounds)\n\n", get_test4 == -1 ? KGRN : KRED, get_test4);

    printf("%s=== Testing array_set ===\n", KBLU);
    int set_test1 = array_set(&array, 1, 25);
    printf("%sarray_set(1, 25) = %d (expected: 0)\n", set_test1 == 0 ? KGRN : KRED, set_test1);

    int set_verify = array_get(&array, 1);
    printf("%sarray_get(1) after set = %d (expected: 25)\n", set_verify == 25 ? KGRN : KRED, set_verify);

    int set_test2 = array_set(&array, 10, 100);
    printf("%sarray_set(10, 100) = %d (expected: -1 - out of bounds)\n", set_test2 == -1 ? KGRN : KRED, set_test2);

    printf("%sArray after set: ", KYEL);
    array_print(&array);
    printf("\n");

    printf("%s=== Testing array_insert ===\n", KBLU);
    int insert_test1 = array_insert(&array, 1, 15);
    printf("%sarray_insert(1, 15) = %d (expected: 0), size = %d\n", insert_test1 == 0 ? KGRN : KRED, insert_test1,
           array.size);

    printf("%sArray after insert: ", KYEL);
    array_print(&array);
    printf("\n");

    int insert_test2 = array_insert(&array, 0, 5);
    printf("%sarray_insert(0, 5) = %d (expected: 0), size = %d\n", insert_test2 == 0 ? KGRN : KRED, insert_test2,
           array.size);

    printf("%sArray after insert at beginning: ", KYEL);
    array_print(&array);
    printf("\n");

    printf("%s=== Testing array_remove ===\n", KBLU);
    int remove_test1 = array_remove(&array, 2);
    printf("%sarray_remove(2) = %d (expected: 0), size = %d\n", remove_test1 == 0 ? KGRN : KRED, remove_test1,
           array.size);

    printf("%sArray after remove: ", KYEL);
    array_print(&array);
    printf("\n");

    int remove_test2 = array_remove(&array, 10);
    printf("%sarray_remove(10) = %d (expected: -1 - out of bounds)\n\n", remove_test2 == -1 ? KGRN : KRED,
           remove_test2);

    printf("%s=== Testing array capacity ===\n", KBLU);
    array_clear(&array);
    for (int i = 0; i < ARRAY_CAPACITY; i++) {
        array_push_back(&array, i * 10);
    }
    printf("%sFilled array to capacity (%d elements): ", KYEL, array.size);
    array_print(&array);
    printf("\n");

    int capacity_test = array_push_back(&array, 999);
    printf("%sarray_push_back when full = %d (expected: -1)\n\n", capacity_test == -1 ? KGRN : KRED, capacity_test);

    printf("%s=== Testing array_clear ===\n", KBLU);
    array_clear(&array);
    printf("%sarray_clear: size = %d (expected: 0)\n", array.size == 0 ? KGRN : KRED, array.size);

    int clear_remove_test = array_remove(&array, 0);
    printf("%sarray_remove on empty array = %d (expected: -2)\n\n", clear_remove_test == -2 ? KGRN : KRED,
           clear_remove_test);

    printf("%s=== All tests completed ===\n", KBLU);
    return 0;
}
