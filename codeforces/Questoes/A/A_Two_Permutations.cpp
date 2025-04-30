#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    int t; cin >> t;

    while(t--){
        int n, a, b; cin >> n >> a >> b;

        if (n == 1 || (n == a && n == b)) cout << "YES" << "\n";
        else {
            if (a + b + 2 <= n) cout << "YES" << "\n";
            else cout << "NO" << "\n";
        }
    }
}
