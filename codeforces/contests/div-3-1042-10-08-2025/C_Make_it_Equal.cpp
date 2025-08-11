// UPSOLVE

#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n, k; cin >> n >> k;

    map<int, int> val;
    for (int i = 0; i < n; i++){
        int x; cin >> x;
        x %= k;
        x = min(x, k-x);
        val[x]++;
    }

    for (int i = 0; i < n; i++){
        int x; cin >> x;
        x %= k;
        x = min(x, k-x);
        val[x]--;
    }

    for (auto i : val){
        if (i.second != 0){
            cout << "NO" << "\n";
            return;
        }
    }

    cout << "YES" << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}