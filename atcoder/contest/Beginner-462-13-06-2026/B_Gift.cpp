#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n; cin >> n;

    vector<vector<int>> arr(n+1);

    for (int i = 1; i <= n; i++){
        int x; cin >> x;
        for (int j = 0; j < x; j++){
            int y; cin >> y;
            arr[y].push_back(i);
        }
    }

    for (int i = 1; i <= n; i++){
        cout << arr[i].size() << " ";
        for (int j = 0; j < arr[i].size(); j++){
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    solve();
}