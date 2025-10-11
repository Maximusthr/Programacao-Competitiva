#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 32769;
const int MOD = 32768;

int bfs(int x){
    queue<int> q;
    q.push(x);

    vector<bool> vis(MAX);
    vector<int> dist(MAX);

    int ans = 0;

    dist[x] = 0;

    while(!q.empty()){
        int v = q.front();
        q.pop();

        if (!vis[v]) vis[v] = true;

        if (v == 0){
            return dist[0];
        }

        if (!vis[(v+1)%MOD]){
            vis[(v+1)%MOD] = true;
            q.push((v+1) % MOD);
            dist[(v+1) % MOD] = dist[v] + 1;
        }
        if (!vis[(2*v)%MOD]){
            vis[(2*v)%MOD] = true;
            q.push((2*v) % MOD);
            dist[(v*2) % MOD] = dist[v] + 1;
        }
    }

}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    int n; cin >> n;

    vector<int> arr(n);
    for (auto &i : arr) cin >> i;

    vector<int> v(MAX, -1);
    for (int i = 0; i < n; i++){
        if (v[arr[i]] == -1){
            v[arr[i]] = bfs(arr[i]);
        }
    }

    for (int i = 0; i < n; i++){
        cout << v[arr[i]] << " \n"[i==n-1];
    }
}   