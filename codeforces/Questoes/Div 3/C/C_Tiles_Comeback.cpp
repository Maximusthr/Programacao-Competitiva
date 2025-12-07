#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n, k; cin >> n >> k;

    vector<int> arr(n);
    map<int, int> freq;
    for (auto &i : arr){
        cin >> i;
        freq[i]++;
    }

    if (freq[arr[0]] < k || freq[arr.back()] < k){
        cout << "NO" << "\n";
        return;
    }

    if (arr[0] == arr.back() && freq[arr[0]] >= k){
        cout << "YES" << "\n";
        return;
    }

    int count_1 = 0;
    for (int i = 0; i < n; i++){
        if (count_1 < k){
            if (arr[i] == arr[0]) count_1++;
        }
        else {
            if (freq[arr.back()] >= k) cout << "YES" << "\n";
            else cout << "NO" << "\n";
            return;
        }
        freq[arr[i]]--;
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}