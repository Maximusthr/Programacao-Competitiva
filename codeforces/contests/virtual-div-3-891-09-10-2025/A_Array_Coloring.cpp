#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n; cin >> n;

    int odd = 0, even = 0;
    for (int i = 0; i < n; i++){
        int x; cin >> x;
        if (x % 2) odd++;
        else even++;
    }

    if (odd % 2 == 0){
        cout << "YES" << "\n";
    }
    else if (odd % 2) {
        cout << "NO" << "\n";
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}