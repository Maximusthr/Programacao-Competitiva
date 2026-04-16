#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n; cin >> n;

    vector<int> freq(30);
    for (int i = 0; i < n; i++){
        int x, y; cin >> x >> y;
        if (x == 1) {
            freq[y]++;
        }
        else {
            for (int j = 29; j >= 0; j--){
                if ((1 << j) > y) continue;
                
                ll l = 0, r = freq[j];
                while(l < r){
                    ll mid = (l+r)/2;

                    if ((1ll*mid << j) > y) r = mid;
                    else l = mid + 1;
                }
                if (l * (1ll << j) > y) l--; 

                y -= (1ll << j) * l;
            }
            if (y == 0) cout << "YES" << "\n";
            else cout << "NO" << "\n";
        }
    }

}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    solve();
}