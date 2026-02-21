#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n, days; cin >> n >> days;

    vector<int> a(n), b(n);
    for (auto &i : a) cin >> i;
    for (auto &i : b) cin >> i;

    deque<pair<ll, int>> pilha;
    int cont = 0;
    ll used = 0;
    ll ans = 0;

    for (int i = 0; i < n; i++){
        pilha.push_back({a[i], i});

        int qtd = b[i];
        while(!pilha.empty()){
            ll v = pilha.front().first;
            int idx = pilha.front().second;
            pilha.pop_front();

            qtd -= v;
            if (qtd > 0) continue;
            else if (qtd == 0) {
                cont++;
                break;
            }
            else {
                pilha.push_front({qtd * -1, idx});
                if (i - idx >= days){
                    pilha.pop_front();
                }
                break;
            }
        }
    }

    while(!pilha.empty()){
        ans += pilha.front().first;
        pilha.pop_front();
    }

    cout << ans << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}