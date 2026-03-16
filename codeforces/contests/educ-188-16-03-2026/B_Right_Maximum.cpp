#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n; cin >> n;

    vector<int> arr(n);
    priority_queue<int> pq;
    for (int i = 0; i < n; i++){
        cin >> arr[i];
        pq.push(arr[i]);
    }
    
    int ans = 0;
    map<int, int> cont;
    for (int i = n-1; i >= 0; i--){
        while (i >= 0 && arr[i] != pq.top()){
            cont[arr[i]]++;
            i--;
        }
        int x = pq.top();
        pq.pop();
        ans++;
        while (!pq.empty() && cont[pq.top()] > 0) {
            cont[pq.top()]--;
            pq.pop();
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