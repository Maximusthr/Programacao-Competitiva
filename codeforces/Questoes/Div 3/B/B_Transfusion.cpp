#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n; cin >> n;

    ll even = 0, odd = 0;
    for (int i = 0; i < n; i++){
        int x; cin >> x;
        if (i % 2) odd += x;
        else even += x;
    }

    int div_even = n/2, div_odd = n/2;
    if (n % 2) div_even++;

    if ((even % div_even == 0) && (odd % div_odd == 0) && (even/div_even == odd/div_odd)){
        cout << "YES" << "\n";
    }
    else cout << "NO" << "\n";

}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}