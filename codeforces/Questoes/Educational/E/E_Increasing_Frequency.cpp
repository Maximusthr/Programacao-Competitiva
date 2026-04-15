#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 5e5+5;

void solve(){
    int n, c; cin >> n >> c;

    vector<int> arr(n+1);
    vector<int> prefix(n+1);
    vector<vector<int>> v(MAX);
    vector<bool> vis(MAX);

    for (int i = 1; i <= n; i++){
        cin >> arr[i];

        prefix[i] += prefix[i-1] + (arr[i] == c);
        v[arr[i]].push_back(i);
    }

    int ext = 0;
    for (int i = 1; i <= n; i++){
        if (vis[arr[i]] || arr[i] == c || !v[arr[i]].size()) continue;

        int atual = 1;
        ext = max(ext, atual);

        for (int j = 1; j < v[arr[i]].size(); j++){
            atual += 1 - prefix[v[arr[i]][j]] + prefix[v[arr[i]][j-1]]; // atual - dir + esq
            
            if (atual <= 0) atual = 1;

            ext = max(ext, atual);
        }

        vis[arr[i]] = 1;
    }
    cout << ext + prefix[n] << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    solve();
}