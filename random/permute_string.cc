/*
 * Given a string return all possible permutations
 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<string> rec_permute(string, vector<string>);

vector<string> permutations(string word){
    vector<string> res;
    if(word.empty() || word.size() < 2){
        res.push_back(word);
        return res;
    }

    res = rec_permute(word, res);
    return res;
}

vector<string> rec_permute(string word, vector<string> results){
    if(word.size() == 1){
        results.push_back(word);
        return results;
    }else{
        char c = word[0];
        word.erase(0,1);
        results = rec_permute(word, results);
        // Coming up from bottom
        vector<string> temp;
        for(auto i : results){
            for(int j = 0; j <= i.size(); ++j){
                string t(i);
                t.insert(t.begin() + j, c);
                temp.push_back(t);
            }
        }
        return temp;
    }
}

int main(int argc, char** argv){
    string t("abcd");
    auto res = permutations(t);
    cout << res.size() << endl;
    for(auto i : res){
        cout << i << endl;
    }
    return 0;
}
