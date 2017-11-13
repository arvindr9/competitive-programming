#include <bits/stdc++.h>

using namespace std;

int main() {
    int days;
    cin >> days;
    int arr[days];
    for (int i = 0; i < days; i++) {
        int a;
        cin >> a;
        arr[i] = a;
    }
    map<int, int> lastVisit;
    int index = 0;
    for (auto i: arr) {
        lastVisit[i] = index;
        index++;  
    }
    int min = 200001;
    int ans = 0;
    for (auto visit: lastVisit) {
        //cout << visit.first << " " << visit.second << "\n";
        if(visit.second < min) {
            min = visit.second;
            ans = visit.first; 
        }
    }
    cout << ans;
}
