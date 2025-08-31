#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    int n, k; cin >> n >> k;

    vector<int> arr(n);
    for (auto &i : arr) cin >> i;

    vector<int> dp(k+1, -1);

    auto solve = [&](auto &self, int K) -> int{
        // 0 -> eu perco
        // 1 -> eu ganho
        
        if (dp[K] != -1) return dp[K];

        int res = 0;
        for (int i = 0; i < n; i++){
            if (K - arr[i] >= 0){
                if (self(self, K-arr[i]) == 0) res = 1;
                else {};
            }
        }

        return dp[K] = res;
    };

    if (solve(solve, k) == 0) cout << "Second" << "\n";
    else cout << "First" << "\n";
}
