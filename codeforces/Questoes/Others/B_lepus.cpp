#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 1010;

int n;
string s;
int memo[MAX];

int dp(int idx){
    if (idx == n-1){
        return 0;
    }
    if (idx >= n || s[idx] == 'w'){
        return -INF;
    }

    if (memo[idx] != -1){
        return memo[idx];
    }

    int here = (s[idx] == '"'); 
    int best = -INF;

    int r1 = dp(idx+1);
    if (r1 !=  -INF) best = max(best, r1 + here);

    int r3 = dp(idx+3);
    if (r3 != -INF) best = max(best, r3 + here);

    int r5 = dp(idx+5);
    if (r5 != -INF) best = max(best, r5 + here);

    memo[idx] = best;

    return memo[idx];
}

void solve(){
    cin >> n;

    cin >> s;

    memset(memo, -1, sizeof(memo));    

    cout << (dp(0) == -INF ? -1 : dp(0)) << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    freopen("lepus.in", "r", stdin);
    freopen("lepus.out", "w", stdout);
    solve();
}