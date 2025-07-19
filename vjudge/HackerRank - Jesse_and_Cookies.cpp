#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    int n, k; cin >> n >> k;

    priority_queue<ll, vector<ll>, greater<ll>> q;

    for (int i = 0; i < n; i++){
        ll x; cin >> x;
        q.push(x);
    }

    int ans = 0;
    while(true){
        if (q.top() >= k){
            cout << ans << "\n";
            return 0;
        }

        if (q.size() == 1){
            cout << -1 << "\n";
            return 0;
        }

        ll a = q.top();
        q.pop();
        ll b = q.top();
        q.pop();
        q.push(a + (2*b));

        ans++;
    }
}