#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int K = 25;
const int MAX = 2e5+5;

int st[K+1][MAX];

int lg(int x){
    return x ? __builtin_clz(1) - __builtin_clz(x) : -1;
}

void solve(){
    int n, m; cin >> n >> m;

    vector<int> arr(n);
    for (auto &i : arr) cin >> i;

    vector<int> diff(n);
    diff[0] = arr[0];
    for (int i = 0; i < n-1; i++){
        diff[i] = abs(arr[i] - arr[i+1]);
    }

    for (int i = 0; i <= K; i++){
        for (int j = 0; j <= n; j++){
            st[i][j] = 0;
        }
    }

    for (int i = 0; i < n; i++){
        st[0][i] = diff[i];
    }

    for (int i = 1; i <= K; i++){
        for (int j = 0; j + (1 << i) <= n; j++){
            st[i][j] = __gcd(st[i-1][j], st[i-1][j + (1 << (i-1))]);
        }
    }

    while(m--){
        int l, r; cin >> l >> r;
        
        if (l == r){
            cout << 0 << " ";
            continue;
        }

        l--, r -= 2;

        int logg = lg(r-l+1);

        cout << __gcd(st[logg][l], st[logg][r - (1 << logg) + 1]) << " ";
    }
    cout << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}