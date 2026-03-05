#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 1e5+5;

void solve(){
    int n, m; cin >> n >> m;

    vector<int> a(n), b(m);
    for (auto &i : a) cin >> i;
    for (auto &i : b) cin >> i;

    vector<bool> todos(MAX);

    int i = 0, j = 0;
    ll qtd = 0;
    ll ans = 0;
    while (j < m){
        while(i < n && !todos[b[j]]){
            qtd++;
            todos[a[i]] = 1;
            i++;
        }
        qtd--;
        ans += 2*(qtd) + 1;
        j++;
        while(j < m && todos[b[j]]){
            j++;
            ans++;
            qtd--;
        }
        qtd = max(qtd, 0ll);
    }

    cout << ans << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}