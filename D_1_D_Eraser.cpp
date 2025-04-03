#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    int t; cin >> t;

    while(t--){
        int n, k; cin >> n >> k;

        string x; cin >> x;
        
        int ans = 0;
        int i = 0, aux = 0;
        bool ok = false;
        for (; i < n;){
            if (ok){
                if (aux == k) {
                    aux = 0;
                    ok = false;
                } else aux++;
            }
            if (x[i] == 'B' && !ok) {
                ok = true;
                aux++;
                ans++;
            }
            i++;
        }

        cout << ans << "\n";
    }
}