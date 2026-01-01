#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n; cin >> n;

    set<int> ids;
    vector<pair<int, int>> par(n);
    for (int i = 0; i < n; i++){
        cin >> par[i].first;
        par[i].first--;
        ids.insert(par[i].first);
    }

    for (int i = 0; i < n; i++){
        cin >> par[i].second;
    }

    int size = ids.size();

    vector<vector<ll>> arr(n);
    for (int i = 0; i < n; i++){
        arr[par[i].first].push_back(par[i].second);
    }

    sort(arr.begin(), arr.end(), [&](vector<ll> x, vector<ll> y){
        return x.size() > y.size();
    });

    for (int i = 0; i < n; i++){
        if (arr[i].size() == 0) break;
        sort(arr[i].begin(), arr[i].end(), greater<ll> ());
    }
    
    for (int i = 0; i < n; i++){
        for (int j = 1; j < arr[i].size(); j++){
            arr[i][j] += arr[i][j-1];
        }
    }

    vector<ll> ans(n+1);
    for (int i = 1; i <= n; i++){
        for (int j = 0; j < arr.size(); j++){
            int valor = arr[j].size();
            if (i > arr[j].size()) break;
            int v = arr[j].size()/i;
            v = v * i;
            if (v == 0 || v > arr[j].size()) continue;
            ans[i] += arr[j][(v-1)];
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