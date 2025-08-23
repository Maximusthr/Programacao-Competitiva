#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

vector<pair<ll, ll>> elem;
ll n, pos;

bool ok (ll mid){
    // ll seg = 0;

    // for (int i = 0; i < n; i++){
    //     if (elem[i].first > mid) continue;

    //     seg += min((mid - elem[i].first)/elem[i].first + 1, (elem[i].second - elem[i].first)/elem[i].first + 1);
    //     if (mid == elem[i].second) seg--;
    //     else if (mid < elem[i].second && mid % elem[i].first == 0) seg--;
    // }

    // return seg < pos;

    ll count = 0;
    for (ll i = 1; i <= n; i++){
        count += min(n, mid / i);
    }
    return count < pos;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    cin >> n;

    pos = (n*n)/2 + 1;

    for (ll i = 1; i <= n; i++){
        elem.push_back({i, i * n});
    }

    ll l = 0, r = n*n;
    while(l < r){
        ll mid = l + (r-l+1)/2;

        if (ok(mid)){
            l = mid;
        }
        else r = mid-1;
    }

    cout << l+1 << "\n";
}