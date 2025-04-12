// CS

#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    int n, k; cin >> n >> k;

    vector<int> a(n+1);
    
    for (int i = 0; i <= n; i++) a[i] = 1;
    int s = k;
    
    for (int i = k; i <= n; i++){
        a[i] = s;
        s -= a[i-k];
        s += a[i];
        s %= MOD;
        if (s < 0) s += MOD;
        //s = (s - a[i-k] + a[i]) % MOD;
    }
    
    cout << a[n] << "\n";
}
