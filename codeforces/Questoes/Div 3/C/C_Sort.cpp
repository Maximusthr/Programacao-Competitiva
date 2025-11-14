#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n, q; cin >> n >> q;

    string a, b; cin >> a >> b;

    vector<vector<int>> pref(n+1, vector<int>(26)), pppref(n+1, vector<int> (26));
    for (int i = 1; i <= n; i++){
        pref[i][(a[i-1] - 'a')]++;
        pppref[i][(b[i-1] - 'a')]++;

        for (int j = 0; j < 26; j++){
            pref[i][j] += pref[i-1][j];
            pppref[i][j] += pppref[i-1][j];
        }
    }

    while(q--){
        int x, y; cin >> x >> y;

        int dif = 0;
        for (int i = 0; i < 26; i++){
            int v = pref[y][i] - pref[x-1][i];
            int v2 = pppref[y][i] - pppref[x-1][i];

            dif += abs(v2-v);
        }

        cout << dif/2 << "\n";
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}