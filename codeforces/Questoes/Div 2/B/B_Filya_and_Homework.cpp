#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;


void solve(){
    int n; cin >> n;

    vector<int> arr(n);
    for (auto &i : arr) cin >> i;

    sort(arr.begin(), arr.end());
    
    int dif = 1;
    for (int i = 1; i < n; i++){
        if (arr[i] != arr[i-1]){
            dif++;
        }
    }

    if (dif >= 4) {
        cout << "NO" << "\n";
        return;
    }
    if (dif <= 2){
        cout << "YES" << "\n";
        return;
    }

    // 3 distintos
    array<int, 3> v = {-1, -1, -1};
    for (int i = 1; i < n; i++){
        if (arr[i] != arr[i-1]){
            if (v[0] == -1) {
                v[0] = arr[i-1];
                v[1] = arr[i];
            }
            else {
                v[2] = arr[i];
                break;
            }
        }
    }

    if (v[1] * 2 == (v[0] + v[2])){
        cout << "YES" << "\n";
        return;
    }
    
    cout << "NO" << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    // int t; cin >> t;
    // while(t--){
    solve();
    // }
}