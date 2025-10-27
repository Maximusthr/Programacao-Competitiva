#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    int n, m; cin >> n >> m;

    vector<int> diff(n+2);

    for (int i = 0; i < m; i++){
        int x, y; cin >> x >> y;
        diff[x]++;
        diff[y+1]--;
    }

    int ans = INF;

    for (int i = 1; i <= n; i++){
        diff[i] += diff[i-1];
        ans = min(diff[i], ans);
    }

    cout << ans << "\n";
}