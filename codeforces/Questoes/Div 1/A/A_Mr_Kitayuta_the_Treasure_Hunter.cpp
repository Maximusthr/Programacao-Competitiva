#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 30005;

int n, d;
vector<ll> coord(MAX);
ll memo[MAX][500];

ll dp(int idx, int pulo){
    if (pulo == 0 || idx >= MAX) {
        return 0;
    }

    if (memo[idx][pulo - d] != -1) return memo[idx][pulo-d];

    int ans = 0;
    ans = max({dp(idx + pulo - 1, pulo - 1) + coord[idx], dp(idx + pulo, pulo) + coord[idx], dp(idx + pulo + 1, pulo + 1) + coord[idx]});

    return memo[idx][pulo - d] = ans;
}

void solve(){
    cin >> n >> d;

    for (int i = 0; i < n; i++){
        int x; cin >> x;
        coord[x]++;
    }

    memset(memo, -1, sizeof(memo));

    cout << dp(d, d) << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    solve();
}