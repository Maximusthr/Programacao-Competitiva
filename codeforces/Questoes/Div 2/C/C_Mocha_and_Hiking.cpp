#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n; cin >> n;

    vector<int> arr(n+1);
    int idx = 0;
    for (int i = 1; i <= n; i++){
        cin >> arr[i];
        if (arr[i] == 1) idx = i;
    }

    if (arr[1] == 1){
        cout << n+1 << " ";
        for (int i = 1; i <= n; i++){
            cout << i << " \n"[i == n];
        }
        return;
    }
    if (arr.back() == 0){
        for (int i = 1; i <= n; i++){
            cout << i << " ";
        }
        cout << n+1 << "\n";
        return;
    }
    bool flag = 0;
    for (int i = 1; i < n; i++){
        if (!flag && arr[i] == 0 && arr[i+1] == 1){
            cout << i << " " << n+1 << " ";
            flag = 1;
            continue;
        }
        cout << i << " ";
    }
    cout << n << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}