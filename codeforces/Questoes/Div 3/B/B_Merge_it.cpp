#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n; cin >> n;

    vector<int> v(3);

    for (int i = 0; i < n; i++){
        int x; cin >> x;

        v[x % 3]++;
    }

    int ans = v[0];
    
    int r = min(v[1], v[2]);
    ans += r;

    v[1] -= r;
    v[2] -= r;

    cout << ans + (v[1] + v[2])/3 << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}
