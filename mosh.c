#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>



// 1. Implement bitPopulationCount:
//
// return the number of bits set to 1 in the given integer
size_t bitPopulationCount(uint64_t n)
{
    int count=0;
    while (n != 0) {
        count += n & 1;
        n >>= 1;
    }
    return count;
}

//
// 2. Implement equalizePopulationCounts:
//
// Input: You are given an integer, but you are not disclosed to the state of each specific bit in it (e.g. cannot query its value)
// Task: Split the input bit set into two subsets, and have the two populations equalize.
// Allowed:
// * Calling your implemented bitPopulationCount
// * Manipulating bits, based on the initial state
// Not allowed:
// * Query bit values, e.g. if (n & 1)
// * Forcing bit to a fixed value,  e.g. n |= 1, n ^= n
// (Masking bits for splitting into subsets, is not considered forcing)
// Extra challenge:
// * Allow one call to bitPopulationCount, O(1)
//
int equalizePopulationCounts_solution(uint64_t undisclosed_bit_set, uint64_t* bit_subset1, uint64_t* bit_subset2)
{
    size_t count = bitPopulationCount(undisclosed_bit_set);
    uint64_t mask = (1ull << count) - 1;  // mask width same to <population count>, pitfall: avoid 1 treated as int (32bit) during compilation!
    
    const size_t sizeInBits = sizeof(undisclosed_bit_set) * 8;
    if ((0 == count) || (sizeInBits == count)) {
        mask = (1ull << (sizeInBits / 2)) - 1;  // mask half of the bits, pitfall: avoid 1 treated as int (32bit) during compilation!
        *bit_subset1 = undisclosed_bit_set & mask;     // subset is either all 1 or all 0
        *bit_subset2 = undisclosed_bit_set & ~mask;    // original bits, excluding subset1, subset is either all 1 or all 0
    }
    else {
        // split by picking exactly <population count> bits into one subset, the rest of the bits in the other subset:
        *bit_subset1 = ~undisclosed_bit_set & mask;    // flip bits to set desired amount of 1s, extract a subset of size same to <population count>
        *bit_subset2 = undisclosed_bit_set & ~mask;    // original bits, excluding subset1
    }

    return bitPopulationCount(*bit_subset1) == bitPopulationCount(*bit_subset2);
}

int main(){
    int n = 66775235;
    printf("%zu\n " ,bitPopulationCount(n));

    uint64_t * a = malloc(sizeof(uint64_t));
    uint64_t * b = malloc(sizeof(uint64_t));
    equalizePopulationCounts_solution(n, a, b);
    printf("a= %llu %zu\n" ,*a,bitPopulationCount(*a));
    printf("b= %llu %zu\n" ,*b ,bitPopulationCount(*b));
    free(a);
    free(b);


}