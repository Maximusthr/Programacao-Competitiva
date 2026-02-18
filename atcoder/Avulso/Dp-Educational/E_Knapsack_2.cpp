#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 100005;

void solve(){
    int n, W; cin >> n >> W;

    vector<pair<int, int>> m(n);
    for (int i = 0; i < n; i++){
        cin >> m[i].first >> m[i].second;
    }

    // a dp vai ser em cima dos valores
    // retornando o peso de cada item

    ll dp[MAX];
    memset(dp, LINF, sizeof(dp));

    dp[0] = 0;
    
    // queremos minimizar o peso
    for (int i = 0; i < n; i++){
        for (int j = MAX - m[i].second - 1; j >= 0; j--){
            dp[j + m[i].second] = min(dp[j + m[i].second], dp[j] + m[i].first);
        }
    }

    for (int i = MAX - 1; i >= 0; i--){
        if (dp[i] <= W){
            cout << i << "\n";
            return;
        }
    }

    cout << 0 << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    solve();
}