#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n; cin >> n;

    vector<vector<int>> pos(n+1);
    for (int i = 0; i < n; i++){
        int x; cin >> x;
        pos[x].push_back(i);
    }

    vector<int> ans;
    for (int i = 0; i < n;){
        int j = i+1;
        int mex = 0;
        while(true){
            auto it = lower_bound(pos[mex].begin(), pos[mex].end(), i);

            if (it == pos[mex].end()) break;

            j = max(j, *it + 1);
            mex++;
        }
        i = j;
        ans.push_back(mex);
    }

    cout << ans.size() << "\n";
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