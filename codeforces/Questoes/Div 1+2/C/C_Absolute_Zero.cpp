#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n; cin >> n;

    vector<int> arr(n);
    bool odd = false, even = false;
    for (auto &i : arr) {
        cin >> i;
        if (i % 2) odd = true;
        else even = true;
    }

    if (odd && even){
        cout << -1 << "\n";
        return;
    }

    sort(arr.begin(), arr.end(), greater<int> ());

    if (arr[0] == 0){
        cout << 0 << "\n";
        return;
    }

    vector<int> ans;
    while(arr[0] > 1){
        int v = arr[0]/2;

        ans.push_back(v);

        arr[0] = abs(arr[0] - v);
    }

    ans.push_back(1);

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