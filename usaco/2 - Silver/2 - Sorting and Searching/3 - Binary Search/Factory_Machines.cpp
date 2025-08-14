#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

ll n, k;
vector<ll> arr(n);

bool ok(ll mid){
    ll qtd = 0;
    for (int i = 0; i < n; i++){
        qtd += (mid/arr[i]);
        if (qtd >= k) break;
    }

    return qtd >= k;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    cin >> n >> k;

    arr.resize(n);

    for (auto &i : arr) cin >> i;

    ll l = 0, r = 1e18;
    while (l < r){
        ll mid = l + (r-l)/2;

        if (ok(mid)){
            r = mid;
        }
        else l = mid + 1;
    }

    cout << l << "\n";
}