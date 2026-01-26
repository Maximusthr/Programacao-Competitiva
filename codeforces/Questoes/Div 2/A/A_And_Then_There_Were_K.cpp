#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n; cin >> n;

    int ans = 0;
    bool achou = false;
    for (int i = 30; i >= 0; i--){
        if (!achou && (n & (1 << i))){
            achou = true;
            continue;
        }
        if (achou){
            ans += (1 << i);
        }
    }

    cout << ans << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}