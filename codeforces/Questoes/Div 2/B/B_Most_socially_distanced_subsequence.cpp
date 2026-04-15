#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n; cin >> n;

    vector<int> arr(n);
    for (auto &i : arr) cin >> i;

    vector<int> ans;
    ans.push_back(arr[0]);
    

    int sum = 0;
    for (int i = 1; i < n-1; i++){
        if (arr[i] < arr[i+1] && arr[i] > arr[i-1]) continue;
        if (arr[i] > arr[i+1] && arr[i-1] > arr[i]) continue;
        ans.push_back(arr[i]);
    }
    ans.push_back(arr.back());

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