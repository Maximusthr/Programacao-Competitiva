#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 3e5 + 5;

vector<int> crivo(MAX);

set<int> fatores(int x) {
    set<int> fat;

    while (x > 1){
        fat.insert(crivo[x]);
        x /= crivo[x];
    }

    return fat;
}

void solve(){
    int n; cin >> n;

    vector<int> arr(n);
    for (auto &i : arr) cin >> i;
    int start, end; cin >> start >> end;
    
    if (start == end){
        cout << 1 << "\n" << start << "\n";
        return;
    }
    else if (arr[start - 1] == arr[end - 1] && arr[start-1] > 1){
        cout << 2 << "\n" << start << " " << end << "\n";
        return;
    }
    
    start--, end--;

    vector<bool> vis(MAX); 
    vector<int> pai(MAX, -1); 
    vector<set<int>> g(MAX); 

    for (int i = 0; i < n; i++){
        set<int> fact = fatores(arr[i]);

        for (auto &x : fact){
            g[x].insert(arr[i]);
        }
    }

    queue<pair<int, int>> q;
    int v = arr[start];
    while (v > 1){
        if (!vis[crivo[v]]){
            q.push({crivo[v], arr[start]});
            vis[crivo[v]] = true;
        }
        v /= crivo[v];
    }
    bool ok = false;
    while(!q.empty()){
        int u = q.front().first;
        int p = q.front().second;
        q.pop();

        for (auto x : g[u]){
            if (pai[x] != -1) continue;
            pai[x] = p;

            if (x == arr[end]){
                ok = true;
                break;
            }

            int aux = x;
            while (aux > 1){
                if (!vis[crivo[aux]]){
                    q.push({crivo[aux], x});
                    vis[crivo[aux]] = true;
                }
                aux /= crivo[aux];
            }
        }

        if (ok) break;
    }

    if (!ok){
        cout << -1 << "\n";
        return;
    }

    vector<int> idx(MAX);
    for (int i = 0; i < n; i++){
        idx[arr[i]] = i;
    }

    vector<int> ans;
    for (int u = arr[end]; u != arr[start]; u = pai[u]){
        if (u == arr[end]) ans.push_back(end);
        else ans.push_back(idx[u]);
    }
    ans.push_back(start);
    reverse(ans.begin(), ans.end());

    cout << ans.size() << "\n";
    for (auto &i : ans) cout << i+1 << " ";
    cout << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    crivo[0] = 0;
    crivo[1] = 1;

    for (ll i = 2; i < MAX; i++){
        if (crivo[i] == 0){
            crivo[i] = i;
            for (ll j = i * i; j < MAX; j += i){
                if (crivo[j] == 0){
                    crivo[j] = i;
                }
            }
        }
    }

    solve();
}