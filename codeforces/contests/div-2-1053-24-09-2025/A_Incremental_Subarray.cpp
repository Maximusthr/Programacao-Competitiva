#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n, m; cin >> n >> m;

    vector<int> arr(m);
    for (auto &i : arr) cin >> i;

    bool achou = false;
    int maior = arr[0];
    for (int i = 0; i < m; i++){
        if (!achou && arr[i]) {
            achou = true;
            continue;
        }
        if (achou && arr[i] == 1) {
            cout << 1 << "\n";
            return;
        }
        maior = max(maior, arr[i]);
    }

    cout << n - maior + 1 << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}