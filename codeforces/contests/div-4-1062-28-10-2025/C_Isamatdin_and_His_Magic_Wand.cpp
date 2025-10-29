#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n; cin >> n;

    vector<int> odd, even;
    vector<int> arr(n);
    for (int i = 0; i < n; i++){
        cin >> arr[i];
        if (arr[i]%2) odd.push_back(arr[i]);
        else even.push_back(arr[i]);
    }

    if (odd.size() > 0 && even.size() > 0){
        sort(arr.begin(), arr.end());
    }
    for (auto &i : arr) cout << i << " ";
    cout << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}