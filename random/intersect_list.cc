/*
 * Combine two unsorted lists...this wasnt supposed to be the question 
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void combine(vector<int>& l1, vector<int>& l2){
    if(!l1.empty() && !l2.empty()){
        sort(l1.begin(), l1.end());
        sort(l2.begin(), l2.end());

        vector<int> temp;
        int i, j;
        for(i = 0, j = 0; i < l1.size() && j < l2.size();){
            if(l1[i] < l2[j]){temp.push_back(l1[i++]);}
            else {temp.push_back(l2[j++]);}
        }

        temp.insert(temp.end(), l1.begin() + i, l1.end());
        temp.insert(temp.end(), l2.begin() + j, l2.end());

        for(auto i : temp){
            cout << i << "\t";
        }
        cout << endl;
    }
}

void intersect(vector<int>& l1, vector<int>& l2){
    if(!l1.empty() && !l2.empty()){
        sort(l1.begin(), l1.end());
        sort(l2.begin(), l2.end());

        for(int i  = 0, j = 0; i < l1.size() && j < l2.size(); ){
            if(l1[i] == l2[j]){cout << l1[i] << "\t"; ++i; ++j;}
            else{
                if(l1[i] < l2[j]){++i;}
                else{++j;}
            }
        }
    }
}

int main(int argc, char **argv){
    int arr1[] = {5,2,45,12,2,98,145, 121};
    int arr2[] = {12,53,89,121,0,533,1,539};
    vector<int> l1(arr1, arr1 + 8);
    vector<int> l2(arr2, arr2 + 8);

    intersect(l1, l2);
    return 0;
}
