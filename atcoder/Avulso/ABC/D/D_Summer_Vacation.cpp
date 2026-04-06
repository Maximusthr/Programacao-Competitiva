#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n, m; cin >> n >> m;

    vector<vector<int>> trab(m+1);

    for (int i = 0; i < n; i++){
        int x, y; cin >> x >> y;
        if (x <= m) trab[x].push_back(y);
    }

    ll ans = 0;

    priority_queue<int> pq;
    for (int i = 1; i <= m; i++){
        for (auto j : trab[i]){
            pq.push(j);
        }

        if (!pq.empty()){
            ans += pq.top();
            pq.pop();
        }
    }

    cout << ans << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    solve();
}