#include <stdint.h>
#include <stdio.h>


/**
 * Retrieves the bit value at the specified index in the given number.
 * 
 * @param number The integer number to extract the bit from
 * @param index The bit position (0-based, where 0 is the least significant bit)
 * @return The bit value at the specified index (0 or 1)
 */

int get_bit(int number, int index) {
       if (number >> index & 1 )
              return 1;
    return 0;
}

/**
 * Sets the bit at the specified index to 1 in the given number.
 *
 * @param number The integer number to modify
 * @param index The bit position to set (0-based, where 0 is the least significant bit)
 * @return The modified number with the bit set to 1 at the specified index
 */
int set_bit(int number, int index) {

      /* if (!(number >> index & 1 ))
                    number |= 1 << index;*/

    return number |= 1 << index;
}

/**
 * Clears the bit at the specified index to 0 in the given number.
 *
 * @param number The integer number to modify
 * @param index The bit position to clear (0-based, where 0 is the least significant bit)
 * @return The modified number with the bit cleared to 0 at the specified index
 */

int clear_bit(int number, int index) {

       if (!(number >> index & 1 ))
              return number &= 1 << index;
    return number ^= 1 << index;
}

/**
 * Flips (toggles) the bit at the specified index in the given number.
 * If the bit is 0, it becomes 1; if it's 1, it becomes 0.
 *
 * DON'T use ~ operator
 *
 * @param number The integer number to modify
 * @param index The bit position to flip (0-based, where 0 is the least significant bit)
 * @return The modified number with the bit flipped at the specified index
 */

int flip_bit(int number, int index) {
       if (!(number >> index & 1 ))
              return number |= 1 << index;
    return number ^= 1 << index;
}

/**
 * Checks the parity of the given number by counting the number of set bits.
 *
 * @param number The integer number to check
 * @return 0 if the number has even parity (even number of 1 bits), 1 if odd parity
 */

int check_parity(int number) {
       if((number >> 0 & 1 ))
              return 1;
    return 0;
}

int check_parity1(uint16_t number) {

       int count_of_0 = 0, count_of_1 = 0;

       for (int i = 0; i < sizeof(uint16_t) * 8; i++) {
              if (number >> i & 1)
                     count_of_1++;
              else
                     count_of_0++;
       }

       if (count_of_1 & 1)
              return 1;
       return 0;
}

/*
 * Flips (inverts) all bits in the given number without using bitwise NOT operation.
 *
 * @param number The integer number to invert
 * @return The number with all bits flipped (ones become zeros and vice versa)
 */

int flip_all_bits(int number) {

       for (int i = 0; i < sizeof(int) * 8; i++)
                     number = number ^ 1 << i;
    return number;
}

/**
 * Checks if the given number is a power of 2.
 * A number is a power of 2 if it has exactly one bit set.
 *
 * DON'T use loops.
 *
 * HINT: Write down binary representation of any power of 2 number (1, 2, 4, 8, 16, 32, 64, ...).
 *       Write down the same number in binary representation -1.
 *
 * @param number The integer number to check
 * @return 1 if the number is a power of 2, 0 otherwise
 */
int is_power_of_2(int number) {
       if (number & (number - 1))
              return 0;
       if (!number)
              return 0;
    return 1;
}

#define KNRM  "\x1B[0m"
#define KRED  "\x1B[31m"
#define KGRN  "\x1B[32m"
#define KYEL  "\x1B[33m"
#define KBLU  "\x1B[34m"

