#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n, k; cin >> n >> k;

    set<int> arr;
    map<int, bool> freq;
    for (int i = 0; i < n; i++){
        int x; cin >> x;
        arr.insert(x);
        freq[x] = 1;
    }

    vector<int> ans;
    while (arr.size() > 0){
        int v = *arr.begin();
        ans.push_back(v);
        arr.erase(v);

        for (int i = v; i <= k; i += v){
            if (!freq[i]){
                cout << -1 << "\n";
                return;
            }

            arr.erase(i);
        }
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