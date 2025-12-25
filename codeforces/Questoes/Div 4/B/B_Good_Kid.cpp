#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n; cin >> n;

    pair<int, int> v = {INF, -1};
    vector<int> arr(n);
    for (int i = 0; i < n; i++){
        cin >> arr[i];

        if (v.first > arr[i]){
            v = {arr[i], i};
        }
    }

    arr[v.second]++;

    int val = arr[0];
    for (int i = 1; i < n; i++){
        val *= arr[i];
    }

    cout << val << "\n"; 
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}