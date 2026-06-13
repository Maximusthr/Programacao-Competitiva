#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n, k; cin >> n >> k;

    vector<int> arr(n);
    map<int, int> freq;
    for (auto &i : arr) {
        cin >> i;
        freq[i]++;
    }

    sort(arr.begin(), arr.end());

    for (int i = 1; i < n; i++){
        if (k >= abs(arr[i] - arr[i-1]) && arr[i] != arr[i-1]){
            cout << "YES" << "\n";
            return;
        }
        else {
            if (freq[arr[i]] % 2 == 0){
                cout << "YES" << "\n";
                return;
            }
        }
    }

    cout << "NO" << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}