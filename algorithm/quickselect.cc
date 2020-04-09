/*Implementation of quickselect, useful for finding the jth 
 * order statistic in O(n) by using a divide and conquer to
 * recursively discard half the array at each point.
 *
 * Popular question based on this:
 * Find the median of an unsorted array in linear time
 *
 */

#include <iostream>
#include <vector>

using namespace std;

int quickselect(vector<int> nums, int j){
    if(nums.size() < j){return -1;}

    // Select a random pivot. I pick the midpoint
    int pivot = 0 + (nums.size() - 1)/2;
    
    // Divide the array into two based on which larger or
    // smaller than pivot element
    vector<int> smaller, larger;
    for(int index = 0; index < nums.size(); index++){
        if(index == pivot){continue;}
        if(nums[index] <= nums[pivot]){smaller.push_back(nums[index]);}
        else{larger.push_back(nums[index]);}
    }

    if(smaller.size() + 1 == j){return nums[pivot];}
    if(smaller.size() + 1 > j){return quickselect(smaller, j);}
    if(smaller.size() + 1 < j){return quickselect(larger, j - smaller.size() - 1);}

    return -1;
}

int main(int argc, char** argv){
    int inp[] = {2,6,5,1,4,3};
    vector<int> nums(inp, inp + sizeof(inp) / sizeof(int));
    cout << quickselect(nums, 5) << endl;

    return 0;
}
