#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(string s){
    if (s == "first"){
        int n, m; cin >> n >> m;

        vector<vector<int>> g(n);
        for (int i = 0; i < m; i++){
            int x, y; cin >> x >> y;
            x--, y--;
            g[x].push_back(y);
            g[y].push_back(x);
        }

        vector<int> dist(n, -1);

        queue<int> q;
        dist[0] = 0;
        q.push(0);
        while (!q.empty()){
            int u = q.front();

            q.pop();

            for (auto v : g[u]){
                if (dist[v] == -1){
                    dist[v] = dist[u] + 1;
                    q.push(v);
                }
            }
        }

        string ans;
        for (int i = 0; i < n; i++){
            if (dist[i] % 3 == 0) ans.push_back('r');
            else if (dist[i] % 3 == 1) ans.push_back('b');
            else ans.push_back('g');
        }

        cout << ans << "\n";
    }
    else {
        int q; cin >> q;
        while(q--){
            int x; cin >> x;
            string c; cin >> c;

            bool r = false, g = false, b = false;
            for (int i = 0; i < x; i++){
                if (c[i] == 'r') r = true;
                else if (c[i] == 'b') b = true;
                else g = true;
            }

            char alvo = '#';
            if (g && b){
                // vai pro verde
                alvo = 'g';
            }
            else if (r && g){
                // vai pro vermelho
                alvo = 'r';
            }
            else if (b && r){
                // vai pro azul
                alvo = 'b';
            }

            if (alvo == '#') cout << 1 << "\n";
            else {
                for (int i = 0; i < x; i++){
                    if (c[i] == alvo) {
                        cout << i + 1 << "\n";
                        break;
                    }
                }
            }


        }
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    string s; cin >> s;

    int t; cin >> t;
    while(t--){
        solve(s);
    }
}