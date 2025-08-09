#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

ll exp(ll a, ll b){
    ll x = 1;
    while (b > 0){
        if (b % 2) x *= a;
        b >>= 1;
        a *= a;
    }

    return x;
}

void transf(ll n, vector<int> &bin){
    for (int i = 0; i < 63; i++){
        if (n & (1LL << i)){
            bin.push_back(1);
        }
        else bin.push_back(0);
    }
}

void solve(){
    ll l, r; cin >> l >> r;

    if (l == r){
        cout << r << "\n";
        return;
    }

    // basta ver o primeiro bit diferente de cada um, o resto depois desse pode ser 1
    // depois passamos do ponto de quebra voltando, pois pode haver mais uns.

    vector<int> bin1;
    vector<int> bin2;

    transf(r, bin1);
    reverse(bin1.begin(), bin1.end());

    transf(l, bin2);
    reverse(bin2.begin(), bin2.end());

    int pos = -1;
    for (int i = 0; i < 63; i++){
        if (bin1[i] != bin2[i]){
            pos = i;
            break;
        }
    }

    int qtd = 0;
    for (int i = pos+1; i < 63; i++) qtd++;

    for (int i = 0; i < pos; i++){
        if (r & (1LL << (62-i))) qtd++;
    }

    int count_r = 0;
    for (int i = 0; i < 63; i++){
        if (r & (1LL << i)) count_r++;
    }

    if (count_r > qtd) cout << r << "\n";
    else {
        vector<int> ans_bin;
        for (int i = 0; i < pos; i++){
            if (r & (1LL << (62-i))) ans_bin.push_back(1);
            else ans_bin.push_back(0);
        }
        ans_bin.push_back(0); // pos
        for (int i = pos+1; i < 63; i++){
            ans_bin.push_back(1);
        }

        ll ans = 0;
        for (int i = 0, j = 62; i < ans_bin.size(); i++, j--){
            ans += exp(2, j) * ans_bin[i];
        }

        cout << ans << "\n";
    }

}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}