/*
 * Assign rooms to meetings such that they don't conflict. Minimize the room
 * numbers assigned. [start time, end time] format for the intervals
 */

#include <iostream>
#include <vector>
#include <map>

using namespace std;

struct Interval{
    int start;
    int end;
    int id;
    Interval(int s, int e, int i) : start(s), end(e), id(i){};
};

struct Node{
    int time;
    bool start;
    int id;
    Node(int t, bool s, int i) : time(t), start(s), id(i){};
};

bool compare(Node n1, Node n2){
        return n1.time < n2.time;
}

void assign(vector<Interval>& meetings){
    // Make the event list
    vector<Node> events;
    for(auto i : meetings){
        Node n1(i.start, true, i.id);
        Node n2(i.end, false, i.id);
        events.push_back(n1);
        events.push_back(n2);
    }

    sort(events.begin(), events.end(), compare);
    map<int, int> id_to_room;

    // Sweep line through the event list
    vector<bool>rooms(10, true);
    for(auto j : events){
        if(j.start){
            // Find the first meeting room
            int k;
            for(k = 0; k < rooms.size(); ++k){
                if(rooms[k]){
                    cout << "Meeting " << j.id << " is using room " << k << endl;
                    id_to_room[j.id] = k;
                    rooms[k] = false;
                    break;
                }
            }
            if(k == rooms.size()){cout << j.id << ":None" << endl;}
        }else{
            if(id_to_room.count(j.id)){
                cout << "Meeting " << j.id << "is freeing " << id_to_room[j.id] << endl;
                rooms[id_to_room[j.id]] = true;
                id_to_room.erase(j.id);
            }
        }
    }
}


int main(int argc, char **argv){
    vector<Interval> meetings;
    Interval i1(0, 5, 1); //1
    Interval i2(3, 7, 2); //2
    Interval i3(4, 6, 3); //3
    Interval i4(5, 9, 4); //1
    Interval i5(8, 12, 5); //2
    Interval i6(15, 19, 6); //1

    meetings.push_back(i1);
    meetings.push_back(i2);
    meetings.push_back(i3);
    meetings.push_back(i4);
    meetings.push_back(i5);
    meetings.push_back(i6);

    assign(meetings);
    return 0;
}
