#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n; cin >> n;

    priority_queue<int> pq;

    ll ans = 0;
    for (int i = 0; i < n; i++){
        int x; cin >> x;
        if (!x){
            if (!pq.empty()){
                ans += pq.top();
                pq.pop();
            }
        }
        else pq.push(x);
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