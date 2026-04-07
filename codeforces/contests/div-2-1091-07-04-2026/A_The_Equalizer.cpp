#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n, k; cin >> n >> k;

    vector<int> arr(n);
    for (auto &i : arr) {
        cin >> i;
    }

    int sum = accumulate(arr.begin(), arr.end(), 0);

    if (sum & 1){
        cout << "YES" << "\n";
        return;
    }

    if (n % 2 == 0){
        cout << "YES" << "\n";
    }
    else if (n % 2 == 1 && k % 2 == 0){
        cout << "YES" << "\n";
    }
    else {
        cout << "NO" << "\n";
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}