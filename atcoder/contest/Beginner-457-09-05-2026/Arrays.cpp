#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n; cin >> n;

    vector<vector<int>> arr(n);
    for (int i = 0; i < n; i++){
        int x; cin >> x;
        for (int j = 0; j < x; j++){
            int y; cin >> y;
            arr[i].push_back(y);
        }
    }

    int x, y; cin >> x >> y;

    cout << arr[x-1][y-1] << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    solve();
}