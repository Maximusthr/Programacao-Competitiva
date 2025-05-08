#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    int t; cin >> t;

    while(t--){
        ll n; cin >> n;
        ll sum = n * (n+1)/2;
        ll square = 1LL*sqrt(sum);

        if (square * square == sum) cout << -1 << "\n";
        else {
            bool ok = false;
            ll sum_aux = 0;
            for (int i = 1; i <= n; i++){
                if (ok){
                    sum_aux += i-1;
                }
                else sum_aux += i;
                ll s = 1LL*sqrt(sum_aux);
                if (s * s == sum_aux && !ok){
                    ok = true;
                    sum_aux++;
                    cout << i+1 << " ";
                }
                else if (ok) {
                    cout << i-1 << " ";
                    ok = false;
                }
                else cout << i << " ";
            }
            cout << "\n";
        }
    }
}
