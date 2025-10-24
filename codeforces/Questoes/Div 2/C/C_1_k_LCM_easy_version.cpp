#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n, k; cin >> n >> k;

    if (n % 2 == 0 && n/2 % 2 == 0){
        int v = n/2;
        if (v == 0) v++;
        
        // 16 -> 8 4 4

        cout << v << " " << v/2 << " " << v/2 << "\n";
    }
    else if (n % 2 == 1) {
        cout << n/2 << " " << n/2 << " " << 1 << "\n";
    }
    else {
        cout << n/2 - 1 << " " << n/2 - 1 << " " << 2 << "\n";
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}