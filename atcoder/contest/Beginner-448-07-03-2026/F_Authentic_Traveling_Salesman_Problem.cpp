// upsolve
// semelhante a ordenação do algoritmo Mo

#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n; cin >> n;

    vector<array<int, 3>> dist(n);
    for (int i = 0; i < n; i++){
        int x, y; cin >> x >> y;

        dist[i][0] = x;
        dist[i][1] = y;
        dist[i][2] = i;
    }

    int bloco = 155;
    sort(dist.begin()+1, dist.end());

    for (int i = 0; i < n; i++){
        swap(dist[i][0], dist[i][1]);
    }

    for (int i = 1; i < n; i += bloco){
        if (i & 1){
            sort(dist.begin()+i, dist.begin()+min(n, i+bloco));
        }
        else {
            sort(dist.begin()+i, dist.begin()+min(n, i+bloco), greater<>());
        }
    }
    for (int i = 0; i < n; i++){
        cout << dist[i][2] + 1 << " \n"[i == n-1];
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    solve();
}