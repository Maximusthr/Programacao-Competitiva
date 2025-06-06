#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    int n; cin >> n;

    vector<ll> arr(n);
    arr[0]++;
    ll v = 0;
    for (int i = 1; i <= n; i++){
        ll a; cin >> a;

        v += a;
        arr[((v % n) + n) % n]++;
    }

    ll ans = 0;
    for (auto x : arr){
        ans += ((x-1)*(x))/2;
    }

    cout << ans << "\n";
}
