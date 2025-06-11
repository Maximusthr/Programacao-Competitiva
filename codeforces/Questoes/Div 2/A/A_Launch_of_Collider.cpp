#include <bits/stdc++.h>

using namespace std;

const int MAX = 1e9+1;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;

    string x; cin >> x;
    vector<int> arr(t);
    for (int &i : arr) cin >> i;

    bool ok = false;
    int dist = MAX;
    for (int i = 0; i < t-1; i++){
        if (x[i] == 'R' && x[i+1] == 'L'){
            int tempo = (arr[i+1] - arr[i])/2;
            dist = min(dist, tempo);
            ok = true;
        }
    }

    cout << (ok ? dist : -1) << "\n";
}
