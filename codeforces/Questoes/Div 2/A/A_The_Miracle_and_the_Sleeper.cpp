#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    int t; cin >> t;

    while(t--){
        int l, r; cin >> l >> r;

        if (l <= r/2 + 1) {
            cout << r % (r/2 + 1) << "\n";
        }
        else cout << r % l << "\n";
    }
}