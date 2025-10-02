#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n, k; cin >> n >> k;

    vector<ll> arr(n);
    map<ll, ll> freq;
    for (int i = 0; i < n; i++){
        cin >> arr[i];
        freq[arr[i]]++;
    }    

    for (auto [x, y] : freq){
        if (y > 1){
            freq[x+k] += y-1;
        }
    }

    for (int i = 0; i < 10000000; i++){
        if (freq[i] == 0){
            cout << i << "\n";
            return;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}