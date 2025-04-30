#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    int t; cin >> t;

    while(t--){
        ll n, f, a, b; cin >> n >> f >> a >> b;
        
        vector<ll> arr(n);
        for (auto &i : arr) cin >> i;

        bool ok = true;
        for (int i = 0; i < n; i++){
            if (i == 0){
                if (arr[i] * a <= b) {
                    f -= a * arr[i];
                }
                else f -= b;
                
            }
            else {
                if ((arr[i] - arr[i-1]) * a <= b){
                    f -= (arr[i]-arr[i-1]) * a;
                }
                else {
                    f -= b;
                }
            }
            if (f <= 0) {
                ok = false;
                break;
            }
        }

        cout << (ok ? "YES" : "NO") << "\n";
    }
}
