#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    int n, m, a, b; cin >> n >> m >> a >> b;

    auto ok = [&](int mid) -> bool {
        int aux = mid;

        // caso ambos
        ll quant_m = aux/b;
        aux -= quant_m*b;
        ll ind = aux/a;

        ll qnt = (quant_m*m + ind);

        // caso individual
        ind = mid/a;
        quant_m = mid/b;

        return (qnt >= n || ind >= n || quant_m*m >= n);
    };

    int l = 0, r = 1e7+5;
    while (l < r){
        int mid = l + (r-l)/2;

        if (ok(mid)) {
            r = mid;
        }
        else l = mid + 1;
    }

    cout << l << "\n";
}