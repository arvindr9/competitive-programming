#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    int notes[n+1] = {0};
    for (int i = 1; i <= n; i++) {
        int a;
        cin >> a;
        notes[i] = a;
    }
    /*map<int, int> timeToRoom;
    timeToRoom[0] = 1;
    for(int day = 1; day <= n; day++) {
        int prevTime = arr[i];
        if(timeToRoom.count(prevTime)) {
            timeToRoom[day] = timeToRoom[prevTime];
        } else {
            timeToRoom[day] = elt;
        }
    }*/
    set<int> times;
    map<int, int> roomToTime;
    map<int, int> timeToRoom;
    times.insert(0);
    roomToTime[1] = 0;
    timeToRoom[0] = 1;
    for(int day = 1; day <= n; day++) {
        int currNote = notes[day];
        times.insert(day);
        if(times.find(currNote)!=times.end()) {
            times.erase(currNote);
            int room = timeToRoom[currNote];
            roomToTime[room] = day;
            timeToRoom[day] = room;
        } else {
            times.insert(day);
            int room = roomToTime.size()+1;
            roomToTime[room] = day;  
            timeToRoom[day] = room;
        }
    }
    cout << roomToTime.size();

    

}
