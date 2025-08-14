#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 101;
vector<int> g[MAX];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    freopen("factory.in", "r", stdin);
    freopen("factory.out", "w", stdout);

    int n; cin >> n;

    for (int i = 0; i < n-1; i++){
        int x, y; cin >> x >> y;
        x--;
        y--;
        g[x].push_back(y);
    }

    int ans = INF;
    int aux = 0;
    for (int i = 0; i < n; i++){
        if (g[i].size() == 0){
            ans = i+1;
            aux++;
        }
        if (aux == 2){
            ans = INF;
            break;
        }
    }

    cout << (ans == INF ? -1 : ans) << "\n";
}