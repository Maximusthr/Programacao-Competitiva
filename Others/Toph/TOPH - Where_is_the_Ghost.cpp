#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 1e4+5;
const int MOD = 1e9 + 7;

int n;
vector<int> arr(MAX);
int memo[MAX][2521];

const int fixo = 2520;

int dp(int idx, int v){
    if (idx == n) return (v == fixo);

    if (memo[idx][v] != -1) return memo[idx][v] % MOD;

    int ans = (dp(idx+1, __gcd(arr[idx] * v, fixo)) + dp(idx+1, v)) % MOD;

    return memo[idx][v] = ans;
}

void solve(){
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }

    memset(memo, -1, sizeof(memo));

    cout << dp(0, 1) % MOD << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    solve();
}