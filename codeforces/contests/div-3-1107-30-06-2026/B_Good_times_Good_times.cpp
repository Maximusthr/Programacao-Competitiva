#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int decimal(ll x){
    set<int> ans;
    // int v = 0;
    while(x > 0){
        ans.insert(x%10);
        x /= 10;
    }
    return ans.size();
}

void solve(){
    ll x; cin >> x;

    int zero = decimal(x);  

    vector<int> ans = {11, 101, 1001, 10001, 100001, 1000001, 10000001, 100000001};

    for (int i = 0; i < ans.size(); i++){
        ll z = 1ll * ans[i] * x;
        if (decimal(z) <= 2){
            cout << ans[i] << "\n";
            return;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}