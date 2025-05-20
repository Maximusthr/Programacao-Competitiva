#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n, m; cin >> n >> m;

    vector<string> c1(n);
    for (int i = 0; i < n; i++) cin >> c1[i];

    vector<string> c2(n);
    for (int i = 0; i < n; i++) cin >> c2[i];
    
    int ans = 0;
    
    for (int i = 0; i < m; i++){
        vector<char> g;
        map<char, int> verif;
        for (int j = 0; j < n; j++){
            // cows_1
            g.push_back(c1[j][i]);
        }

        for (int j = 0; j < n; j++){
            // cows_2
            verif[c2[j][i]]++;
        }

        bool ok = false;
        for (int i = 0; i < g.size(); i++){
            if (verif[g[i]]) {
                ok = true;
                break;
            }
        }
        if (!ok) ans++;

    }

    cout << ans << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    freopen("cownomics.in", "r", stdin);
    freopen("cownomics.out", "w", stdout);

    solve();
}
