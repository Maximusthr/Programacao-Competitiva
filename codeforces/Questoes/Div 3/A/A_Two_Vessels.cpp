#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int a, b, x; cin >> a >> b >> x;

    if (a > b) swap(a, b);

    int alvo = (a + b + 1)/2;
    int v = (alvo + x - 1 - a);

    cout << v/x << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}