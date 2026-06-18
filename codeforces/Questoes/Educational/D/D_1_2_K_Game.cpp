#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n, k; cin >> n >> k;

    if (k % 3 != 0 || n < k){
        cout << (n % 3 == 0 ? "Bob" : "Alice") << "\n";
        return;
    }

    n %= (k+1);
    if (n == k) cout << "Alice" << "\n";
    else if (n % 3 == 0) cout << "Bob" << "\n";
    else cout << "Alice" << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}