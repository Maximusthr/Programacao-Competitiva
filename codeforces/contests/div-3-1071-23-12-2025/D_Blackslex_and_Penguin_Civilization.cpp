#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n; cin >> n;

    vector<int> ans;

    int v = n;
    ans.push_back((1 << v) - 1);
    vector<bool> vis((1 << v) - 1);
    vis[(1 << v) - 1] = true;

    while (v > 0){
        int aux = (1 << v) - 1;
        while (aux <= (1 << n) - 1){
            if (!vis[aux]){
                vis[aux] = 1;
                ans.push_back(aux);
            }
            int valor = (1 << (v+1));
            aux += valor;
        }
        v--;
    }

    vector<int> even;
    for (int i = 0; i < (1 << n) - 1; i++){
        if ((i & 1) && !vis[i]) ans.push_back(i);
        else if (i % 2 == 0) even.push_back(i);
    }

    for (int i = 0; i < even.size(); i++){
        ans.push_back(even[i]);
    }

    for (auto &i : ans) cout << i << " ";
    cout << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}