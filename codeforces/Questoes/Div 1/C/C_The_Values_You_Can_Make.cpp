#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    int n, k; cin >> n >> k;

    vector<vector<bool>> dp(k+1, vector<bool> (k+1));

    dp[0][0] = 1;

    while(n--){
        int x; cin >> x;

        for (int i = k; i >= 0; i--){
            for (int j = k; j >= 0; j--){

                if (!dp[i][j]) continue;

                if (i + x <= k){
                    dp[i+x][j] = 1;
                }

                if (j + x <= k){
                    dp[i][j+x] = 1;
                }

            }
        }
    }

    int ans = 0;
    vector<int> res;
    for (int i = 0; i <= k; i++){
        if (dp[i][k-i]) {
            ans++;
            res.push_back(i);
        }
    }

    cout << ans << "\n";
    for (auto &i : res) cout << i << " ";
    cout << "\n";
}