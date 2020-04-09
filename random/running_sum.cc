/*
 * Given an array find the contiguous subarray that sums to zero
 */

#include <iostream>
#include <vector>
#include <map>

using namespace std;

vector<int> range(vector<int>& nums){
    map<int, int> sums;

    int s = 0;
    vector<int> res;
    for(int i = 0; i < nums.size(); ++i){
        s += nums[i];
        if(!s){
            res.insert(res.begin(), nums.begin(), nums.begin() + i + 1);
            return res;
        }
        if(sums.count(s)){
            res.insert(res.begin(), nums.begin() + sums[s] + 1, nums.begin() + i + 1);
            return res;
        }else{
            sums[s] = i;
        }
    }

    return res;
}

int main(int argc, char **argv){
    int arr[7] = {1,1,-2,-2,-2,4,9};
    vector<int> t(arr, arr + 7);

    auto j = range(t);
    for(auto i : j){
        cout << i << "\t";
    }
    cout << endl;
}
            
