#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n, q; cin >> n >> q;

    vector<vector<ll>> prefix(1005, vector<ll> (1005));

    vector<vector<ll>> arr(1005, vector<ll> (1005));

    for (int i = 0; i < n; i++){
        int x, y; cin >> x >> y;
        arr[x][y] += (x*y);
    }

    for (int i = 1; i < 1005; i++){
        for (int j = 1; j < 1005; j++){
            prefix[i][j] += arr[i][j] + prefix[i-1][j] + prefix[i][j-1] - prefix[i-1][j-1];
        }
    }

    for (int i = 0; i < q; i++){
        int a, b, c, d; cin >> a >> b >> c >> d;

        cout << prefix[c-1][d-1] - prefix[a][d-1] - prefix[c-1][b] + prefix[a][b] << "\n";
    }

}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}