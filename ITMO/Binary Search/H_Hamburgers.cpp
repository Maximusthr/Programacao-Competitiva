#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

ll nb, ns, nc;
ll pb, ps, pc; 
ll coins;
map<char, int> qtd;
bool ok(ll mid){
    ll qtd_b = qtd['B'] * mid;
    ll qtd_s = qtd['S'] * mid;
    ll qtd_c = qtd['C'] * mid;

    // tiro os da cozinha
    qtd_b -= nb;
    qtd_s -= ns;
    qtd_c -= nc;

    // vou na loja e vejo quantos é preciso comprar
    ll preco = 0;
    if (qtd_b > 0) preco += qtd_b * pb;
    if (qtd_s > 0) preco += qtd_s * ps;
    if (qtd_c > 0) preco += qtd_c * pc;

    return coins >= preco;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    string h; cin >> h;
    
    for (int i = 0; i < (int)h.size(); i++){
        qtd[h[i]]++;
    }

    cin >> nb >> ns >> nc;
    cin >> pb >> ps >> pc;
    cin >> coins;

    ll l = 0, r = 2e12+1;
    ll ans = 0;
    while (l <= r){
        ll mid = l + (r-l)/2;

        if (ok(mid)){
            ans = mid;
            l = mid + 1;
        }
        else r = mid - 1;
    }

    cout << ans << "\n";
}
