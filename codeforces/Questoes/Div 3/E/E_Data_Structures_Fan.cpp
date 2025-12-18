#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n; cin >> n;

    vector<int> arr(n);
    for (auto &i : arr) cin >> i;

    string s; cin >> s;

    int G0 = 0, G1 = 0;

    for (int i = 0; i < n; i++){
        if (s[i] == '1') G1 ^= arr[i];
        else G0 ^= arr[i];
    }

    vector<int> prefix(n+2);
    for (int i = 0; i < n; i++){
        prefix[i+1] = (prefix[i] ^ arr[i]);
    }

    int q; cin >> q;
    while(q--){
        int v; cin >> v;
        if (v == 2){
            int x; cin >> x;
            cout << (x == 1 ? G1 : G0) << " ";
        }
        else {
            int l, r; cin >> l >> r;
            G0 = G0 ^ (prefix[r] ^ prefix[l-1]);
            G1 = G1 ^ (prefix[r] ^ prefix[l-1]);
        }
    }
    cout << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}