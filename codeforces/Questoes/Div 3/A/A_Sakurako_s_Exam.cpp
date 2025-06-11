#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int a, b; cin >> a >> b;

    if (a % 2 || (a == 0 && b % 2)) {
        cout << "NO" << "\n";
        return;
    }
    cout << "YES" << "\n";
    return;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    int t; cin >> t;

    while(t--){
        solve();
    }
}
