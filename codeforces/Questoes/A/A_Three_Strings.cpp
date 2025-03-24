#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    int t; cin >> t;

    while(t--){
        string a, b, c; cin >> a >> b >> c;

        bool ok = true;
        for (int i = 0; i < (int)c.size(); i++){
            if (c[i] != a[i] && c[i] != b[i]) {
                ok = false;
                break;
            }
        }
        cout << (!ok ? "NO" : "YES") << "\n";
    }
}
