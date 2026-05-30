#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n, m; cin >> n >> m;

    vector<int> shari(n), neta(m);
    for (auto &i : shari) cin >> i;
    for (auto &i : neta) cin >> i;

    sort(shari.begin(), shari.end());
    sort(neta.begin(), neta.end());

    int ans = 0;
    int i = 0, j = 0;
    while(i < n && j < m){
        if (shari[i] * 2 >= neta[j]){
            i++;
            j++;
            ans++;
        }
        else i++;
    }
    cout << ans << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    solve();
}