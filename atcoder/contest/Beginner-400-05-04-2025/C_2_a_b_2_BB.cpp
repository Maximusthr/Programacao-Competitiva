#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    ll n; cin >> n;

    ll l1 = 0, r = INF;
    while(l1 < r){
        ll mid = l1 + (r - l1 + 1)/2;

        if (mid * mid * 2 <= n) l1 = mid;
        else r = mid-1;
    }

    ll l2 = 0;
    r = INF;
    while(l2 < r){
        ll mid = l2 + (r - l2 + 1)/2;

        if (mid * mid * 4 <= n) l2 = mid;
        else r = mid-1;
    }


    cout << l1 + l2 << "\n";
}