#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n; cin >> n;

    vector<int> arr(n+1);
    for (int i = 1; i <= n; i++){
        cin >> arr[i];
    }

    vector<int> foi(n+1, INF);
    vector<bool> vis(n+1);
    vector<int> pai(n+1, -1);

    auto bfs = [&](int i){
        queue<pair<int, int>> q;
        q.push({i, 0});
        vis[i] = true;
        while(!q.empty()){
            int u = q.front();

            q.pop();

            if ((arr[u] % 2) != (arr[i] % 2)){
                // achou
                // sai propagando de volta
                int c = 1;
                vis[u] = false;
                int f = 0;
                for (int p = u; p != i; p = pai[p]){
                    if (f) foi[p] = c++;
                    f++;
                }
                foi[i] = c;
                break;
            }

            if (u + arr[u] <= n && !vis[u + arr[u]]){
                q.push(u + arr[u]);
                pai[u + arr[u]] = u;
                vis[u + arr[u]] = true;
            }
            else if (u + arr[u] <= n && vis[u + arr[u]]){
                if (foi[u + arr[u]] != INF){
                    int x = foi[u + arr[u]];
                    for (int p = u; p != i; p = pai[p]){
                        foi[p] = x++;
                    }
                    break;
                }
            }
            if (u - arr[u] >= 1 && !vis[u - arr[u]]){
                q.push(u - arr[u]);
                pai[u - arr[u]] = u;
                vis[u - arr[u]] = true;
            }
            else if (u - arr[u] >= 1 && vis[u - arr[u]]){
                if (foi[u - arr[u]] != INF){
                    int x = foi[u - arr[u]];
                    for (int p = u; p != i; p = pai[p]){
                        foi[p] = x++;
                    }
                    break;
                }
            }
        }
    };

    for (int i = 1; i <= n; i++){
        if (!vis[i]) bfs(i);
    }

    for (int i = 1; i <= n; i++){
        cout << (foi[i] == INF ? -1 : foi[i]) << " \n"[i == n];
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    solve();
}