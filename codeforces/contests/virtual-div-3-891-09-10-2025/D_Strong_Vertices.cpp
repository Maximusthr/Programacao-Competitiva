#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n; cin >> n;

    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; i++){
        int x; cin >> x;

        a[i] = {x, i};
    }
    for (int i = 0; i < n; i++){
        int x; cin >> x;
        a[i].first -= x;
    }

    sort(a.begin(), a.end(), greater<pair<int, int>>());

    vector<int> ans;
    ans.push_back(a[0].second);

    for (int i = 1; i < n; i++){
        if (a[0].first == a[i].first){
            ans.push_back(a[i].second);
        }
    }

    reverse(ans.begin(), ans.end());

    cout << ans.size() << "\n";
    for (auto y : ans){
        cout << y + 1 << " ";
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