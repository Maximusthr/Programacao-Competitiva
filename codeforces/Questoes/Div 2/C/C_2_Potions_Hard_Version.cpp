#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n; cin >> n;

    vector<ll> arr(n);
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }

    priority_queue<ll, vector<ll>, greater<ll>> pq;
    ll sum = 0;
    for (int i = 0; i < n; i++){
        sum += arr[i];
        pq.push(arr[i]);

        if (sum < 0){
            int x = pq.top();
            pq.pop();

            sum -= x;
        }
    }

    cout << pq.size() << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    solve();
}