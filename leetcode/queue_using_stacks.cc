/*
 * Implement the following operations of a queue using stacks.
 *
 * push(x) -- Push element x to the back of queue.
 * pop() -- Removes the element from in front of queue.
 * peek() -- Get the front element.
 * empty() -- Return whether the queue is empty.
 */

#include <iostream>
#include <deque>
#include <vector>

using namespace std;

class Queue {
    public:
        void push(int x){
            if(stack.empty()){
                stack.push_back(x);
            }else{
                // transfer all to move stack
                for(auto i : stack){
                    move_stack.push_back(stack.back());
                    stack.pop_back();
                }
                stack.push_back(x);
                for(auto i : move_stack){
                    stack.push_back(move_stack.back());
                    move_stack.pop_back();
                }
            }
        }

        void pop(void){
            if(!stack.empty()){
                stack.pop_back();
            }
        }

        int peek(void){
            if(!stack.empty()){
                return stack.back();
            }else{
                return -1;
            }
        }

        bool empty(void){
            return stack.empty();
        }

        void print_queue(void){
            for(auto i : stack){
                cout << i << endl;
            }
            cout << endl;
        }

    private:

        vector<int> stack;
        vector<int> move_stack;
};

int main(int argc, char **argv){
    Queue q;

    q.push(1);
    q.push(2);
    q.push(3);

    q.print_queue();

    cout << q.peek() << endl;

    q.pop();

    cout << q.peek() << endl;

    q.pop();
    q.pop();

    cout << q.empty() << endl;

    return 0;
}
