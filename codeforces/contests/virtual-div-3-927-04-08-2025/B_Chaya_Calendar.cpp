#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n; cin >> n;

    vector<ll> arr(n);
    for (int i = 0; i <n; i++){
        cin >> arr[i];
    }

    bool aconteceu = false;
    ll ano = arr[0];
    for (int i = 1; i < n; i++){
        ll val = ano/arr[i];

        ano = (val+1) * arr[i];
    }

    cout << ano << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}