// upsolve

#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    int t; cin >> t;

    while(t--){
        int n; cin >> n;

        cout << 2*n-1 << "\n";
        for (int i = 1; i <= n; i++){
            cout << i << " " << 1 << " " << i << "\n";
            if (i != n) cout << i << " " << i+1 << " " << n << "\n";
        }
    }
}