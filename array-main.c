#include <stdio.h>

#define VECTOR_CAPACITY 100

typedef struct int_array {
    int elements[VECTOR_CAPACITY];
    int size;
} int_array_t;

/**
 * Initializes an integer array structure.
 * Sets the size to 0.
 *
 * @param array Pointer to the int_array_t structure to initialize
 */
void vector_init(int_array_t* array) {
    array->size = 0;
}

/**
 * Prints all elements in the array to standard output.
 *
 * @param array Pointer to the int_array_t structure to print
 */
void vector_print(int_array_t* array) {
    
}

/**
 * Adds an element to the end of the array.
 *
 * @param array Pointer to the int_array_t structure
 * @param element The integer value to add to the array
 * @return 0 if successful, -1 if an array is full
 */

int vector_push_back(int_array_t* array, int element) {
     if (array->size >= VECTOR_CAPACITY)
         return -1;
     array->elements[array->size++] = element;
   return 0;
}

/**
 * Retrieves the element at the specified index.
 *
 * @param array Pointer to the int_array_t structure
 * @param index The position of the element to retrieve
 * @return The integer value at the specified index. Return -1 if the index is out of bounds
 */

int vector_get(int_array_t* array, int index) {
    if (index < 0 || index >= array->size)
        return -1;
    return array->elements[index];
}

/**
 * Sets the element at the specified index to a new value.
 *
 * @param array Pointer to the int_array_t structure
 * @param index The position where the element should be set
 * @param element The new integer value to set
 * @return 0 if successful, -1 if the index is out of bounds
 */

