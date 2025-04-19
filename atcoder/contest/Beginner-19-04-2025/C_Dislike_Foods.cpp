#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 3e5+1;

vector<int> g[MAX];
// vector<vector<int>> g(MAX, vector<int> (MAX))

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    int n, m; cin >> n >> m;

    vector<int> qtd(m);
    for (int i = 0; i < m; i++){
        cin >> qtd[i];
        for (int j = 0; j < qtd[i]; j++){
            int x; cin >> x;
            g[x].push_back(i);
        }
    }

    int ans = 0;
    for (int i = 0; i < n; i++){
        int x; cin >> x;
        for (int &j : g[x]){
            qtd[j]--;
            if (!qtd[j]) ans++;
        }
        cout << ans << "\n";
    }
}
