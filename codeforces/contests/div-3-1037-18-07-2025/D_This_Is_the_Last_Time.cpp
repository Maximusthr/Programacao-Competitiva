#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

struct cassi{
    int l, r, real;
};

void solve(){
    int n, k; cin >> n >> k;

    vector<cassi> arr(n);

    for (int i = 0; i < n; i++){
        cin >> arr[i].l >> arr[i].r >> arr[i].real;
    }

    sort(arr.begin(), arr.end(), [&](cassi &a, cassi &b){
        if (a.l != b.l) return a.l < b.l;
        return a.real > b.real;
    });

    for (int i = 0; i < n; i++){
        if (k >= arr[i].l && k <= arr[i].r){
            k = max(k, arr[i].real);
        }
    }

    cout << k << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}