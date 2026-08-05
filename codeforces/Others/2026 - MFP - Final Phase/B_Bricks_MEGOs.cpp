#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n, q, k; cin >> n >> q >> k;

    while(q--){
        int l, r; cin >> l >> r;
        if (k > r){
            k -= r-l+1;
        }
        else if (k <= r && k >= l){
            int x = r - k;
            k = n - x;
        }
    }

    cout << k << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    solve();
}