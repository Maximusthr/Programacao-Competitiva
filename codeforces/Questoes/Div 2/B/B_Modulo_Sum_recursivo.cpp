#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int n, m;
vector<ll> arr;
int memo[1005][1005];

int dp(int i, ll resto){
    if (resto == 0) return 1;
    if (i == n) return 0;

    if (memo[i][resto] != -1) return memo[i][resto];

    int ans = (dp(i+1, (resto + arr[i]) % m) | dp(i+1, resto));
    return memo[i][resto] = ans;
}   

void solve(){
    cin >> n >> m;

    if (n >= m){
        cout << "YES" << "\n";
        return;
    }

    arr.resize(n);
    for (auto &i : arr) {
        cin >> i;
        i %= m;
    }

    memset(memo, -1, sizeof(memo));

    if (dp(0, m)) cout << "YES" << "\n";
    else cout << "NO" << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    solve();
}