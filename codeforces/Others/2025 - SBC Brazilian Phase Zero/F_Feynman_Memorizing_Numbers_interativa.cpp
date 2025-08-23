#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    int n;
    vector<int> v;
    
    cin >> n;
    
    v.resize(n);
    for (int i = 0; i < n; i++){
        cin >> v[i];
        v[i] += 1000;
    }
    
    ll dp[8005][5];

    memset(dp, 0, sizeof(dp));

    dp[0][0] = 1;

    for (int i = 0; i < n; i++){
        for (int k = 4; k >= 1; k--){
            for (int valor = 0; valor <= 8000; valor++){

                if (v[i] > valor) continue;

                dp[valor][k] += dp[valor-v[i]][k-1];

            }
        }
    }

    int q; cin >> q;
    while(q--){
        int x; cin >> x;

        x += 4000;

        cout << dp[x][4] << "\n";
    }
}