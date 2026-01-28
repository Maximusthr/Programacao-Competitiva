#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n, m; cin >> n >> m;

    if (n > 30){
        cout << m << "\n";
        return;
    }

    cout << m % (1 << n) << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    solve();
}