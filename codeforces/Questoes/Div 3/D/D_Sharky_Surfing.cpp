#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n, m, l; cin >> n >> m >> l;

    int ans = 0;

    vector<pair<int, int>> o(n), bonus(m);
    for (int i = 0; i < n; i++){
        cin >> o[i].first >> o[i].second;
    }
    for (int i = 0; i < m; i++){
        cin >> bonus[i].first >> bonus[i].second;
    }

    int pulo = 1;
    priority_queue<int> pq;

    int j = 0;
    for (int i = 0; i < n; i++){
        bool ok = false;
        if (pulo + o[i].first - 1 > o[i].second) {

        }
        else {
            for (; j < m; j++){
                if (bonus[j].first < o[i].first){
                    pq.push(bonus[j].second);
                }
                else break;
            }
            while (!pq.empty()){
                pulo += pq.top();
                pq.pop();
                ans++;
                if (pulo + o[i].first - 1 > o[i].second){
                    ok = true;
                    break;
                }
            }
            if (!ok){
                cout << -1 << "\n";
                return;
            }
        }
    }

    cout << ans << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}