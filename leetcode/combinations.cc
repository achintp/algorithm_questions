/*
 * Given two integers n and k, return all possible combinations of k numbers out
 *  of 1 ... n.
 */


#include <iostream>
#include <vector>

using namespace std;

void BFS(int n, int k, vector<int>& path, vector<vector<int>>& res);

vector<vector<int>> combine(int n, int k){
        vector<vector<int>> res;
        if(n == 0 || k  > n){
                return res;
        }

        vector<int> path;

        if(n == 1 || k == n){
                for(int i = 1; i < n+1; ++i){
                        path.push_back(i);
                }
                res.push_back(path);
                return res;
        }

        BFS(n, k, path, res);
        return res;
}

void BFS(int n, int k, vector<int>& path, vector<vector<int>>& res){
        if(path.size() == k){
                for(auto i : path){
                        cout << i << "\t";
                }
                cout << endl;
                vector<int> temp(path.begin(), path.end());
                res.push_back(temp);
                return;
        }else{
                // Include this value in combination
                path.push_back(n);
                if(n-1 >= 0){
                    BFS(n-1, k, path, res);
                }

                // Don't include this value in combination
                path.pop_back();
                if(n-1 >= 0){
                    BFS(n-1, k, path, res);
                }
        }
}

int main(int argc, char **argv){
        vector<vector<int>> res;
        res = combine(4, 2);

      //  for(auto i : res){
      //          for(auto j : i){
      //                  cout << j << "\t";
      //          }
      //          cout << endl;
      //  }
}

