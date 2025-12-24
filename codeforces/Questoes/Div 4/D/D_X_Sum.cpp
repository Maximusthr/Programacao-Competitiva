#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n, m; cin >> n >> m;

    vector<vector<ll>> arr(n, vector<ll> (m));

    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cin >> arr[i][j];
        }
    }

    ll sum = 0;

    auto check = [&](ll x, ll y) -> ll {
        ll total = arr[x][y];

        for (int i = x+1, j = y+1; i < n && j < m; i++, j++){
            total += arr[i][j];
        }

        for (int i = x+1, j = y-1; i < n && j >= 0; i++, j--){
            total += arr[i][j];
        }

        for (int i = x-1, j = y+1; i >= 0 && j < m; i--, j++){
            total += arr[i][j];
        }

        for (int i = x-1, j = y-1; i >= 0 && j >= 0; i--, j--){
            total += arr[i][j];
        }

        return total;
    };

    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            ll aux = check(i, j);

            sum = max(sum, aux);
        }
    }

    cout << sum << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}