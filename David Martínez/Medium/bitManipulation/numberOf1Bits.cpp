#include <iostream>

using namespace std;

class Solution {
public:
    int hammingWeight(uint32_t n) {
        /*
        info
            input:
                - binary representation of an unsigned integer

            output:
                - return number of '1' bits it has

            constraints:
                - input must be a binary string of length 32

        example
            n = 00000000000000000000000000001011
            -> 3

            n = 00000000000000000000000010000000
            -> 1

            n = 11111111111111111111111111111101
            -> 32

        brute force solution
            traverse the string once with a pointer and count '1's

            complexity:
                runtime: O(n) -> n = 32 -> O(1)
                extra space: O(1)

        optimize
            best conceivable runtime: O(n) -> O(1)

        test
            - no '1's
            - multiple '1's
        */


        return __builtin_popcount(n);
    }
};