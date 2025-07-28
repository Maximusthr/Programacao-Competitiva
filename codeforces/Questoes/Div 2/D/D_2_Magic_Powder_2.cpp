#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

vector<ll> a;
vector<ll> b;
int n, k;

bool ok(ll mid){

    ll aux = k;

    for (int i = 0; i < n; i++){
        ll v = b[i]/a[i];

        if (v >= mid) continue;
        else {
            aux -= abs(mid*a[i] - b[i]);
            if (aux < 0){
                break;
            }
        }
    }

    return (aux >= 0);

}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    cin >> n >> k;
    a.resize(n);
    b.resize(n);

    for (auto &i : a) cin >> i;
    for (auto &i : b) cin >> i;

    ll l = 0, r = 1e18+5;
    while (l < r){
        ll mid = l + (r-l+1)/2;

        if (ok(mid)){
            l = mid;
        }
        else r = mid-1;
    }

    cout << l << "\n";
}