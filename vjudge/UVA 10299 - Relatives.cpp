#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    int n;
    while(cin >> n && n){
        int ans = n;

        if (n == 1){
            cout << 0 << "\n";
            continue;
        }

        for (int i = 2; i * i <= n; i++){
            if (n % i == 0){
                while(n % i == 0){
                    n /= i;
                }
                ans -= ans/i;
            }
        }

        if (n > 1){
            ans -= ans/n;
        }

        cout << ans << "\n";
    }
}