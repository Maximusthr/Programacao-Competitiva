#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int n;
vector<ll> arr;
ll memo[3005][3005];

ll dp(int l, int r){
    if (l == r) return arr[l];

    auto &p = memo[l][r];
    if (p != -1) return p;

    ll ans = 0;
    ans += max(arr[l] - dp(l+1, r), arr[r] - dp(l, r-1));

    return p = ans;
}

void solve(){
    cin >> n;

    arr.resize(n+1);

    for (int i = 1; i <= n; i++){
        cin >> arr[i];
    }

    memset(memo, -1, sizeof(memo));

    cout << dp(1, n) << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    solve();
}