// UPSOLVE

#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n, m; cin >> n >> m;

    vector<int> arr(n);
    for (auto &i : arr) cin >> i;

    string s; cin >> s;

    vector<int> idx;
    
    int l = 0, r = n-1;
    for (int i = 0; i < n; i++){
        if (s[i] == 'L'){
            idx.push_back(l++);
        }
        else if (s[i] == 'R'){
            idx.push_back(r--);
        }
    }

    reverse(idx.begin(), idx.end());

    vector<int> ans;

    int multi = 1;
    for (int i = 0; i < n; i++){
        multi = (arr[idx[i]] % m) * (multi % m) % m;
        ans.push_back(multi);
    }

    reverse(ans.begin(), ans.end());

    for (auto &i : ans) cout << i << " ";
    cout << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}