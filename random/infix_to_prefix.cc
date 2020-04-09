/*
 * COnvert infix expression to postfix expression
 */

#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

map<char, int> precedence;

string convert(string infix){
    if(infix.empty()){return "";}
    vector<char> stack;
    string res;
    for(int i = 0; i < infix.size(); ++i){
        string num = "";
        while(infix[i] >= '0' && infix[i] <= '9'){
            num += infix[i++];
        }
        res += num;
        if(infix[i] != ' ' ){
            char op = infix[i];
            if(op == '('){
                stack.push_back(op);
                continue;
            }
            if(op == ')'){
                while(stack.back() != '('){
                    res += stack.back();
                    stack.pop_back();
                }
                stack.pop_back();
                continue;
            }
            while(!stack.empty()){
                if(precedence[stack.back()] >= precedence[op]){
                    res += stack.back();
                    stack.pop_back();
                }else{break;}
            }
           
            stack.push_back(op);
            
        }
    }
    while(!stack.empty()){
        res += stack.back();
        stack.pop_back();
    }
    return res;
}

int main(int argc, char **argv){
    string t(argv[1]);
    precedence['('] = 0;
    precedence['+'] = 1;
    precedence['-'] = 1;
    precedence['*'] = 2;
    precedence['/'] = 2;
    cout << convert("(4+8)*(6-5)/((3-2)*(2+2))") << endl;
}


