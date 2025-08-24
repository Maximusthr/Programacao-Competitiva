#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n; cin >> n;

    vector<int> arr(101);
    for (int i = 0; i < n; i++){
        int x; cin >> x;
        arr[x]++;
    }

    for (int i = 0; i < 101; i++){
        if (arr[i] > 1){
            cout << "YES" << "\n";
            return;
        }
    }

    cout << "NO" << "\n";
    return;

}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}