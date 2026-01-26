#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n, k; cin >> n >> k;

    vector<pair<int, int>> p(k);
    for (auto &i : p){
        cin >> i.first >> i.second;
        i.first--, i.second--;
    }

    vector<bool> nao(n);
    for (int i = 0; i < k; i++){
        nao[p[i].first] = 1;
        nao[p[i].second] = 1;
    }

    int pode = 0;
    for (int i = 0; i < n; i++){
        if (!nao[i]) {
            pode = i;
            break;
        }
    }

    cout << n-1 << "\n";
    for (int i = 0; i < n; i++){
        if (i == pode) continue;
        cout << i+1 << " " << pode+1 << "\n";
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    solve();
}