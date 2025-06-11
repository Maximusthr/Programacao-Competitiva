#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    int t; cin >> t;

    while(t--){
        int n, m; cin >> n >> m;

        if (n == 1 && m == 1) cout << 0;
        else if (n == 1 || m == 1) cout << max(n, m);
        else if (n >= m) cout << n + (m-1)*2;
        else cout << m + (n-1)*2;

        cout << "\n";
    }
}
