/* 
 * Make a calculator the parses an input string
 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int calculate(string expr){
    if(expr == ""){return 0;}

    vector<char> stack;
    for(auto i : expr){
        if(i == "*" || i == "+" || i == "-" || i == "/"){

