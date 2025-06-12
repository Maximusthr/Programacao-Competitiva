#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n, m; cin >> n >> m;

    ll maior = -LINF;
    vector<vector<ll>> arr(n+1, vector<ll> (m+1));
    int x = 0, y = 0;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            cin >> arr[i][j];
            maior = max(maior, arr[i][j]);
            if (maior == arr[i][j]){
                x = i, y = j;
            }
        }
    }

    int valor_x = 0, valor_y = 0;

    if (x > n/2) valor_x = x;
    else if (x <= n/2) valor_x = n-x+1;

    if (y > m/2) valor_y = y;
    else if (y <= m/2) valor_y = m-y+1;

    cout << valor_x * valor_y << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    int t; cin >> t;

    while(t--){
        solve();
    }
}