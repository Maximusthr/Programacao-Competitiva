#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n, k; cin >> n >> k;

    vector<int> arr(n);
    for (auto &i : arr) cin >> i;

    if (n == k){
        cout << arr.size() << "\n";
        for (auto &i : arr) cout << i << " ";
        cout << "\n";
        return;
    }

    vector<bool> valores(101);
    int dif = 0;
    for (int i = 0; i < n; i++){
        if (!valores[arr[i]]) {
            dif++;
            valores[arr[i]] = 1;
        }
    }

    if (dif > k){
        cout << -1 << "\n";
        return;
    }

    if (dif != k){
        for (int i = 1; i <= n; i++){
            if (!valores[i]){
                arr.push_back(i);
                dif++;
            }
            if (dif == k) break;
        }
    }

    sort(arr.begin(), arr.end());
    arr.resize(unique(arr.begin(), arr.end()) - arr.begin());

    vector<int> ans;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < arr.size(); j++){
            ans.push_back(arr[j]);
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