#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    ll n; cin >> n;

    if (n % 12 == 0){
        cout << 0 << " " << n << "\n";
        return;
    }
    if (n == 1){
        cout << 1 << " " << 0 << "\n";
        return;
    }

    vector<ll> num = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 11, 22, 33, 44, 55, 66, 77, 88, 99, 101, 111, 121, 131, 141, 151, 161,
                        171, 181, 191, 202, 212, 222, 232, 242, 252, 262, 272, 282, 292};

    for (int i = 0; i < num.size(); i++){
        if (n - num[i] < 0) break;
        if ((n - num[i]) % 12 == 0){
            cout << num[i] << " " << n-num[i] << "\n";
            return;
        }
    }

    cout << -1 << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}