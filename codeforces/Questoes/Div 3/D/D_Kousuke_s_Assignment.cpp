#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    set<ll> elem;

    int n; cin >> n;
    ll sum = 0;
    int ans = 0;
    for (int i = 0; i < n; i++){
        int a; cin >> a;
        elem.insert(sum);
        sum += a;

        if (elem.find(sum) != elem.end()){
            ans++;
            elem.clear();
            sum = 0;
        }
    }
    cout << ans << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}