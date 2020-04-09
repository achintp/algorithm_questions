/*
 * Print out the text form of all numbers between 1 - 1000
 */

#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <map>

using namespace std;

map<int, vector<string>> convert;
map<int, string> diff;

string print_text(int num){
    if(!num){return "zero";}
    
    if(num == 10000){return "one thousand";}

    int n = num;
    int sz = -1;
    while(n){
        sz += 1;
        n /= 10;
    }

    string res = "";
    while(num&&sz>=0){
        int k  =num/pow(10,sz);
        if(sz == 1){
            if(k == 1){
                res += " " + diff[num];
                return res;
            }
            res += " " + convert[pow(10,sz)][k];
        }else{
            res += " " + convert[0][k];
            res += "hundred";
        }
        num /= pow(10, sz--);
    }

    return res;
}

int main(int argc, char** argv){
    convert[0][0] = "";
    convert[0][1] = "one";
    convert[0][2] = "two";
    convert[0][3] = "three";
    convert[0][4] = "four";
    convert[0][5] = "five";
    convert[0][6] = "six";
    convert[0][7] = "seven";
    convert[0][8] = "eight";
    convert[0][9] = "nine";
    convert[1][0] = "and";
    convert[1][1] = "dasd";
    convert[1][2] = "twenty";
    convert[1][3] = "thirty";
    convert[1][4] = "fourty";
    convert[1][5] = "fifty";
    convert[1][6] = "sixty";
    convert[1][7] = "seventy";
    convert[1][8] = "eighty";
    convert[1][9] = "ninety";
    
    diff[10] = "ten";
    diff[11] = "eleven";
    diff[12] = "twelve";
    diff[13] = "thirteen";
    diff[14] = "fourteen";
    diff[15] = "fifteen";
    diff[16] = "sixteen";
    diff[17] = "seventeen";
    diff[18] = "eighteen";
    diff[19] = "nineteen";

    int num = atoi(argv[0]);

    cout << print_text(num) << endl;
    
}
