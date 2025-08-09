#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

ll countGood(ll num){
    int n = 4;
    vector<int> arr = {2, 3, 5, 7};

    ll qtd = num;
    ll ans = num;

    for (int i = 1; i < (1 << n); i++){
        int c = 0;
        ll div = 1;
        for (int j = 0 ; j < n; j++){
            if ((i >> j) & 1){
                c++;
                div *= arr[j];
            }
        }   

        if (c % 2) ans -= (qtd/div);
        else ans += (qtd/div);
    }

    return ans;
}

void solve(){
    ll l, r; cin >> l >> r;

    cout << countGood(r) - countGood(l-1) << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}