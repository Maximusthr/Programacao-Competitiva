// TLE caso 13
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    int n, q; cin >> n >> q;

    vector<int> arr(n);
    for (auto &i : arr) cin >> i;

    while(q--){
        int m, p, h; cin >> m >> p >> h;

        p--;

        if (m == 1) arr[p] = h;
        else {
            int ans = 1;

            for (int i = p; i < n-1; i++){
                if (abs(arr[i] - arr[i+1]) <= h) ans++;
                else break;
            }

            for (int i = p; i > 0; i--){
                if (abs(arr[i] - arr[i-1]) <= h) ans++;
                else break;
            }

            cout << ans << "\n";
        }
    }
}
