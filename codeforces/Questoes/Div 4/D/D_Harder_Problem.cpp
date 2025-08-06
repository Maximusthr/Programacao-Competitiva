#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n; cin >> n;

    vector<int> arr(n);
    for (auto &i : arr) cin >> i;

    vector<int> vis(n+1, -1);
    vector<int> idx(n+1, -1);

    for (int i = 1; i <= n; i++){
        if (vis[arr[i-1]] == -1){
            vis[arr[i-1]] = i-1;
            idx[i-1] = arr[i-1];
        }
    }

    vector<int> ap;
    for (int i = 1; i <= n; i++){
        if (vis[i] == -1) ap.push_back(i);
    }

    int j = 0;
    for (int i = 1; i <= n; i++){
        if (idx[i-1] == -1){
            cout << ap[j++] << " ";
        }
        else cout << idx[i-1] << " ";
    }
    cout << "\n";
    
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}