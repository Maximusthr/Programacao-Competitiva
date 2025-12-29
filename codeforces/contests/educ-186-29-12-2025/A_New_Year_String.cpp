#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n; cin >> n;

    string s; cin >> s;
    bool seis = false;
    bool cinco = false;

    for (int i = 0; i < n-3; i++){
        string aux = s.substr(i, 4);
        if (aux == "2025") cinco = true;
        if (aux == "2026") seis = true;
    }

    if (seis || !cinco) cout << 0 << "\n";
    else cout << 1 << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}