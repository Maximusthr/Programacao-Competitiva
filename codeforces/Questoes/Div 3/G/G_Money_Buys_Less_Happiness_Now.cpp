#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n, x; cin >> n >> x;

    int sum = 0;
    priority_queue<int> pq;
    for (int i = 0; i < n; i++){
        int c; cin >> c;

        pq.push(c);
        sum -= c;

        if (sum < 0){
            sum += pq.top();
            pq.pop();
        }

        sum += x;
    }

    cout << pq.size() << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}