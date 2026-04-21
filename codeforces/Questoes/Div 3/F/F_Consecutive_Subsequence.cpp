
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

vector<int> arr;
map<int, vector<int>> mapa;
vector<bool> vis; 
vector<int> qtd; 

int dfs (int u){
    if (vis[u]) return qtd[u];
    else vis[u] = true;

    if (mapa[arr[u]+1].size() == 0){
        mapa.erase(arr[u]+1);
        return 0;
    }

    // lower_bound no indice dentro do map
    int l = 0, r = mapa[arr[u]+1].size()-1;
    while(l < r){
        int mid = l + (r-l)/2;
        if (u <= mapa[arr[u]+1][mid]) r = mid;
        else l = mid + 1;
    }
    if (mapa[arr[u]+1][l] <= u) return 0;

    return qtd[u] = dfs(mapa[arr[u]+1][l]) + 1;
};

void solve(){
    int n; cin >> n;

    vis.resize(n+1);
    qtd.resize(n+1);
    arr.resize(n);

    for (int i = 0; i < n; i++){
        cin >> arr[i];
        mapa[arr[i]].push_back(i);
    }

    bool usado = false;
    int ans = 1;
    for (int i = 0; i < n; i++){
        if (!vis[i]){
            int v = dfs(i);
            ans = max(ans, v+1);
        }
    }

    vector<int> path;
    int v = ans-1, atual = -1;
    for (int i = 0; i < n; i++){
        if (qtd[i] == v){
            if (atual == -1) atual = arr[i];
            else {
                if (atual + 1 == arr[i]) atual++;
                else continue;
            }
            path.push_back(i+1);
            v--;
        }   
    }

    cout << ans << "\n";
    for (auto &i : path) cout << i << " ";
    cout << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    solve();
}