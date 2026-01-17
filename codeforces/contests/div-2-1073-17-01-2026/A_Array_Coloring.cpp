#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n; cin >> n;

    vector<pair<int, int>> arr(n);
    int tipo = 0;
    for (int i = 0; i < n; i++){
        cin >> arr[i].first;
        arr[i].second = tipo;
        tipo ^= 1;
    }

    sort(arr.begin(), arr.end());

    for (int i = 0; i < n-1; i++){
        if (arr[i].second == arr[i+1].second){
            cout << "NO" << "\n";
            return;
        }
    }

    cout << "YES" << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}