int main(void) {
    printf("%s=== Testing get_bit ===\n", KBLU);
    int get_test1 = get_bit(0b00001010, 0);
    printf("%sget_bit(0b00001010, 0) = %d (expected: 0)\n", get_test1 == 0 ? KGRN : KRED, get_test1);

    int get_test2 = get_bit(0b00001010, 1);
    printf("%sget_bit(0b00001010, 1) = %d (expected: 1)\n", get_test2 == 1 ? KGRN : KRED, get_test2);

    int get_test3 = get_bit(0b00001010, 3);
    printf("%sget_bit(0b00001010, 3) = %d (expected: 1)\n", get_test3 == 1 ? KGRN : KRED, get_test3);

    int get_test4 = get_bit(0b10000000, 7);
    printf("%sget_bit(0b10000000, 7) = %d (expected: 1)\n", get_test4 == 1 ? KGRN : KRED, get_test4);

    int get_test5 = get_bit(0, 5);
    printf("%sget_bit(0, 5) = %d (expected: 0)\n\n", get_test5 == 0 ? KGRN : KRED, get_test5);

    printf("%s=== Testing set_bit ===\n", KBLU);
    int set_test1 = set_bit(0b00000000, 0);
    printf("%sset_bit(0b00000000, 0) = 0b%08d (expected: 0b00000001, decimal: %d)\n",
           set_test1 == 0b00000001 ? KGRN : KRED, set_test1, set_test1);

    int set_test2 = set_bit(0b00000000, 5);
    printf("%sset_bit(0b00000000, 5) = 0b%08d (expected: 0b00100000, decimal: %d)\n",
           set_test2 == 0b00100000 ? KGRN : KRED, set_test2, set_test2);

    int set_test3 = set_bit(0b10000000, 1);
    printf("%sset_bit(0b10000000, 1) = 0b%08d (expected: 0b10000010, decimal: %d)\n",
           set_test3 == 0b10000010 ? KGRN : KRED, set_test3, set_test3);

    int set_test4 = set_bit(0b00000010, 1);
    printf("%sset_bit(0b00000010, 1) = 0b%08d (expected: 0b00000010, decimal: %d)\n",
           set_test4 == 0b00000010 ? KGRN : KRED, set_test4, set_test4);

    int set_test5 = set_bit(0b00001111, 7);
    printf("%sset_bit(0b00001111, 7) = 0b%08d (expected: 0b10001111, decimal: %d)\n\n",
           set_test5 == 0b10001111 ? KGRN : KRED, set_test5, set_test5);

    printf("%s=== Testing clear_bit ===\n", KBLU);
    int clear_test1 = clear_bit(0b11111111, 0);
    printf("%sclear_bit(0b11111111, 0) = 0b%08d (expected: 0b11111110, decimal: %d)\n",
           clear_test1 == 0b11111110 ? KGRN : KRED, clear_test1, clear_test1);

    int clear_test2 = clear_bit(0b11111111, 5);
    printf("%sclear_bit(0b11111111, 5) = 0b%08d (expected: 0b11011111, decimal: %d)\n",
           clear_test2 == 0b11011111 ? KGRN : KRED, clear_test2, clear_test2);

    int clear_test3 = clear_bit(0b10000010, 7);
    printf("%sclear_bit(0b10000010, 7) = 0b%08d (expected: 0b00000010, decimal: %d)\n",
           clear_test3 == 0b00000010 ? KGRN : KRED, clear_test3, clear_test3);

    int clear_test4 = clear_bit(0b00000000, 3);
    printf("%sclear_bit(0b00000000, 3) = 0b%08d (expected: 0b00000000, decimal: %d)\n",
           clear_test4 == 0b00000000 ? KGRN : KRED, clear_test4, clear_test4);

    int clear_test5 = clear_bit(0b10101010, 1);
    printf("%sclear_bit(0b10101010, 1) = 0b%08d (expected: 0b10101000, decimal: %d)\n\n",
           clear_test5 == 0b10101000 ? KGRN : KRED, clear_test5, clear_test5);

    printf("%s=== Testing flip_bit ===\n", KBLU);
    int flip_test1 = flip_bit(0b00000000, 0);
    printf("%sflip_bit(0b00000000, 0) = 0b%08d (expected: 0b00000001, decimal: %d)\n",
           flip_test1 == 0b00000001 ? KGRN : KRED, flip_test1, flip_test1);

    int flip_test2 = flip_bit(0b00000001, 0);
    printf("%sflip_bit(0b00000001, 0) = 0b%08d (expected: 0b00000000, decimal: %d)\n",
           flip_test2 == 0b00000000 ? KGRN : KRED, flip_test2, flip_test2);

    int flip_test3 = flip_bit(0b10101010, 3);
    printf("%sflip_bit(0b10101010, 3) = 0b%08d (expected: 0b10100010, decimal: %d)\n",
           flip_test3 == 0b10100010 ? KGRN : KRED, flip_test3, flip_test3);

    int flip_test4 = flip_bit(0b11111111, 5);
    printf("%sflip_bit(0b11111111, 5) = 0b%08d (expected: 0b11011111, decimal: %d)\n",
           flip_test4 == 0b11011111 ? KGRN : KRED, flip_test4, flip_test4);

    int flip_test5 = flip_bit(0b01010101, 7);
    printf("%sflip_bit(0b01010101, 7) = 0b%08d (expected: 0b11010101, decimal: %d)\n\n",
           flip_test5 == 0b11010101 ? KGRN : KRED, flip_test5, flip_test5);

    printf("%s=== Testing check_parity ===\n", KBLU);
    int parity_test1 = check_parity(0b00000000);
    printf("%scheck_parity(0b00000000) = %d (expected: 0 - even)\n", parity_test1 == 0 ? KGRN : KRED, parity_test1);

    int parity_test2 = check_parity(0b00000001);
    printf("%scheck_parity(0b00000001) = %d (expected: 1 - odd)\n", parity_test2 == 1 ? KGRN : KRED, parity_test2);

    int parity_test3 = check_parity(0b00000011);
    printf("%scheck_parity(0b00000011) = %d (expected: 1 - odd)\n", parity_test3 == 1 ? KGRN : KRED, parity_test3);

    int parity_test4 = check_parity(0b11111111);
    printf("%scheck_parity(0b11111111) = %d (expected: 1 - odd)\n", parity_test4 == 1 ? KGRN : KRED, parity_test4);

    int parity_test5 = check_parity(0b10101010);
    printf("%scheck_parity(0b10101010) = %d (expected: 0 - even)\n", parity_test5 == 0 ? KGRN : KRED, parity_test5);

    int parity_test6 = check_parity(0b10101011);
    printf("%scheck_parity(0b10101011) = %d (expected: 1 - odd)\n\n", parity_test6 == 1 ? KGRN : KRED, parity_test6);

    printf("%s=== Testing check_parity1 ===\n", KBLU);
    int parity_test11 = check_parity1(0b00000000);
       printf("%sheck_parity1(0b00000000) = %d (expected: 0 - even)\n", parity_test11 == 0 ? KGRN : KRED, parity_test11);
       int parity_test12 = check_parity1(0b00101001);
       printf("%sheck_parity1(0b00101001) = %d (expected: 1 - odd)\n", parity_test12 == 1 ? KGRN : KRED, parity_test12);
       int parity_test13 = check_parity1(0b00111001);
       printf("%sheck_parity1(0b00101001) = %d (expected: 0 - odd)\n", parity_test13 == 0 ? KGRN : KRED, parity_test13);

    printf("%s=== Testing flip_all_bits ===\n", KBLU);
    int flip_all_test1 = flip_all_bits(0b00000000);
    printf("%sflip_all_bits(0b00000000) = %d (expected: -1)\n", flip_all_test1 == -1 ? KGRN : KRED, flip_all_test1);

    int flip_all_test2 = flip_all_bits(0b11111111);
    printf("%sflip_all_bits(0b11111111) = %d (expected: -256)\n", flip_all_test2 == -256 ? KGRN : KRED, flip_all_test2);

    int flip_all_test3 = flip_all_bits(0b10101010);
    printf("%sflip_all_bits(0b10101010) = %d (expected: -171)\n", flip_all_test3 == -171 ? KGRN : KRED, flip_all_test3);

    int flip_all_test4 = flip_all_bits(0);
    printf("%sflip_all_bits(0) = %d (expected: -1)\n", flip_all_test4 == -1 ? KGRN : KRED, flip_all_test4);

    int flip_all_test5 = flip_all_bits(42);
    printf("%sflip_all_bits(42) = %d (expected: -43)\n\n", flip_all_test5 == -43 ? KGRN : KRED, flip_all_test5);

    printf("%s=== Testing is_power_of_2 ===\n", KBLU);
    int pow2_test1 = is_power_of_2(1);
    printf("%sis_power_of_2(1) = %d (expected: 1)\n", pow2_test1 == 1 ? KGRN : KRED, pow2_test1);

    int pow2_test2 = is_power_of_2(2);
    printf("%sis_power_of_2(2) = %d (expected: 1)\n", pow2_test2 == 1 ? KGRN : KRED, pow2_test2);

    int pow2_test3 = is_power_of_2(4);
    printf("%sis_power_of_2(4) = %d (expected: 1)\n", pow2_test3 == 1 ? KGRN : KRED, pow2_test3);

    int pow2_test4 = is_power_of_2(8);
    printf("%sis_power_of_2(8) = %d (expected: 1)\n", pow2_test4 == 1 ? KGRN : KRED, pow2_test4);

    int pow2_test5 = is_power_of_2(16);
    printf("%sis_power_of_2(16) = %d (expected: 1)\n", pow2_test5 == 1 ? KGRN : KRED, pow2_test5);

    int pow2_test6 = is_power_of_2(32);
    printf("%sis_power_of_2(32) = %d (expected: 1)\n", pow2_test6 == 1 ? KGRN : KRED, pow2_test6);

    int pow2_test7 = is_power_of_2(64);
    printf("%sis_power_of_2(64) = %d (expected: 1)\n", pow2_test7 == 1 ? KGRN : KRED, pow2_test7);

    int pow2_test8 = is_power_of_2(128);
    printf("%sis_power_of_2(128) = %d (expected: 1)\n", pow2_test8 == 1 ? KGRN : KRED, pow2_test8);

    int pow2_test9 = is_power_of_2(0);
    printf("%sis_power_of_2(0) = %d (expected: 0)\n", pow2_test9 == 0 ? KGRN : KRED, pow2_test9);

    int pow2_test10 = is_power_of_2(3);
    printf("%sis_power_of_2(3) = %d (expected: 0)\n", pow2_test10 == 0 ? KGRN : KRED, pow2_test10);

    int pow2_test11 = is_power_of_2(5);
    printf("%sis_power_of_2(5) = %d (expected: 0)\n", pow2_test11 == 0 ? KGRN : KRED, pow2_test11);

    int pow2_test12 = is_power_of_2(6);
    printf("%sis_power_of_2(6) = %d (expected: 0)\n", pow2_test12 == 0 ? KGRN : KRED, pow2_test12);

    int pow2_test13 = is_power_of_2(15);
    printf("%sis_power_of_2(15) = %d (expected: 0)\n", pow2_test13 == 0 ? KGRN : KRED, pow2_test13);

    int pow2_test14 = is_power_of_2(100);
    printf("%sis_power_of_2(100) = %d (expected: 0)\n\n", pow2_test14 == 0 ? KGRN : KRED, pow2_test14);

    printf("%s=== All tests completed ===\n", KBLU);

    return 0;
}