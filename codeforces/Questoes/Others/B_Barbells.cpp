#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

vector<int> pesos;
int n, m;

bool ok = false;
void possivel(int index, ll esquerda, ll direita){
    if (index == pesos.size()){
        if (esquerda == direita){
            ok = true;
        }
        return;
    }

    possivel(index + 1, esquerda + pesos[index], direita);
    possivel(index + 1, esquerda, direita + pesos[index]);

}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    cin >> n >> m;

    vector<ll> arr(n);
    for (auto &i : arr) cin >> i;

    vector<ll> b(m);
    for (auto &i : b) cin >> i;

    set<ll> ans;

    for (int mask = 0; mask < (1 << m); mask++){
        ll sum = 0;
        for (int bit = 0; bit < m; bit++){
            if (mask & (1 << bit)){
                sum += b[bit];
                pesos.push_back(b[bit]);

            }
        }

        possivel(0, 0, 0);

        if (ok){
            ans.insert(sum);
        }

        ok = false;
        pesos.clear();
    }

    set<ll> ans2;

    for (int i = 0; i < n; i++){
        for (auto it : ans){
            ans2.insert(arr[i] + it);
        }
    }

    for (auto i : ans2) cout << i << "\n";
}