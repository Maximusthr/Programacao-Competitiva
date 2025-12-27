#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    string s; cin >> s;

    int n = s.size();

    bool tem = false;
    int count = 0;
    for (int i = 0; i < n; i++){
        if (s[i] == 'Y') count++;
    }

    if (count >= 2) cout << "NO" << "\n";
    else cout << "YES" << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}