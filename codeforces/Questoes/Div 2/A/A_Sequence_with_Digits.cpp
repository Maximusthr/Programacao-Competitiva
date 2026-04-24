#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

ll verif(ll a, bool type){
    if (type == 0){
        int m = INF;
        while(a > 0){
            m = min(a % 10, 1ll*m);
            a /= 10;
        }
        return m;
    }
    else {
        int m = 0;
        while(a > 0){
            m = max(a % 10, 1ll*m);
            a /= 10;
        }
        return m;
    }
}

void solve(){
    ll a, k; cin >> a >> k;

    while(k > 1){
        int men = verif(a, 0);
        int mai = verif(a, 1);

        a += (men * mai);

        if (mai == 0 || men == 0){
            cout << a << "\n";
            return;
        }
        k--;
    }
    cout << a << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}