#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    ll h, c, temp; cin >> h >> c >> temp;

    if (h == temp){
        cout << 1 << "\n";
        return;
    }
    if ((h+c) >= 2 * temp){
        cout << 2 << "\n";
        return;
    }

    ll l = 0, r = 1e9;
    while(l < r){
        ll mid = l + (r-l+1)/2;

        if ((mid + 1) * h + mid * c >= (2 * mid + 1) * temp) l = mid;
        else r = mid - 1;
    }

    ll v1 = (((l + 1)*h + l*c - (2*l + 1) * temp)) * (2 * l + 3);

    ll v2 = -1 * ((l + 2)*h + (l + 1)*c - (2 * l + 3) * temp) * (2 * l + 1);

    if (v1 <= v2){
        cout << 2 * l + 1 << "\n";
    }
    else cout << 2 * l + 3 << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}