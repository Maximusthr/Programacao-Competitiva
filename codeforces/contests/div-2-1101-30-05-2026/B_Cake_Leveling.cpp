#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n; cin >> n;

    vector<ll> arr(n);
    for (auto &i : arr) cin >> i;

    ll sum = 0;
    ll atual = arr[0];
    for (int i = 0; i < n; i++){
        sum += arr[i];

        if (arr[i] < atual) atual = min(atual, sum/(i+1));
        cout << atual << " \n"[i+1 == n];
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}