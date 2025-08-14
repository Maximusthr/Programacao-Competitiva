#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 1e5 + 5;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    int n; cin >> n;
    
    vector<int> h(n);

    for (int i = 0; i < n; i++){
        cin >> h[i];
    }

    int dp[MAX];

    memset(dp, INF, sizeof(dp));

    dp[0] = 0;

    for (int i = 1; i < n; i++){
        for (int j = max(0, i-2); j < i; j++){
            dp[i] = min(dp[i], dp[j] + abs(h[j] - h[i]));
        }
    }

    cout << dp[n-1] << "\n";
}