#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n; cin >> n;

    vector<int> arr(n);

    for (int i = 0; i < n; i++){
        cin >> arr[i];
        
        arr[i]--;
    }

    vector<bool> vis(n);
    vector<int> ans(n);

    for (int i = 0; i < n; i++){
        if (!vis[i]){

            vector<int> viz;
            int atual = i;
            while (!vis[atual]){
                vis[atual] = true;
                viz.push_back(atual);
                atual = arr[atual];
            }

            for (auto v : viz){
                ans[v] = viz.size();
            }
        }
    }

    for (int i = 0 ; i < n; i++){
        cout << ans[i] << " \n"[i == n-1];
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}