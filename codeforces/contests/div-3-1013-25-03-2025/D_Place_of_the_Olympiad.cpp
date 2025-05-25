#include <bits/stdc++.h>

using namespace std;

// Couldn't Solve

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    int t; cin >> t;

    while(t--){
        int n, m, k; cin >> n >> m >> k;

        if (n >= k) {
            cout << 1 << "\n";
            continue;
        }

        int ans = 1;
        k -= n;
        while (k > 0){
            k -= m;
            ans++;
        }

        cout << ans << "\n";
    }
}