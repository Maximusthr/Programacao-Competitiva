#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n, k; cin >> n >> k;
    
    map<int, int> freq;
    vector<int> arr(n);
    int sum = 0;
    int extra = 0;
    for (int i = 0; i < n; i++){
        cin >> arr[i];
        if (arr[i] % k) freq[arr[i]%k]++;
        else extra++;

        arr[i] %= k;
    }
    if (extra) sum++;

    for (auto &[x, y] : freq){
        if (y <= 0) continue;
        int menor = min(y, freq[k - x]);
        y -= menor;
        freq[k - x] -= menor;

        if (y > freq[k-x]) y--;
        else freq[k-x]--;
        
        sum++;
    }

    for (auto [x, y] : freq){
        if (y <= 0) continue;
        sum += y;
    }

    cout << sum << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}