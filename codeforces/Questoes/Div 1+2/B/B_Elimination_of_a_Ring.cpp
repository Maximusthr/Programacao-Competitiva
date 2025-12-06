#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n; cin >> n;

    set<int> elem;
    int achou = 0;
    for (int i = 0; i < n; i++){
        int x; cin >> x;
        if (!elem.count(x)) achou++;
        elem.insert(x);
    }

    if (achou == 2){
        cout << n/2 + 1 << "\n";
    }
    else cout << n << "\n";

}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}