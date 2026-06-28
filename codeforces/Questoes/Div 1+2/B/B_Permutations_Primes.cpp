#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n; cin >> n;

    if (n == 1){
        cout << 1 << "\n";
        return;
    }
    if (n == 2){
        cout << 1 << " " << 2 << "\n";
        return;
    }
    
    vector<int> arr(n);
    arr[0] = 2;
    arr.back() = 3;
    arr[n/2] = 1;

    int i = 4;
    for (int j = 0; j < n; j++){
        if (arr[j] == 0){
            cout << i++ << " ";
        }
        else cout << arr[j] << " ";
    }
    cout << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}