#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 1e6 + 5;

vector<bool> tem(MAX);

void solve(){
    int n; cin >> n;

    if (tem[n]) cout << "YES" << "\n";
    else cout << "NO" << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    // pre-calculo de k
    for (int i = 2; i < 2000; i++){
        if (1ll*i*i > MAX) break;
        ll tot = i * i;
        ll serie = 1 + i + tot;
        for (int p = 2; p <= 20; p++){
            if (serie > MAX) break;
            tem[serie] = true;
            tot *= i;
            serie += tot;
        }
    }

    int t; cin >> t;
    while(t--){
        solve();
    }
}