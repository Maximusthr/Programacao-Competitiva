// upsolve

#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n; cin >> n;

    int qtd = 0;
    int sum = 0;
    
    for (int i = 0; i < n; i++){
        int x; cin >> x;
        sum += x;
        qtd += (x > 0);
    }

    cout << min(qtd, sum - n + 1) << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}