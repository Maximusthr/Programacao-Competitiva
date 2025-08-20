#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 10005;

void solve(){
    int n; cin >> n;

    vector<int> arr(n);
    vector<int> ocor(MAX);

    array<int, 2> v = {0, 0};
    
    for (int i = 0; i < n; i++){
        cin >> arr[i];
        v[0] = max(v[0], arr[i]);
        ocor[arr[i]]++;
    }
    
    vector<bool> vis(MAX);
    for (int i = 0; i < n; i++){
        if (v[0] % arr[i] == 0 && !vis[arr[i]]){
            vis[arr[i]] = 1;
            ocor[arr[i]]--;
        }
    }

    for (int i = 0; i < MAX; i++){
        if (ocor[i] > 0) v[1] = max(v[1], i);
    }

    cout << v[0] << " " << v[1] << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    // int t; cin >> t;
    // while(t--){
    solve();
    // }
}