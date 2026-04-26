#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n; cin >> n;

    vector<int> arr(n);
    for (auto &i : arr) cin >> i;

    auto copy = arr;
    sort(copy.begin(), copy.end());
    int M = copy[copy.size()/2];

    vector<int> dp(n+1, -1);
    dp[0] = 0;
    for (int i = 0; i < n; i++){
        if(dp[i] == -1) continue;
        int menor = 0;
        int maior = 0;
        for (int j = i; j < n; j++){
            int tam = j - i + 1;
            menor += (arr[j] < M);
            maior += (arr[j] > M);

            if (tam & 1 && tam > 2 * menor && tam > 2 * maior){
                dp[j + 1] = max(dp[j + 1], dp[i] + 1);
            }
        }
    }

    cout << dp[n] << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}