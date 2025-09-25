#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

vector<int> val;

const int MAX = 1e5 + 5;

int memo[MAX];

int dp(int i){
    if (i == 0) return 0;
    
    if (memo[i] != -1) return memo[i];

    int ret = INF;
    for (int j = max(0, i - 2); j < i; j++){
        ret = min(ret, dp(j) + abs(val[j] - val[i]));
    }

    return memo[i] = ret;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    int n; cin >> n;

    val.resize(n);

    for (int i = 0; i < n; i++){
        cin >> val[i];
    }

    memset(memo, -1, sizeof(memo));

    cout << dp(n-1) << "\n";
}