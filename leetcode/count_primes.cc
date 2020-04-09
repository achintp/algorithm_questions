/*
 * Count the number of prime numbers less than a non-negative number, n.
 */

#include <iostream>
#include <vector>

using namespace std;

int count_primes(int n){
        if(n==0 || n == 1){return 0;}

        vector<bool> sieve;

        for(int i = 0; i <= n; ++i){
                sieve.push_back(true);
        }

        for(int ind = 2; ind*ind <= n; ind++){
                if(!sieve[ind]){continue;}
                else{
                        for(long prod = (ind)*(ind); prod <= n; prod += (ind)){
                                        sieve[prod] = false;
                         }
                }
        }

        int res = 0;
        int counter = 0;
        for(auto i : sieve){
            if(i){
                res += 1;
            }
            counter++;
        }

        return res-2;
}

int main(int argc, char **argv){
        cout << count_primes(49979) << endl;
        return 0;
}
