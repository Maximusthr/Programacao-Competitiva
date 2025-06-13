#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;


void solve(){
    int n; cin >> n;

    if (n == 1) {
        cout << -1 << "\n";
        return;
    }

    string s;
    for (int i = 0; i < n; i++){
        if (i == n-1) s += '4';
        else s += '7';
    }

    reverse(s.begin(), s.end());

    cout << s << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    int t; cin >> t;


    while(t--){
        solve();
    }
}