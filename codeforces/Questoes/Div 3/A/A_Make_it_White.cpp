#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n; cin >> n;
    string s; cin >> s;

    int first = -1, last = -1;
    for (int i = 0; i < n; i++){
        if (s[i] == 'B' && first == -1){
            first = i;
        } 
        if (s[i] == 'B') last = i;
    }

    if (first == -1) cout << 0 << "\n";
    else cout << last-first+1 << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}