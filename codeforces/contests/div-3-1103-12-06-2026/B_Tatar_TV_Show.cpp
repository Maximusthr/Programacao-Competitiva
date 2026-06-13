#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n, k; cin >> n >> k;

    string s; cin >> s;

    for (int i = 0; i < n-k; i++){
        if (s[i] == '1' && s[i+k] == '1'){
            s[i] = '0';
            s[i+k] = '0';
        }
        if (s[i] == '1' && s[i+k] == '0' && i+k < n-k){
            s[i] = '0';
            s[i+k] = '1';
        }
    }

    // cout << s << "\n";
    for (int i = 0; i < n; i++){
        if (s[i] == '1'){
            cout << "NO" << "\n";
            return;
        }
    }
    cout << "YES" << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}