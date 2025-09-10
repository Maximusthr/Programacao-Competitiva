#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int a, b; cin >> a >> b;
    
    if (a == b){
        cout << 0 << "\n";
        return;
    }

    if (a % b == 0 || b % a == 0){
        cout << 1 << "\n";
        return;
    }

    cout << 2 << "\n";
    
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}