/*
 * Get the post order traversal of a binary tree from the pre and in.
 * This is an inefficient implementation since I'm making copies across
 * calls. Instead pass indices and vectors by references.
 */

#include <vector>
#include <string>

using namespace std;

void postit(vector<int> in, vector<int> pre){

    int root = pre.first();
    if(in.size() == 1){
            cout << " " << root;
            return;
    }
    vector<int> left_in;
    vector<int> right_in;
    vector<int>* point = &left;

    for(auto i : in){
            if(i==root){
                    point = &right;
                    continue;
            }else{
                    point->push_back(i);
            }
    }
    pre.erase(pre.begin());
    vector<int> left_pre(pre.begin(), pre.begin() + left_in.size());
    vector<int> right_pre(pre.begin() + left_in.size(), pre.end());
    
    postit(left_in, left_pre);
    postit(right_in, right_pre);

    cout << " " << root " ";
    return;            
}

int main(int argc, char **argv){
        int in_arr[] = {4,2,5,1,3,6}
