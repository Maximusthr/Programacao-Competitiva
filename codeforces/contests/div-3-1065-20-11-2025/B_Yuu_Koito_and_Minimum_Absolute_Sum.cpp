#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n; cin >> n;

    bool dif = 0;
    vector<int> arr(n);
    for (int i = 0; i < n; i++){
        cin >> arr[i];
        if (i > 0 && arr[i] != arr[i-1]) dif = 1;
    }

    if (!dif){
        cout << 0 << "\n";
        for (int i = 0; i < n; i++){
            if (arr[i] == -1) cout << 0 << " \n"[i==n-1];
            else cout << arr[i] << " \n"[i==n-1];
        }
        return;
    }

    if (arr[0] == -1 && arr[n-1] == -1){
        arr[0] = 0, arr[n-1] = 0;
    }
    if (arr[0] == -1 || arr[n-1] == -1){
        arr[0] = max(arr[0], arr[n-1]);
        arr[n-1] = max(arr[0], arr[n-1]);
    }

    cout << abs(arr[0] - arr[n-1]) << "\n";
    for (int i = 0; i < n; i++){
        if (arr[i] == -1) arr[i] = 0;
        cout << arr[i] << " \n" [i == n-1];
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}