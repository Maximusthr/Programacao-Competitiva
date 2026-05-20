#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

pair<ll, string> memo[20][2][2][2];
bool vis[20][2][2][2];

pair<ll, string> dp(const string &teto, const string &piso, int idx, bool zero_esq, bool smaller, bool greater){
    if (idx == teto.size()){
        return {1, ""};
    }

    if (vis[idx][zero_esq][smaller][greater]) return memo[idx][zero_esq][smaller][greater];

    pair<ll, string> resp = {-1, ""};

    for (int i = 0; i <= 9; i++){
        bool small = 1, great = 1, zero = zero_esq;

        int tet = teto[idx] - '0';
        int pis = piso[idx] - '0';

        if (!smaller && i > tet) continue;
        if (!smaller && i == tet) small = 0;

        if (!greater && i < pis) continue;
        if (!greater && i == pis) great = 0;

        pair<ll, string> aux = dp(teto, piso, idx+1, (zero && i == 0), small, great);

        pair<ll, string> atual;
        if (zero_esq && i == 0) atual = {1 * aux.first, "" + aux.second};
        else atual = {i * aux.first, to_string(i) + aux.second};

        if (atual.first > resp.first){
            resp = atual;
        }
    }
    vis[idx][zero_esq][smaller][greater] = 1;
    return memo[idx][zero_esq][smaller][greater] = resp;
}

void solve(){
    string a, b; cin >> a >> b;

    if (a.size() < b.size()){
        while(a.size() != b.size()){
            a = '0' + a;
        }
    }

    memset(vis, 0, sizeof(vis));

    pair<ll, string> ans = dp(b, a, 0, 1, 0, 0);

    cout << ans.second << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    solve();
}