int vector_set(int_array_t* array, int index, int element) {

    if (index < 0 || index >= array->size)
        return -1;
    array->elements[index] = element;

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

int vector_insert(int_array_t* array, int index, int element) {

    if (index < 0 || index >= array->size)
        return -1;
    if (array->size >= VECTOR_CAPACITY)
        return -2;

    for (int i = array->size; i > index; i--) {
        int t = array->elements[i];
        array->elements[i] = array->elements[i-1];
        array->elements[i-1] = t;
    }

    array->elements[index] = element;

    return 0;
}

/**
 * Removes the element at the specified index, shifting subsequent elements.
 *
 * @param array Pointer to the int_array_t structure
 * @param index The position of the element to remove
 * @return 0 if successful, -1 if the index is out of bounds, -2 if the array is empty
 */

int vector_remove(int_array_t* array, int index) {
    if (array->size == 0)
        return -2;
    if (index < 0 || index >= array->size)
        return -1;
    for (int i = index; i < array->size; i++) {
        array->elements[i] = array->elements[i + 1];
    }
    array->size--;
    return 0;
}

/**
 * Resets size to 0.
 *
 * @param array Pointer to the int_array_t structure to clear
 */
void vector_clear(int_array_t* array) {
    array->size = 0;
}

#define KNRM  "\x1B[0m"
#define KRED  "\x1B[31m"
#define KGRN  "\x1B[32m"
#define KYEL  "\x1B[33m"
#define KBLU  "\x1B[34m"

int main(void) {
    int_array_t array;

    printf("%s=== Testing vector_init ===\n", KBLU);
    array.size = 5; /* assuming that size has some garbage value */
    vector_init(&array);
    printf("%svector_init: size = %d (expected: 0)\n\n", array.size == 0 ? KGRN : KRED, array.size);

    printf("%s=== Testing vector_push_back ===\n", KBLU);
    array.size = 0;
    int push_test1 = vector_push_back(&array, 10);
    printf("%svector_push_back(10) = %d (expected: 0), size = %d\n", push_test1 == 0 ? KGRN : KRED, push_test1,
           array.size);

    int push_test2 = vector_push_back(&array, 20);
    printf("%svector_push_back(20) = %d (expected: 0), size = %d\n", push_test2 == 0 ? KGRN : KRED, push_test2,
           array.size);

    int push_test3 = vector_push_back(&array, 30);
    printf("%svector_push_back(30) = %d (expected: 0), size = %d\n", push_test3 == 0 ? KGRN : KRED, push_test3,
           array.size);

    printf("%sArray after push_back: ", KYEL);
    vector_print(&array);
    printf("\n");

    printf("%s=== Testing vector_get ===\n", KBLU);
    int get_test1 = vector_get(&array, 0);
    printf("%svector_get(0) = %d (expected: 10)\n", get_test1 == 10 ? KGRN : KRED, get_test1);

    int get_test2 = vector_get(&array, 1);
    printf("%svector_get(1) = %d (expected: 20)\n", get_test2 == 20 ? KGRN : KRED, get_test2);

    int get_test3 = vector_get(&array, 2);
    printf("%svector_get(2) = %d (expected: 30)\n", get_test3 == 30 ? KGRN : KRED, get_test3);

    int get_test4 = vector_get(&array, 10);
    printf("%svector_get(10) = %d (expected: -1 - out of bounds)\n\n", get_test4 == -1 ? KGRN : KRED, get_test4);

    printf("%s=== Testing vector_set ===\n", KBLU);
    int set_test1 = vector_set(&array, 1, 25);
    printf("%svector_set(1, 25) = %d (expected: 0)\n", set_test1 == 0 ? KGRN : KRED, set_test1);

    int set_verify = vector_get(&array, 1);
    printf("%svector_get(1) after set = %d (expected: 25)\n", set_verify == 25 ? KGRN : KRED, set_verify);

    int set_test2 = vector_set(&array, 10, 100);
    printf("%svector_set(10, 100) = %d (expected: -1 - out of bounds)\n", set_test2 == -1 ? KGRN : KRED, set_test2);

    printf("%sArray after set: ", KYEL);
    vector_print(&array);
    printf("\n");

    printf("%s=== Testing vector_insert ===\n", KBLU);
    int insert_test1 = vector_insert(&array, 1, 15);
    printf("%svector_insert(1, 15) = %d (expected: 0), size = %d\n", insert_test1 == 0 ? KGRN : KRED, insert_test1,
           array.size);

    printf("%sArray after insert: ", KYEL);
    vector_print(&array);
    printf("\n");

    int insert_test2 = vector_insert(&array, 0, 5);
    printf("%svector_insert(0, 5) = %d (expected: 0), size = %d\n", insert_test2 == 0 ? KGRN : KRED, insert_test2,
           array.size);

    printf("%sArray after insert at beginning: ", KYEL);
    vector_print(&array);
    printf("\n");

    printf("%s=== Testing vector_remove ===\n", KBLU);
    int remove_test1 = vector_remove(&array, 2);
    printf("%svector_remove(2) = %d (expected: 0), size = %d\n", remove_test1 == 0 ? KGRN : KRED, remove_test1,
           array.size);

    printf("%sArray after remove: ", KYEL);
    vector_print(&array);
    printf("\n");

    int remove_test2 = vector_remove(&array, 10);
    printf("%svector_remove(10) = %d (expected: -1 - out of bounds)\n\n", remove_test2 == -1 ? KGRN : KRED,
           remove_test2);

    printf("%s=== Testing array capacity ===\n", KBLU);
    vector_clear(&array);
    for (int i = 0; i < VECTOR_CAPACITY; i++) {
        vector_push_back(&array, i * 10);
    }
    printf("%sFilled array to capacity (%d elements): ", KYEL, array.size);
    vector_print(&array);
    printf("\n");

    int capacity_test = vector_push_back(&array, 999);
    printf("%svector_push_back when full = %d (expected: -1)\n\n", capacity_test == -1 ? KGRN : KRED, capacity_test);

    printf("%s=== Testing vector_clear ===\n", KBLU);
    vector_clear(&array);
    printf("%svector_clear: size = %d (expected: 0)\n", array.size == 0 ? KGRN : KRED, array.size);

    int clear_remove_test = vector_remove(&array, 0);
    printf("%svector_remove on empty array = %d (expected: -2)\n\n", clear_remove_test == -2 ? KGRN : KRED,
           clear_remove_test);

    printf("%s=== All tests completed ===\n", KBLU);
    return 0;
}
