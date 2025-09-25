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

    vector<int> dp(k+1);

    dp[0] = 0;
    for (int i = 0; i <= k; i++){
        for (int j = 0; j < n; j++){
            if (i - arr[j] >= 0 && dp[i-arr[j]] == 0){
                dp[i] = 1;
            }
        }
    }

    if (dp[k] == 1) cout << "First" << "\n";
    else cout << "Second" << "\n";
}
