#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n; cin >> n;

    map<string, int> mapa;
    for (int i = 0; i < n; i++){
        string s; cin >> s;
        mapa[s]++;
    }

    int ans = 0;
    for (auto [x, y] : mapa){
        ans = max(ans, y);
    }

    cout << ans << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    solve();
}