/*
 * Text form of numbers from 1 to 1000
 */

#include <iostream>
#include <vector>
#include <map>
#include <sstream>
#include <cmath>

using namespace std;

vector<vector<string>> i_to_t(2, vector<string>(20, ""));

void text(int n){
    int counter = -1;
    int temp = n;
    while(temp){
        counter++;
        temp /= 10;
    }
    string res;

    while(counter != -1){
        int t = n / pow(10, counter);
        if(counter == 2){
            res += i_to_t[0][t];
            res += " hundred";
        }    
        if(counter == 1){
            if(n < 20 && n > 9){
                res += i_to_t[0][n];
                counter = -1;
                continue;
            }else{
                res += i_to_t[1][t];
                res += " ";
            }
        }
        if(!counter){
            res += i_to_t[0][t];
        }
        counter--;
        n /= 10;
    }

    cout << res << endl;
}

int main(int argc, char **argv){

    i_to_t[0][0] = "";
    i_to_t[0][1] = "one";
    i_to_t[0][2] = "two";
    i_to_t[0][3] = "three";
    i_to_t[0][4] = "four";
    i_to_t[0][5] = "five";
    i_to_t[0][6] = "six";
    i_to_t[0][7] = "seven";
    i_to_t[0][8] = "eight";
    i_to_t[0][9] = "nine";
    i_to_t[0][10] = "ten";
    i_to_t[0][11] = "eleven";
    i_to_t[0][12] = "twelve";
    i_to_t[0][13] = "thirteen";
    i_to_t[0][14] = "fourteen";
    i_to_t[0][15] = "fifteen";
    i_to_t[0][16] = "sixteen";
    i_to_t[0][17] = "seventeen";
    i_to_t[0][18] = "eighteen";
    i_to_t[0][19] = "nineteen";
    i_to_t[1][0] = "and";
    i_to_t[1][2] = "twenty";
    i_to_t[1][3] = "thirty";
    i_to_t[1][4] = "fourty";
    i_to_t[1][5] = "fifty";
    i_to_t[1][6] = "sixty";
    i_to_t[1][7] = "seventy";
    i_to_t[1][8] = "eighty";
    i_to_t[1][9] = "ninety";

    int n;
    istringstream ss(argv[1]);
    ss >> n;
    cout << n << endl;
    text(n);
    return 0;
}


