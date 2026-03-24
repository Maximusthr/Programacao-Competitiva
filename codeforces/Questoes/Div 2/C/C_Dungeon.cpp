#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n, m; cin >> n >> m;

    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < n; i++){
        int x; cin >> x;
        pq.push(x);
    }

    vector<pair<int, int>> b(m);
    vector<pair<int, int>> extra;
    for (int i = 0; i < m; i++){
        cin >> b[i].first;
    }
    for (int i = 0; i < m; i++){
        cin >> b[i].second;
        if (b[i].second == 0){
            extra.push_back(b[i]);
            b[i].first = INF;
        }
    }

    sort(b.begin(), b.end(), [&](pair<int, int> x, pair<int, int> y){
        if (x.first != y.first) return x.first < y.first;
        return x.second > y.second;
    });

    int i = 0;
    int ans = 0;
    vector<int> foi;
    while(!pq.empty() && i < m){
        if (b[i].second == 0 || b[i].first == INF) break;

        int x = pq.top();
        if (x >= b[i].first){
            ans++;
            pq.pop();
            pq.push(max(x, b[i].second));
            i++;
        }
        else {
            foi.push_back(x);
            pq.pop();
        }
    }

    while(!pq.empty()){
        foi.push_back(pq.top());
        pq.pop();
    }

    sort(extra.begin(), extra.end());

    for (int i = 0, j = 0; i < foi.size() && j < extra.size(); i++){
        if (foi[i] >= extra[j].first){
            ans++;
            j++;
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