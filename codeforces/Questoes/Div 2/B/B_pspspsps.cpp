#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n; cin >> n;

    string s; cin >> s;

    // s -> pi ... pn
    if (s[0] == 's') s[0] = '.';

    // p -> p1 ... pi
    if (s[n-1] == 'p') s[n-1] = '.';

    bool achou_s = false, achou_p = false;
    for (int i = 0; i < n; i++){
        if (s[i] == 'p') achou_p = 1;
        if (s[i] == 's') achou_s = 1;
    }

    cout << (achou_s && achou_p ? "NO" : "YES") << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}