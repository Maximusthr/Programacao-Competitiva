#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n; cin >> n;

    string s;
    for (int i = 0; i < n - (n+3)/4; i++){
        s += '9';
    }
    for (int i = 0; i < (n+3)/4; i++){
        s += '8';
    }

    cout << s << "\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    int t; cin >> t;

    while(t--){
        solve();
    }
}