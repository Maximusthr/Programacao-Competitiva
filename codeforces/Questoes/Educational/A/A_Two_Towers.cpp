#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n, m; cin >> n >> m;
    string a, b; cin >> a >> b;

    int tem = 0, tem2 = 0;
    for (int i = 0; i < n-1; i++){
        if (a[i] == a[i+1]) {
            tem++;
        }
    }
    for (int i = 0; i < m-1; i++){
        if (b[i] == b[i+1]) {
            tem2++;
        }
    }

    if (tem > 1 || tem2 > 1){
        cout << "NO" << "\n";
        return;
    }

    if (tem || tem2){
        if (a.back() == b.back()) {
            cout << "NO" << "\n";
            return;
        }
    }

    if (tem && tem2) cout << "NO" << "\n";
    else cout << "YES" << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}