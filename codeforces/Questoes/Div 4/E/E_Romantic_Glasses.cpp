#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n; cin >> n;

    vector<ll> arr(n);
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }
    
    map<ll, bool> freq;
    ll sum = 0;

    freq[0] = 1;

    for (int i = 0; i < n; i++){
        if (i % 2) arr[i] *= -1;

        sum += arr[i];

        if (freq[sum]){
            cout << "YES" << "\n";
            return;
        }

        freq[sum] = 1;
    }

    cout << "NO" << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}