/* 
 *Make a thread safe id pool assignment
*/

#include <iostream>
#include <map>
#include <thread>
#include <mutex>
#include <chrono>

using namespace std;

void unassign(int);

map<int, bool> assigned;
mutex mtx;
int counter;

void assign(int n){
    mtx.lock();
    int start = counter;
    while(assigned.count(counter)){
        counter = (counter+1)%n;
    }
    assigned[counter] = true;
    int res = counter;
    cout << "id " << res << " assigned" << endl;
    mtx.unlock();
    

    this_thread::sleep_for(chrono::seconds(2));
    unassign(res);

}

void unassign(int k){
    mtx.lock();
    assigned.erase(k);
    cout << "id " << k << " released" << endl;
    mtx.unlock();
}

int main(int argc, char** argv){
    counter = 0;
    for(int i = 0; i <= 10000; ++i){
        thread t(assign, 100);
    }

    return 0;
}
    
