#include <bits/stdc++.h>

using namespace std;

int main() {
    int arr[6];
    int sum = 0;
    for (int i = 0; i < 6; i++) {
        int a;
        cin >> a;
        sum += a;
        arr[i] = a;
    }
    string ans = "NO";
    for (int i = 0; i < 4; i++) {
        for (int j = i+1; j < 5; j++) {
            for(int k = j+1; k < 6; k++) {
                if(arr[i]+arr[j]+arr[k] == sum/2) ans = "YES";
            } 
        }
    }
    if(sum%2 == 1) {
        ans = "NO";
    }
    cout << ans;
    
}
