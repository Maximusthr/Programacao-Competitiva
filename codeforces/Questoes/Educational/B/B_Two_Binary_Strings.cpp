#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    string a, b; cin >> a >> b;

    int n = a.size();

    // acho uma parte que seja 0 0 
    // e tento achar uma segunda parte que seja 1 1, pois o final eh 1

    int prob = -INF, stop = -1;
    bool ok = false, achou = false, pode = false;
    for (int i = 0; i < n; i++){
        if (a[i] == b[i] && a[i] == '0') prob = i;

        else if (a[i] == b[i] && a[i] == '1' && a[i-1] == b[i-1] && a[i-1] == '0'){
            stop = i;
            ok = true;
            break;
        }
    }

    for (int i = 0; i <= prob; i++){
        a[i] = '0';
        b[i] = '0';
    }
    if (ok){
        for (int i = stop; i < n; i++){
            a[i] = '1';
            b[i] = '1';
        }
    }

    if (a == b){
        cout << "YES" << "\n";
    }
    else cout << "NO" << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}