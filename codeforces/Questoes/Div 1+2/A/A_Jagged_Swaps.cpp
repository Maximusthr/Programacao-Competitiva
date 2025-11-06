#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n; cin >> n;
    vector<int> arr(n);
    for (auto &i : arr) cin >> i;

    if (arr[0] != 1){
        cout << "NO" << "\n";
        return;
    }

    int times = 30;
    for (int k = 0; k < times; k++){
        for (int i = 1; i < n-1; i++){
            int j = i;
            while(j < n-1 && arr[j] > arr[j-1] && arr[j] > arr[j+1]){
                swap(arr[j], arr[j+1]);
                j++;
            }
        }
    }

    if (is_sorted(arr.begin(), arr.end())){
        cout << "YES" << "\n";
    }
    else cout << "NO" << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}