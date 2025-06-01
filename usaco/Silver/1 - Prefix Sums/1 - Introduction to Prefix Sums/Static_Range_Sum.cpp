#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    int n, q; cin >> n >> q;

    vector<ll> arr(n);
    for (auto &i : arr) cin >> i;

    for (int i = 1; i < n; i++){
        arr[i] += arr[i-1];
    }

    while(q--){
        int x, y; cin >> x >> y;
        x--;
        y--;

        if (x == -1) cout << arr[y] << "\n";
        else cout << arr[y] - arr[x] << "\n";
    }
}