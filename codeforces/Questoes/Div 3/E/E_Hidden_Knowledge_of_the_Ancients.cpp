#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

ll func(vector<int> &arr, int k, int r){
    if (k == 0) return 0;
    if (r == 0) return 0;

    map<int, int> freq;
    
    int n = arr.size();
    int i = 0, j = 0;
    ll ans = 0;
    
    freq[arr[0]]++;
    int wind = 1;
    int dist = 1;
    while(j < n){
        while (j < n && dist <= k && wind <= r){
            ans += j-i+1;
            j++;
            if (j == n) break;
            freq[arr[j]]++;
            if (freq[arr[j]] == 1) dist++;
            wind++;
        }
        while (i < j && j < n && (dist > k || wind > r)){
            freq[arr[i]]--;
            if (freq[arr[i]] == 0) {
                dist--;
                freq.erase(arr[i]);
            }
            i++;
            wind--;
        }
    }
    return ans;
}

void solve(){
    int n, k, l, r; cin >> n >> k >> l >> r;

    vector<int> arr(n);
    for (auto &i : arr) cin >> i;

    cout << (func(arr, k, r) - func(arr, k, l-1)) - (func(arr, k-1, r) - func(arr, k-1, l-1)) << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}