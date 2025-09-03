#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    string a, b; cin >> a >> b;

    if (b > a) swap(b, a);

    int n = a.size();

    bool ok = false;
    for (int i = 0; i < n; i++){
        if (!ok && a[i] == b[i]) continue;
        else if (!ok) {
            ok = true;
            continue;
        }
        if (a[i] > b[i]) swap(a[i], b[i]);
    }

    cout << a << "\n";
    cout << b << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}
