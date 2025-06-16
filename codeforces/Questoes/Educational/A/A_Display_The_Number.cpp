#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n; cin >> n;

    if (n == 2) {
        cout << 1 << "\n";
        return;
    }
    else if (n == 3){
        cout << 7 << "\n";
        return;
    }

    string s;

    while (n >= 2){
        s += '1';
        n -= 2;
    }
    if (n == 1){
        s[0] = '7';
    }  

    cout << s << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    int t; cin >> t;

    while(t--){
        solve();
    }
}