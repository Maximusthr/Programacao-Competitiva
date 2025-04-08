#include <bits/stdc++.h>

using namespace std;

const int MAX = 1e5 * 2 + 1;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    int t; cin >> t;

    while(t--){
        int n, k; cin >> n >> k;

        if (k % 4 == 2){
            cout << "YES" << "\n";
            for (int i = 3; i <= n; i += 4) cout << i << " " << i+1 << "\n";
            for (int i = 2; i <= n; i += 4) cout << i << " " << i-1 << "\n";
        }
        else if (k % 4 == 1 || k % 4 == 3){
            cout << "YES" << "\n";
            for (int i = 1; i <= n; i += 2) cout << i << " " << i+1 << "\n";
        }
        else cout << "NO" << "\n";
        
    }
}
