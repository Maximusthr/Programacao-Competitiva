#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

// upsolve
void solve(){
    int n; cin >> n;

    if (n == 1){
        cout << 1 << "\n";
        return;
    }

    if (n == 2){
        cout << -1 << "\n";
        return;
    }

    cout << 1 << " " << 2 << " " << 3 << " ";
    ll sum = 3;
    for (int i = 3; i < n; i++){
        sum += sum;
        cout << sum << " \n"[i+1==n];
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}