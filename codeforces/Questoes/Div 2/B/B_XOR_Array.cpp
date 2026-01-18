#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n, l, r; cin >> n >> l >> r;

    vector<int> arr(n+1);

    for (int i = 1; i <= n; i++){
        arr[i] = i;
    }

    arr[r] = arr[l-1];

    vector<int> p(n+1);
    for (int i = 1; i <= n; i++){
        p[i] = arr[i] ^ arr[i-1];
    }

    for (int i = 1; i <= n; i++){
        cout << p[i] << " \n"[i == n];
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}