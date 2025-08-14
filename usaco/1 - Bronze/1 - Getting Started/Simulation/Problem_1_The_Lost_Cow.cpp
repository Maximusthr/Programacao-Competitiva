#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int x, y; cin >> x >> y;

    bool frente = true;

    int ans = 0;
    int start = 1;
    int aux = x;
    int temp = x;
    bool end = 0;
    if (x == y){
        cout << 0 << "\n";
        return;
    }
    while (!end){
        if (frente){
            aux += start;
            frente = false;
        }
        else {
            aux -= start;
            frente = true;
        }
        if (aux >= y && x < y) {
            aux = y;
            end = 1;
        }
        if (aux <= y && x > y){
            aux = y;
            end = 1;
        }
        ans += abs(temp-aux);
        start <<= 1;
        temp = aux;
        aux = x;
    }

    cout << ans << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
 
    freopen("lostcow.in", "r", stdin);
    freopen("lostcow.out", "w", stdout);

    solve();

}