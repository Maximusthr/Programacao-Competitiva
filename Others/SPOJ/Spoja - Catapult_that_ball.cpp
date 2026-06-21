#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int K = 25; // up to 1e7
const int MAX = 50005;

int st[K+1][MAX];

int log2(int x){
    return x ? __builtin_clzll(1) - __builtin_clzll(x) : -1;
}

void solve(){
    int n, q; cin >> n >> q;

    vector<int> arr(n);
    for (auto &i : arr) cin >> i;

    for (int i = 0; i < n; i++){
        st[0][i] = arr[i];
    }

    for (int i = 1; i <= K; i++){
        for (int j = 0; j + (1 << i) <= n; j++){
            st[i][j] = max(st[i-1][j], st[i-1][j + (1 << (i-1))]);
        }
    }

    int ans = 0;
    while(q--){
        int l, r; cin >> l >> r;
        l--;
        r -= 2;
        if (l >= r) r = l;

        int v = arr[l];

        int k = log2(r-l+1);
        int maior = max(st[k][l], st[k][r - (1 << k) + 1]);

        if (v >= maior) ans++;
    }

    cout << ans << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    solve();
}