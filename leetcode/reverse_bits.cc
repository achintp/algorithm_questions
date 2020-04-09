/*
 * Reverse bits of a given 32 bits unsigned integer.
 *
 * For example, given input 43261596 (represented in binary as 
 * 00000010100101000001111010011100), return 964176192 (represented in binary 
 * as 00111001011110000010100101000000).
 *
 * Follow up:
 * If this function is called many times, how would you optimize it?
 */

#include <iostream>

using namespace std;

uint32_t reverse_bits(uint32_t n){
        uint32_t res = 0;
        int counter = 32;
        while(counter){
                res = (res << 1) | (n & 1);
                n = n >> 1;
                counter--;
        }

        return res;
}

int main(int argc, char **argv){
        cout << reverse_bits(1) << endl;

        return 0;
}
