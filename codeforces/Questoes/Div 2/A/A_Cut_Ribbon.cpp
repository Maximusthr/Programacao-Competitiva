#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 4005;

int n, a, b, c;

int memo[MAX][MAX];

int dp(int v, int t){
    
    if (v > n) {
        return 0;
    }
    if (v == n){
        return t;
    }
    
    if (memo[v][t] != -1) return memo[v][t];

    int ans = 0;
    ans = dp(v + a, t + 1);
    ans = max(ans, dp(v + b, t + 1));
    ans = max(ans, dp(v + c, t + 1));

    return memo[v][t] = ans;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    cin >> n >> a >> b >> c;

    memset(memo, -1, sizeof(memo));

    cout << dp(0, 0) << "\n";
}
