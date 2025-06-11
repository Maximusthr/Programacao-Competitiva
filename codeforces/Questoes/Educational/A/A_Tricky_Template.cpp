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

        string a, b, c; cin >> a >> b >> c;

        bool ok = false;
        for (int i = 0; i < n; i++){
            if (c[i] == a[i] || c[i] == b[i]) continue;
            else {
                ok = true;
                break;
            }
        }

        if (ok) cout << "YES" << "\n";
        else cout << "NO" << "\n";
    }
}
