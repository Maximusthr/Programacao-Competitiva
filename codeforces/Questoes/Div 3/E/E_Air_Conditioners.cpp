#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n, k; cin >> n >> k;

    vector<int> ans(n+1, INF);
    vector<int> air(n+1), temp(n+1);
    for (int i = 1; i <= k; i++){
        cin >> air[i];
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    for (int i = 1; i <= k; i++){
        cin >> temp[i];
        ans[air[i]] = temp[i];
        pq.push({temp[i], air[i]});
    }

    while(!pq.empty()){
        auto [u, v] = pq.top();
        pq.pop();

        if (v + 1 <= n){
            if (u + 1 < ans[v + 1]){
                ans[v + 1] = u + 1;
                pq.push({u + 1, v + 1});
            }
        }
        if (v - 1 >= 1){
            if (u + 1 < ans[v - 1]){
                ans[v - 1] = u + 1;
                pq.push({u + 1, v - 1});
            }
        }
    }

    for (int i = 1; i <= n; i++){
        cout << ans[i] << " \n"[i == n];
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}