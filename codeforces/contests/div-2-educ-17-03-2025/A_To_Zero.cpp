#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    int t; cin >> t;

    while(t--){
        int n, k; cin >> n >> k;

        bool ok = false;
        int ans = 0;
        if (n == k) {
            ans++;
            ok = true;
        }
        if (n % 2 == 1 && !ok){
            ans++;
            n -= k;
        }
        if (n % 2 == 0 && !ok){
            ans += n / (k-1);
            ans += (n % (k-1) != 0 ? 1 : 0);
        }

        cout << ans << "\n";
    }
}
