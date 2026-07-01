#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n; cin >> n;

    string s; cin >> s;

    if (n == 1){
        cout << 1 << "\n";
        return;
    }

    bool ok = true;
    for (int i = 1; i < n; i++){
        if (s[i] != s[i-1]) ok = false;
    }
    if (ok){
        cout << 1 << "\n";
        return;
    }

    char c = s[0];
    bool foi = false;
    bool foi2 = false;
    for (int i = 1; i < n; i++){
        if (c != s[i]) foi = true;
        if (foi && c == s[i]) foi2 = true;
    }

    bool foi3 = false;
    bool foi4 = false;
    char d = s[n-1];
    for (int i = n-2; i >= 0; i--){
        if (d != s[i]) foi3 = true;
        if (foi3 && d == s[i]) foi4 = true;
    }

    if (foi && foi2 && foi3 && foi4){
        cout << 1 << "\n";
    }
    else cout << 2 << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}