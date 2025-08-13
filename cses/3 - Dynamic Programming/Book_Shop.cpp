#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    int n, x; cin >> n >> x;

    vector<int> price(n);
    vector<int> page(n);

    for (auto &i : price) cin >> i;
    for (auto &i : page) cin >> i;

    vector<int> dp(x+1);

    for (int i = 0; i < n; i++){
        for (int j = x; j >= price[i]; j--){
            dp[j] = max(dp[j], page[i] + dp[j - price[i]]);
        }
    }

    cout << dp[x] << "\n";
}