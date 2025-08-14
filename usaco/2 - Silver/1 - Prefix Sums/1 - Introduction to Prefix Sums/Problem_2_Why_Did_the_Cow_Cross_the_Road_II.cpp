#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 1e5+5;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    freopen("maxcross.in", "r", stdin);
    freopen("maxcross.out", "w", stdout);

    int n, k, m; cin >> n >> k >> m;

    vector<int> arr(MAX);

    for (int i = 0; i < m; i++){
        int x; cin >> x;
        arr[x] = 1;
    }

    for (int i = 1; i <= n; i++) arr[i] += arr[i-1];

    int ans = INF;
    for (int i = 1; i <= n-k+1; i++){
        ans = min(arr[i+k-1] - arr[i-1], ans);
    }
    
    if (ans == INF) cout << m << "\n";
    else cout << ans << "\n";
}
