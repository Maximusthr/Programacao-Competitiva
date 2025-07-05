#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int a, b, x, y; cin >> a >> b >> x >> y;

    if (a == b) {
        cout << 0 << "\n";
        return;
    }
    
    ll sum = 0;
    int temp_a = 0;

    if (a > b){
        if ((a^1) > b) {
            cout << -1 << "\n";
            return;
        }
        else {
            a = (a ^ 1);
            sum += y;
        }
    }

    while (a != b){
        temp_a = a;

        if ((temp_a ^ 1) > a){
            int aux = (temp_a^1) - a;
            int custo = y * aux;
            if (custo <= x * aux){
                sum += custo;
            }
            else sum += (x*aux);
            a = (temp_a^1);
        }
        else {
            a++;
            sum += x;
        }
    }
    cout << sum << "\n";

}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}