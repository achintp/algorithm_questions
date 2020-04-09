#include <iostream>
#include <vector>

using namespace std;

void min_change(vector<int>& change, int n){
    vector<int> dp(n+1, 10000);
    dp[0] = 0;
    for(auto i : change){
        dp[i] = 1;
    }

    for(int i = 2; i <= n; ++i){
        for(auto j : change){
            if(i - j >= 0){
                dp[i] = min(dp[i-j] + 1, dp[i]);
            }
        }
    }

    cout << dp[n] << endl;
}

vector<vector<int>> r;

void num_ways(vector<int> change, int val, vector<int> res){
    // Recursive way
    for(auto i : change){
        cout << i << "\t";
    }
    cout << endl;
    cout<< "val: " << val << endl;
    if(val == 0){r.push_back(res); return;}
    if(change.empty()){return;}
    if(val < 0){return;}
    else{
        res.push_back(change.back());
        num_ways(change, val - change.back(), res);
        res.pop_back();
        change.pop_back();
        num_ways(change, val, res); 
    }
}

void num_ways_dp(vector<int>& change, int val){
    vector<vector<int>> dp(val+1, vector<int>(change.size(), 0));

    for(int i = 0; i < change.size(); ++i){
        dp[0][i] = 1;
    }

    for(int i = 1; i <= val; ++i){
        for(int j = 0; j < change.size(); ++j){
            // With jth
            int x = i - change[j] >= 0 ? dp[i-change[j]][j] : 0;
            //Without jth
            int y = j >= 1 ? dp[i][j-1] : 0;
            dp[i][j] = x + y;
        }
    }

    cout <<  dp[val][change.size() - 1] << endl;
}   

int main(int argc, char **argv){
    int arr[] = {1,3,6,7};
    vector<int> a(arr, arr + sizeof(arr)/sizeof(int));
    min_change(a, 13);

    vector<int> res;
    num_ways(a, 13, res);
    cout << "size" << r.size() << endl;
    for(auto i : r){
        for(auto j : i){
            cout << j << "\t";
        }
        cout << endl;
    }

    num_ways_dp(a, 13);
    return 0;
}
