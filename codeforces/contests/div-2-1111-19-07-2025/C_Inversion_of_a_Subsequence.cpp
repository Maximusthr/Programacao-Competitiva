#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n; cin >> n;

    vector<int> a(n), b(n);
    for (auto &i : a) cin >> i;
    for (auto &i : b) cin >> i;

    if (a == b){
        cout << 0 << "\n";
        return;
    }

    bool tem_0 = false;
    bool tem_a = false;
    bool tem_1 = false;
    for (int i = 0; i < n; i++){
        tem_0 |= (b[i] == 0);
        tem_a |= (a[i] == 0);
        tem_1 |= (a[i] == 1);
    }

    if ((!tem_0 && tem_a) || !tem_1){
        cout << -1 << "\n";
        return;
    }

    int sum = 0;
    for (int i = 0; i < n; i++){
        if (a[i] != b[i] && a[i] == 1) sum++;
    }
    
    cout << (sum & 1 ? 1 : 2) << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}