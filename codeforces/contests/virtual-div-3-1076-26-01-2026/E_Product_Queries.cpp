#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
// upsolve
void solve(){
    int n; cin >> n;

    set<int> arr;
    for (int i = 0; i < n; i++){
        int x; cin >> x;
        arr.insert(x);
    }
    
    vector<vector<int>> fat(n+1);

    for (int i = 1; i <= n; i++){
        for (int j = i; j <= n; j += i){
            fat[j].push_back(i);
        }
    }

    vector<int> ans(n+1, INF);

    for (int i = 1; i <= n; i++){
        if (arr.count(i)) ans[i] = 1;

        for (auto d : fat[i]){
            if (ans[d] != INF && arr.count(i/d)){
                ans[i] = min(ans[i], ans[d] + 1);
            }
        }
    }

    for (int i = 1; i <= n; i++){
        cout << (ans[i] == INF ? -1 : ans[i]) << " \n"[i == n];
    }
}   

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    int t; cin >> t;
    while(t--){
        solve();
    }
}