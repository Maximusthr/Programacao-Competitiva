#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n; cin >> n;
    
    if (n <= 5) cout << -1 << "\n";
    else {
        cout << 1 << " " << 2 << "\n";
        cout << 2 << " " << 3 << "\n";
        cout << 2 << " " << 4 << "\n";
        for (int i = 5; i <= n; i++){
            cout << 4 << " " << i << "\n";
        }
    }

    cout << 1 << " " << 2 << "\n";
    for (int i = 3; i <= n; i++){
        cout << 2 << " " << i << "\n";
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    solve();
}