#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n, k; cin >> n >> k;

    
    map<int, bool> tem;

    priority_queue<pair<int, int>> arr;
    arr.push({n, 0});

    int ans = 0;
    while(!arr.empty()){
        auto [u, v] = arr.top();

        if (u == k){
            cout << v << "\n";
            return;
        }

        arr.pop();

        int x = u/2;
        int y = (u+1)/2;

        if (!tem[x]) {
            arr.push({x, v+1});
            tem[x] = 1;
        }
        if (!tem[y]) {
            arr.push({y, v+1});
            tem[y] = 1;
        }
    }

    cout << -1 << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}