#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 1e5+5;
vector<int> g[MAX];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    freopen("planting.in", "r", stdin);
    freopen("planting.out", "w", stdout);

    int n; cin >> n;
    for (int i = 0; i < n-1; i++){
        int x, y; cin >> x >> y;
        x--;
        y--;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    int ans = 0;
    for (int i = 0; i < n; i++){
        ans = max(ans, (int) g[i].size() + 1);
    }
    
    cout << ans << "\n";
}