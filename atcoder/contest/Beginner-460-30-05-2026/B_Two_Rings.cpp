#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    ll x1, y1, r1, x2, y2, r2; cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;

    ll dist = (x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1);

    if (dist > abs(r1 - r2) * abs(r1 - r2) && dist < (r1 + r2) * (r1 + r2)){
        cout << "Yes" << "\n";
    }
    else if (dist == (r1 + r2) * (r1 + r2)){
        cout << "Yes" << "\n";
    }
    else if (dist == abs(r1 - r2) * abs(r1 - r2)){
        cout << "Yes" << "\n";
    }
    else cout << "No" << "\n";
}

// 1 2 5 3 2 1


int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}