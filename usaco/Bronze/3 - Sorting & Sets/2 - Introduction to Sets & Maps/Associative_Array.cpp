#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    int t; cin >> t;
    map<ll, ll> elem;

    while(t--){
        int x; cin >> x;

        if (x == 0){
            ll y, qtd; cin >> y >> qtd;
            elem[y] = qtd;
        }
        if (x == 1){
            ll y; cin >> y;
            cout << elem[y] << "\n";
        }
    }
}