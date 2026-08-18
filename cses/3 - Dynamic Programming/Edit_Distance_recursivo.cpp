#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 5005;

int memo[MAX][MAX];

int dp(const string &a, const string &b, int n, int m){
    if (n == 0) return m;
    if (m == 0) return n;

    auto &p = memo[n][m];
    if (p != -1) return p;

    if (a[n-1] == b[m-1]) return p = dp(a, b, n-1, m-1);

    return p = 1 + min({dp(a, b, n-1, m), dp(a, b, n-1, m-1), dp(a, b, n, m-1)});
}

void solve(){
    string a, b; cin >> a >> b;

    memset(memo, -1, sizeof(memo));

    cout << dp(a, b, a.size(), b.size()) << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    solve();
}
