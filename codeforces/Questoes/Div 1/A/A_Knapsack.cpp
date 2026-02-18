#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n; cin >> n;
    ll w; cin >> w;

    priority_queue<pair<ll, ll>> pq;
    for (int i = 0; i < n; i++){
        int x; cin >> x;
        if (x > w) continue;
        
        pq.push({x, i});
    }
    
    ll v = 0;
    bool ok = false;
    vector<int> ans;
    while(!pq.empty()){
        auto [x, y] = pq.top();
        pq.pop();

        v += x;
        if (v > w){
            v -= x;
            continue;
        }
        ans.push_back(y);

        if (v >= (w+1)/2 && v <= w) {
            ok = true;
            break;
        }
    }

    if (ok){
        sort(ans.begin(), ans.end());
        cout << ans.size() << "\n";
        for (auto &i : ans) cout << i+1 << " ";
        cout << "\n";
    }
    else cout << -1 << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}