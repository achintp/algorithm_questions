/*
 *Driver program for testing out graph algorithms
 */

#include<vector>
#include<math.h>
#include<iostream>
#include <stdio.h>

using namespace std;

int numSquares(int n){
        if(n==0){return 0;}
        vector<int> arr(n+1, 1000000);
        
        for(int i = 0; i <= sqrt(n); ++i){
                arr[i*i] = 1;
        }

        arr[0] = 0;
        arr[1] = 1;

        for(int i = 2; i <= n; ++i){
                int min = 10000000;
                for(int j = 0; j <= i; ++j){
                    cout << j << " " << i-j << " " << arr[j] << " " << arr[i-j] << endl; 
                    min = min < arr[j] + arr[i-j] ? min : arr[j] + arr[i-j];
                }
                cout << "Min is " << min << endl;
                arr[i] = min;
        }

        return arr[n];
}

int main(int argc, char **argv){
    int n = 12;

    std::cout << numSquares(n) << endl;    
}
