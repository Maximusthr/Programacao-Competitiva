#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n, q; cin >> n >> q;
    
    vector<int> arr(n);
    for (auto &i : arr) cin >> i;

    vector<int> prefix(n+2);
    for (int i = 1; i <= n; i++){   
        prefix[i] = (arr[i-1] ^ prefix[i-1]);
    }

    while(q--){
        int x, y; cin >> x >> y;

        cout << (prefix[y] ^ prefix[x-1]) << "\n";
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    solve();
}