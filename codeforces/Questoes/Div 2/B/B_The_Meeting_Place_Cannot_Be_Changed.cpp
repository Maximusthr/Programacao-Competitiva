#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int n;
vector<int> pos;
vector<int> v;

bool ok(double m){
    double l = -2e18;
    double r = 2e18;
    for (int i = 0; i < n; i++){
        l = max(l, (double)pos[i] - m*v[i]);
        r = min(r, (double)pos[i] + m*v[i]);
    }

    return (l <= r);
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    cin >> n;
    pos.resize(n);
    v.resize(n);
    for (auto &i : pos) cin >> i;
    for (auto &i : v ) cin >> i;
    
    double l = 0, r = 1e18;
    for (int i = 0; i < 100; i++){
        double mid = l + (r-l)/2;

        if (ok(mid)){
            r = mid;
        }
        else l = mid;
    }

    cout << setprecision(7) << l << "\n";
}