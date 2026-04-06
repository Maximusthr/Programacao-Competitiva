#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n, m; cin >> n >> m;

    vector<int> days(m+1);

    // começo de trás para frente e vejo o maior ponto que posso obter
    // ans = accumulate(days)

    // preciso ver quais dias poderiam ser colocados de forma que você possível ganhar pontos naquele dia

    // eu nao preciso recolocar os caras em uma fila de prioridade

    priority_queue<pair<int, int>> pq;
    map<int, vector<int>> mapa;
    
    for (int i = 0; i < n; i++){
        int x, y; cin >> x >> y;
        // x dias 
        // y custo

        pq.push({y, x});
        mapa[x].push_back(y);
    }

    for (auto [x, y] : mapa){
        sort(y.begin(), y.end(), greater<int> ());
    }

    for (int i = m; i >= 1; i--){
        if (pq.empty()) break;

        pair<int, int> c = pq.top();
        pq.pop();

        if (i - c.second < 0) continue;

        days[i - c.second] = max(days[i - c.second], c.first);
    }

    cout << 1ll*accumulate(days.begin(), days.end(), 0ll) << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    solve();
}