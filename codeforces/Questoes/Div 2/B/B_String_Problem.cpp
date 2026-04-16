#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 26;

void solve(){
    string s; cin >> s;
    string b; cin >> b;

    if (s.size() != b.size()){
        cout << -1 << "\n";
        return;
    }

    vector<vector<int>> dist(MAX, vector<int> (MAX, INF));
    int q; cin >> q;
    while(q--){
        char c, d; cin >> c >> d;
        int w; cin >> w;

        dist[c-'a'][d-'a'] = min(dist[c-'a'][d-'a'], w);
    }

    for (int k = 0; k < MAX; k++){
        for (int i = 0; i < MAX; i++){
            for (int j = 0; j < MAX; j++){
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    int ans = 0;
    vector<char> carac;
    for (int i = 0; i < s.size(); i++){
        if (s[i] == b[i]) {
            carac.push_back(s[i]);
            continue;
        }

        int menor = INF;
        char c;
        for (int j = 0; j < MAX; j++){
            int vs = dist[s[i]-'a'][j];
            int vb = dist[b[i]-'a'][j];

            if (j == s[i]-'a') vs = 0;
            if (j == b[i]-'a') vb = 0;

            menor = min(vs + vb, menor);
            if (vs + vb == menor) c = j + 'a';
        }

        if (menor == INF) {
            cout << -1 << "\n";
            return;
        }

        carac.push_back(c);
        ans += menor;
    }

    cout << ans << "\n";
    for (auto &i : carac) cout << i;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    solve();
}