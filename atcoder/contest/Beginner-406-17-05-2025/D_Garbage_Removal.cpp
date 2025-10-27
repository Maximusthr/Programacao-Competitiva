#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 2e5 + 5;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    int n, m, k; cin >> n >> m >> k;

    vector<vector<int>> g(MAX);
    vector<vector<int>> h(MAX);
    for (int i = 0; i < k; i++){
        int x, y; cin >> x >> y;
        x--, y--;
        g[x].push_back(i);
        h[y].push_back(i);
    }

    vector<bool> col(MAX), row(MAX), total(MAX);

    int q; cin >> q;
    while(q--){
        int x; cin >> x;
        if (x == 1){
            int y; cin >> y;
            y--;
            int todo = 0;
            if (!row[y]) {
                for (auto e : g[y]){
                    if (!total[e]){
                        todo++;
                        total[e] = true;
                    }
                }
                row[y] = true;
            }
            cout << todo << "\n";
        }
        else {
            int y; cin >> y;
            y--;
            int todo = 0;
            if (!col[y]){
                for (auto e : h[y]){
                    if (!total[e]){
                        todo++;
                        total[e] = true;
                    }
                }
                col[y] = true;
            } 
            cout << todo << "\n";
        }
    }
}