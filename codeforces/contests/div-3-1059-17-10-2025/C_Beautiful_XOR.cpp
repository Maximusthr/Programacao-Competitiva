#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int x, y; cin >> x >> y;

    int initial = x;

    if (x == y){
        cout << 0 << "\n";
        return;
    }
    // if (x < y){
    //     cout << -1 << "\n";
    //     return;
    // }

    // ativamos todos os bits
    // desativamos só o necessário

    int pos = 32 - __builtin_clz(x);
    int num = 0; 
    for (int i = pos-1; i >= 0; i--){
        if (!(x & (1 << i))){
            num += (1 << i);
        }
    }

    vector<int> ans;
    ans.push_back(num);

    // desativamos só o necessario
    x = (x ^ num);
    num = 0;
    for (int i = pos-1; i >= 0; i--){
        if ((!(y & (1 << i))) && (x & (1 << i))){
            num += (1 << i);
        }
    }

    ans.push_back(num);

    if ((initial ^ ans[0] ^ ans[1]) == y){
        cout << 2 << "\n";
        cout << ans[0] << " " << ans[1] << "\n";
    }
    else cout << -1 << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}