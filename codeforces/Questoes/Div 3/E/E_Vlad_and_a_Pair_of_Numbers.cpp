#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n; cin >> n;

    if (n & 1){
        cout << -1 << "\n";
        return;
    }

    int a = (n/2);
    int b = (n*2) - a;

    if ((a & b) == (n/2)){
        cout << a << " " << b << "\n";
    }
    else {
        cout << -1 << "\n";
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}