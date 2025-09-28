// upsolve

#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 2e5+5;

void solve(){
    int n, k; cin >> n >> k;

    vector<int> arr(n);
    map<int, int> elem;
    for (int i = 0; i < n; i++){
        cin >> arr[i];
        elem[arr[i]]++;
    }

    for (auto [x, y] : elem){
        if (y % k != 0){
            cout << 0 << "\n";
            return;
        }
    }

    for (auto &[x, y] : elem){
        y /= k;
    }

    ll ans = 0;

    int l = 0, r = 0;
    vector<int> valores(MAX);
    while(r < n && r >= l){
        valores[arr[r]]++;

        while(valores[arr[r]] > elem[arr[r]]){
            valores[arr[l]]--;
            l++;
        }
        ans += (r-l+1);
        r++;
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