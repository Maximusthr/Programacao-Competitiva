#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n, k; cin >> n >> k;

    string s; cin >> s;

    int um = 0;
    for (int i = 0; i < n; i++){
        if (s[i] == '1'){
            um++;
        }
    }

    if (k >= um || k > n/2) cout << "Alice" << "\n";
    else cout << "Bob" << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}