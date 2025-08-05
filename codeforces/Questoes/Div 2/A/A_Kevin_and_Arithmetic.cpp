#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n; cin >> n;
    vector<int> arr(n);
    for (auto &i : arr) cin >> i;

    int sum = 0;
    int a = 0;
    for (int i = 0; i < n; i++){
        if (arr[i] % 2) sum++;
        else a++;
    }

    if (a == 0) {
        sum--;
    }

    cout << sum + (a > 0) << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}