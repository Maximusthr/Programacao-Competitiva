#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    string s; cin >> s;

    int c1 = (s[0] - '0') + (s[1] - '0') + (s[2] - '0');
    int c2 = (s[3] - '0') + (s[4] - '0') + (s[5] - '0');

    cout << (c1 == c2 ? "YES" : "NO") << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}