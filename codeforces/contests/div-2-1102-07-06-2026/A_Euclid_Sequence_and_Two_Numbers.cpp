#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n; cin >> n;

    vector<int> arr(n);
    for (auto &i : arr) cin >> i;

    sort(arr.begin(), arr.end(), greater<int>());
    
    if (n == 2){
        cout << arr[0] << " " << arr[1] << "\n";
        return;
    }

    vector<int> copy;
    copy.push_back(arr[0]);
    copy.push_back(arr[1]);

    for (int i = 2; i < n; i++){
        copy.push_back(arr[i-2] % arr[i-1]);
        if (copy[i] != arr[i]){
            cout << "-1" << "\n";
            return;
        }
    }

    cout << arr[0] << " " << arr[1] << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}