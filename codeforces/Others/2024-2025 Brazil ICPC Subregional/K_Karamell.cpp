#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 105;
const int SOMA = 10005;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    int n; cin >> n;

    vector<int> arr(MAX);
    int sum = 0;
        
    for (int i = 1; i <= n; i++){
        cin >> arr[i];
        sum += arr[i];
    }

    if (sum % 2) {
        cout << -1 << "\n";
        return 0;
    }

    bool dp[MAX][SOMA];

    memset(dp, false, sizeof(dp));

    sum /= 2;

    dp[0][0] = true;
    for (int i = 1; i <= n; i++){
        for (int j = 0; j <= sum; j++){
            dp[i][j] = dp[i-1][j];

            if (arr[i] <= j && dp[i-1][j - arr[i]]){
                dp[i][j] = true;
            }
        }
    }

    if (!dp[n][sum]){
        cout << -1 << "\n";
        return 0;
    }

    vector<int> v1, v2;
    int s = sum;

    for (int i = n; i > 0; i--){
        if (s >= arr[i] && dp[i-1][s-arr[i]]){
            v1.push_back(arr[i]);
            s -= arr[i];
        }
        else {
            v2.push_back(arr[i]);
        }
    }

    int alice = 0, bob = 0;
    for (int i = 0; i < n; i++){
        if (alice <= bob){
            cout << v1.back() << " ";
            alice += v1.back();
            v1.pop_back();
        }
        else {
            cout << v2.back() << " ";
            bob += v2.back();
            v2.pop_back();
        }
    }
}