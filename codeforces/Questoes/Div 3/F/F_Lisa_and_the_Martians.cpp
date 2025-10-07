#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n, k; cin >> n >> k;

    vector<int> arr(n);
    map<int, int> orig;
    for (int i = 0; i < n; i++){
        cin >> arr[i];
        orig[arr[i]] = i;
    }

    map<int, vector<pair<int, int>>> mapa;
    
    for (int i = 0; i < n; i++){
        int v = 0;
        for (int bit = 29; bit >= 0; bit--){
            if (bit >= k) continue;
            if (!(arr[i] & (1 << bit))){
                v += (1 << bit);
            }
        }
        
        mapa[v].push_back({arr[i], i});
    }

    sort(arr.begin(), arr.end());
    
    map<int, int> pos;
    for (int i = 0; i < n; i++){
        pos[arr[i]] = i;
    }

    pair<int, tuple<int, int, int>> ans = {-1, {-1, -1, -1}};
    bool achou = false;

    for (auto [x, y] : mapa){
        if (y.size() > 1) {
            achou = true;
            
            int oper = ((y[0].first ^ x) & (y[1].first ^ x));
            if (oper > ans.first){
                ans = {oper, {y[0].second, y[1].second, x}};
            }
        }
    }

    if (achou){
        cout << get<0>(ans.second) + 1 << " " << get<1>(ans.second) + 1 << " " << get<2>(ans.second) << "\n";
    }
    else {
        for (auto [x, y] : mapa){
            int oper1 = 0, oper2 = 0;
            if (pos[y[0].first] > 0){
                oper1 = ((y[0].first ^ x) & (arr[pos[y[0].first] - 1] ^ x)); // o valor precisa ser no arry sortado
            }
            if (pos[y[0].first] < n-1){
                oper2 = ((y[0].first ^ x) & (arr[pos[y[0].first] + 1] ^ x)); // o valor precisa ser no arry sortado
            }
            if (oper1 > ans.first){
                ans = {oper1, {y[0].second, orig[arr[pos[y[0].first] - 1]], x}}; // posição no arry original
            }
            if (oper2 > ans.first){
                ans = {oper2, {y[0].second, orig[arr[pos[y[0].first] + 1]], x}}; // posição no arry original
            }
        }

        cout << get<0>(ans.second) + 1 << " " << get<1>(ans.second) + 1 << " " << get<2>(ans.second) << "\n";
    }
}   

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}