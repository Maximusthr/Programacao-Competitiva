#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n; cin >> n;

    map<int, int> freq;
    for (int i = 0; i < n; i++){
        int x; cin >> x;
        freq[x]++;
    }

    vector<pair<int, int>> valores;
    ll count = 0;
    for (auto [x, y] : freq){
        if (y >= 2){
            if (y & 1) y--;
            for (int i = 0; i < y/2; i++){
                valores.push_back({x, y});
            }
            count += y;
        }
    }
    
    if (count < 8){
        cout << "NO" << "\n";
        return;
    }
    
    sort(valores.begin(), valores.end());

    vector<pair<int, int>> ans;
    n = valores.size();
    ans.push_back({valores[0].first, valores[n-1].first});
    ans.push_back({valores[0].first, valores[1].first});
    ans.push_back({valores[n-2].first, valores[1].first});
    ans.push_back({valores[n-2].first, valores[n-1].first});

    cout << "YES" << "\n";
    for (auto &i : ans) cout << i.first << " " << i.second << " ";

    cout << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}