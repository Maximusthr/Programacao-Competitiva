// top-down

#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 1e5+5;

int n, k;
vector<int> h;

vector<int> memo(MAX, -1);

int dp(int i){
    if (i == 0) return 0;

    if (memo[i] != -1) return memo[i];

    int ret = INF;
    for (int j = max(0, i-k); j < i; j++){
        ret = min(ret, dp(j) + abs(h[j] - h[i]));
    }

    return memo[i] = ret;

}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    cin >> n >> k;
    h.resize(n);
    for (auto &i : h) cin >> i;

    cout << dp(n-1) << "\n";

}