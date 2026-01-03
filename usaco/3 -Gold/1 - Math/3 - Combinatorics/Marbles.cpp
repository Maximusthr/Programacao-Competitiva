#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

ll func(int n, int k){
    if (k > n-k) k = n-k;

    ll res = 1;
    for (int i = 0; i < k; i++){
        res = res * (n-i)/(i+1);
    }

    return res;
}

void solve(){
    ll n, k; cin >> n >> k;

    cout << func(n-1, k-1) << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}