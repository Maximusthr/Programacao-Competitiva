#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n; cin >> n;

    vector<int> arr(n);
    for (auto &i : arr) cin >> i;

    vector<int> ans(n);
    int maior = 0;
    for (int i = n-1; i >= 0; i--){
        if (arr[i] + i < n) ans[i] = arr[i] + ans[arr[i] + i];
        else ans[i] = arr[i];
        maior = max(maior, ans[i]);
    }

    cout << maior << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}