#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n, s, x; cin >> n >> s >> x;

    vector<int> arr(n);
    for (auto &i : arr) cin >> i;

    int sum = accumulate(arr.begin(), arr.end(), 0);
    while (sum < s){
        sum += x;
    }

    if (sum == s) {
        cout << "YES" << "\n";
    }   
    else cout << "NO" << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}