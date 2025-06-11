#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n, a, b; cin >> n >> a >> b;

    vector<int> arr(n+1);
    iota(arr.begin()+1, arr.end(), 1);

    vector<int> prim;
    vector<int> seg;
    
    vector<bool> vis(n+1);
    
    for (int i = b+1; i <= n && prim.size() < n/2; i++){
        prim.push_back(arr[i]);
        vis[arr[i]] = true;
    }
    for (int i = a; i < b && prim.size() < n/2; i++){
        prim.push_back(arr[i]);
        vis[arr[i]] = true;
    }

    bool ok = false;
    for (int i = 0; i < prim.size(); i++){
        if (prim[i] == a) ok = true;
        if (prim[i] < a) {
            cout << -1 << "\n";
            return;
        }
    }
    if (!ok ){
        cout << -1 << "\n";
        return;
    }
    
    for (int i = 1; i <= n; i++){
        if (vis[arr[i]]) continue;
        seg.push_back(arr[i]);
    }

    for (int i = 0; i < seg.size(); i++){
        if (seg[i] > b) {
            cout << -1 << "\n";
            return;
        }
    }

    if (seg.size() > n/2) {
        cout << -1 << "\n";
        return;
    }

    for (int i = 0; i < prim.size(); i++){
        cout << prim[i] << " ";
    }
    for (int i = 0; i < seg.size(); i++){
        cout << seg[i] << " ";
    }
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    int t; cin >> t;
    while(t--){
        solve();
    }
}