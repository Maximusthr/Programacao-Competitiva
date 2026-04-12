#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n; cin >> n;
    vector<int> arr(n);
    for (auto &i : arr) cin >> i;
    sort(arr.begin(), arr.end());

    int menor = arr[0];
    int c_m = 0;
    int maior = arr.back();
    int c_mai = 0;
    for (int i = 0; i < n; i++){
        if (arr[i] == menor) c_m++;
        else if (arr[i] == maior) c_mai++;
    }

    if (menor == maior) {
        cout << 1ll * c_m * (c_m - 1) << "\n";
    }
    else {
        ll ans = 1ll * c_m * c_mai * 2;
        cout << ans << "\n";
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}