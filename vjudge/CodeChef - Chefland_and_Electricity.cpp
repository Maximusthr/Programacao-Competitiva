#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n; cin >> n;
    string s; cin >> s;

    vector<int> idx;
    for (int i = 0; i < n; i++){
        if (s[i] == '1') idx.push_back(i);
    }

    vector<int> arr(n);
    for (auto &i : arr) cin >> i;

    if (n == 1){
        cout << 0 << "\n";
        return;
    }

    int ans = 0;
    for (int i = 1; i <= idx[0]; i++){
        ans += arr[i] - arr[i-1];
    }
    for (int i = idx.back(); i < n-1; i++){
        ans += arr[i+1] - arr[i];
    }
    
    for (int i = 0; i < idx.size()-1; i++){
        if (idx[i+1] - idx[i] == 1) continue;

        int diff = arr[idx[i+1]] - arr[idx[i]];
        int temp = diff;

        for (int j = idx[i] + 1; j <= idx[i+1]; j++){
            temp = min(temp, diff - (arr[j] - arr[j-1]));
        }
        ans += temp;
    }   

    cout << ans << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}