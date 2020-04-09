/*Given an array of integers, every element appears three times except for one.
 * Find that single one. *
 * Note:
 * Your algorithm should have a linear runtime complexity. Could you implement
 * it without using extra memory?
 *
 * For any general question of the form, an array has all elements which occur K
 * times except for one which occurs M times. Now we'll look at this from the
 * bit perspective. Looking at any bit, we want to maintain a state for each
 * of them, i.e, lets look at the example where every number in an array 
 * repeats 3 times except one which occurs less than 3 time.
 *
 * So we want to maintain the state of each bit such that whenever it's been
 * seen more than 3 times, it resets to 0. In order to count it we need three
 * different bits...lets call them a,b,c; a represents a bit seen once, b 
 * represents a bit seen twice and c is the incoming bit. So if a bit has not
 * been seen we set a, if a is set and we see it we set b and if b is set and 
 * we see it we reset. A sample truth tbale would be:
 *
 * a    b   c   --->   a   b
 * 0    0   0          0   0
 * 0    0   1          1   0
 * 1    0   0          1   0
 * 1    0   1          0   1
 * 0    1   0          0   1
 * 0    1   1          0   0
 *
 * c is the incoming bit so in case its the third time you see this bit being
 * then it resets. So this was for one bit. Instead, since we need to track each
 * bit for a 32 bit number, a and b can both be ints instead. Now we need to 
 * define the update rule to go along with the above state changes. So in this
 * case, we see that a gets set when a is 0 and b is 0 and c is 1 or a is 1 and 
 * b is 0 and c is 0. Hence, the update rule for a would be:
 * a = ~a&~b&c | a&~b&~c
 * Similarly for b it is
 * b = a&~b&c | ~a&b&~c
 *
 *
 * At the end of all of this, we need the remaining bits that are remaining.
 * Hence we have to return a | b, because the bit might have been seen once
 * or twice. 
 */

#include <iostream>
#include <vector>

using namespace std;

int singleNumberII(const vector<int>& nums){
        if(nums.empty()){return 0;}
        if(nums.size() == 1){return nums[0];}

        int a = 0;
        int b = 0;

        for(auto i : nums){
                int ta = a;
                int tb = b;

                a = (~ta&~tb&i) | (ta&~tb&~i);
                b = (ta&~tb&i) | (~ta&tb&~i);
        }

        return a | b;

}

int main(int argc, char **argv){

        int arr[] = {2,4,1,6,1,4,2,1,2,4};
        vector<int> nums(arr, arr + sizeof(arr)/sizeof(int));

        cout << singleNumberII(nums) << endl;

        return 0;
}


